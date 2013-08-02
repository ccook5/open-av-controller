
import socket
import time

UDP_IP = "172.16.112.210"
UDP_PORT = 5000


class kramer_matrix_p2000:

    def __init__(self, dest_ip_address, dest_udp_port, machine_num):
        self.dest_ip_address = dest_ip_address
        self.dest_ip_port    = dest_udp_port
        self.machine_num = machine_num
            
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
        self.sock.connect((UDP_IP, UDP_PORT))
    
    def ident_switcher(self):
        MESSAGE = b'\x3D\x81\x80\x81'
        self.send_message(MESSAGE)
               
        data_name, addr = self.sock.recvfrom(4) # buffer size is 4 bytes


        time.sleep(2)
        MESSAGE = b'\x3D\x81\x81\x81'
        self.send_message(MESSAGE)
               
        data_suffix, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        matrix_name   = self.decode_matrix_name(data_name)
        matrix_suffix = self.decode_matrix_suffix(data_suffix)

        print(matrix_name + matrix_suffix)
        
        MESSAGE = b'\x3D\x83\x80\x81'
        self.send_message(MESSAGE)
               
        data, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        matrix_ver   = self.decode_matrix_name(data)

        print(matrix_ver)
        time.sleep(10)

    def read_output(self, output_num):
        if self.is_op_num_valid(output_num):
            output_byte = 0x80 + output_num
        
            MESSAGE = self.build_message(b'\x05', output_byte, b'\x80', self.machine_num)
            self.send_message(MESSAGE)

    def set_output(self, output_num, input_num):

        print('set output ' + str(output_num) + '>' + str(input_num))
        
        if not self.is_op_num_valid(output_num):
            print('output not valid')
            return
        
        if not self.is_ip_num_valid(input_num):
            print('input not valid')
            return
        
        MESSAGE = self.build_message(b'\x01', output_num, input_num, self.machine_num)
        self.send_message(MESSAGE)

    def store_memory(self, mem_num):
        if self.is_ip_num_valid(mem_num):
            mem_byte = int(80, 16) + mem_num
        
            MESSAGE = self.build_message(b'\x03', mem_byte, b'\x80', self.machine_num)
            self.send_message(MESSAGE)

    def recall_memory(self, mem_num):
        if self.is_ip_num_valid(mem_num):
            mem_byte = int(80, 16) + mem_num
        
            MESSAGE = self.build_message(b'\x04', mem_byte, b'\x80', self.machine_num)
            self.send_message(MESSAGE)
        
# private functions. Don't call outside this class as it might change.

    def get_ip_as_byte(self, ip):
        inputs = { 0:0x80, 1: 0x81, 2:0x82, 3:0x83, 4:0x84, 5:0x85, 6:0x86, 7:0x87, 8:0x88}
        return inputs[ip]

    def is_ip_num_valid(self, num):
        if (num >= 1 and num <= 8):
            return True
        else:
            return False
        
    def is_op_num_valid(self, num):
        if (num >= 1 and num <= 8):
            return True
        else:
            return False

    def build_message(self, instruction_byte, input_num, output_num, machine_number_byte):
        msg = bytearray()
        msg += instruction_byte
        msg.insert(1, self.get_ip_as_byte(input_num))
        msg.insert(2, self.get_ip_as_byte(output_num))
        
        if (self.machine_num != 'all'):
            b = 0x80 + self.machine_num
            msg.insert(3, int(hex(b), 16))
        else:
            msg.insert(3, ord(0xC1))
        return msg

    def send_message(self, msg):
        self.sock.sendall(msg)

    def decode_matrix_name(self, msg):
        print("received message:")
        print(msg)

        return str(msg[1] - 128) + str(msg[2] - 128)
    
    def decode_matrix_suffix(self, msg):
        print("received message:")
        print(msg)

        return chr(msg[1] - 128) + chr(msg[2] - 128)
    
# END CLASS kramer_matrix
##########################################

def main():
    mtrx = kramer_matrix_p2000(UDP_IP, UDP_PORT, 1)

    mtrx.ident_switcher()

    print('loop')
    for input_num in range(1,9):
        print(input_num)
        for output in range(1,9):
            mtrx.set_output(output, input_num)
        time.sleep(1)

                                    


if __name__=="__main__":
    main()
