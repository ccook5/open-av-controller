
import socket
import time

DEST      = "172.16.30.30"
DEST_PORT = 5000


class kramer_matrix_p2000:

    def __init__(self, dest_address, dest_udp_port, machine_num):
        self.dest_address = dest_address
        self.dest_ip_port    = dest_udp_port
        self.machine_num     = machine_num
            
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
        self.sock.connect((self.dest_address, self.dest_ip_port))
    
    def ident_switcher(self):
        matrix_name   = 'UNKNOWN'
        matrix_prefix = ''
        matrix_suffix = ''

# Get matrix Name
        MESSAGE = b'\x3D\x81\x80\x81'
        self.send_message(MESSAGE)
               
        data_name, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        if not self.is_valid_response(data_name):
            print('Name is not a valid response. Check IP address and protocol settings.')
            return False
        
        if not self.decode_error_msg(data_name):
            matrix_name   = self.decode_matrix_name(data_name)


        time.sleep(10)

# Get Matrix Suffix
        MESSAGE = b'\x3D\x81\x81\x81'
        self.send_message(MESSAGE)
               
        data_suffix, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        if not self.is_valid_response(data_suffix):
            print('suffix is not a valid response. Check IP address and protocol settings.')
            return False


        if not self.decode_error_msg(data_suffix):
            matrix_suffix = self.decode_matrix_suffix(data_suffix)


# Get Matrix Prefix
        MESSAGE = b'\x3D\x81\x8b\x81'
        self.send_message(MESSAGE)
               
        data_prefix, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        if not self.is_valid_response(data_prefix):
            print('suffix is not a valid response. Check IP address and protocol settings.')
            return False


        if not self.decode_error_msg(data_prefix):
            matrix_prefix = self.decode_matrix_suffix(data_prefix)

        print('Matrix Name : ' + matrix_prefix + ' ' +matrix_name + '(' + matrix_suffix + ')')

# Get Matrix Version
        MESSAGE = b'\x3D\x83\x80\x81'
        self.send_message(MESSAGE)
               
        data, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        matrix_ver   = self.decode_matrix_version(data)

        print('Matrix Version: ')
        print(matrix_ver)
        time.sleep(10)

    def read_output(self, output_num):
        if not self.is_op_num_valid(output_num):
            print('Invalid output' + output_num)
            return False
        
        MESSAGE = self.build_message(b'\x05', 0, output_num, self.machine_num)
        self.send_message(MESSAGE)

                           
        data, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        if not self.is_valid_response(data):
            print('data is not a valid response. Check IP address and protocol settings.')
            return False

        puts = { 0x80:'0',
                 0x81:'1',
                 0x82:'2',
                 0x83:'3',
                 0x84:'4',
                 0x85:'5',
                 0x86:'6',
                 0x87:'7',
                 0x88:'8' }
        

        print('Output : ' + str(output_num) + ' set to: ' + puts[ ord(data[2]) ] + '.')

    def set_output(self, output_num, input_num):

        print('set output ' + str(output_num) + '>' + str(input_num))
        
        if not self.is_op_num_valid(output_num):
            print('output not valid')
            return
        
        if not self.is_ip_num_valid(input_num):
            print('input not valid')
            return
        
        MESSAGE = self.build_message(b'\x01', input_num, output_num, self.machine_num)
        self.send_message(MESSAGE)
        data, addr = self.sock.recvfrom(4) # buffer size is 4 bytes
        
        if not self.is_valid_response(data):
            print('data is not a valid response. Check IP address and protocol settings.')
            return False

        puts = { 0x80:'0',
                 0x81:'1',
                 0x82:'2',
                 0x83:'3',
                 0x84:'4',
                 0x85:'5',
                 0x86:'6',
                 0x87:'7',
                 0x88:'8' }

        print('Output : ' + puts[ ord(data[2]) ] + ' set to: ' + puts[ ord(data[1]) ] + '.')

    def store_memory(self, mem_num):
        if self.is_ip_num_valid(mem_num):
            mem_byte = int(80, 16) + mem_num
        
            MESSAGE = self.build_message(b'\x03', mem_byte, 0, self.machine_num)
            self.send_message(MESSAGE)

    def recall_memory(self, mem_num):
        if self.is_ip_num_valid(mem_num):
            mem_byte = int(80, 16) + mem_num
        
            MESSAGE = self.build_message(b'\x04', mem_byte, 0, self.machine_num)
            self.send_message(MESSAGE)

    def lock_front_panel(self):
        
        MESSAGE = b'\x1E\x81\x80\x81'
        self.send_message(MESSAGE)
               

    def unlock_front_panel(self):
        
        MESSAGE = b'\x1E\x80\x80\x81'
        self.send_message(MESSAGE)
               

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

    def is_valid_response(self, msg):
        if ord(msg[0]) & 0x40:
            return True
        else:
            return False
        
    def decode_matrix_name(self, msg):
        s = str(ord(msg[1]) - 128) + str(ord(msg[2]) - 128)

        if s[0] == '0':
            s = s[1:]

        return s
    
    def decode_matrix_suffix(self, msg):
        return chr(ord(msg[1]) - 128) + chr(ord(msg[2]) - 128)

    
    def decode_matrix_version(self, msg):
        return str(ord(msg[1]) - 128) + '.' + str(ord(msg[2]) - 128)

    def decode_error_msg(self, msg):

        error_codes = { 0x80: 'Error',
                        0x81: 'Invslid Instruction',
                        0x82: 'Out of Range',
                        0x83: 'Machine Busy',
                        0x84: 'Invalid Input',
                        0x85: 'Valid Input',
                        0x86: 'RX buffer Overflow'}
        
        if ord(msg[0]) == 0x50:
            print ('error: ' + error_codes[ord(msg[2]) ] )

            if ord(msg[2]) == 0x84 or ord(msg[2]) == 0x85:
                print(ord(msg[2]) - 0x80)

            return True
        return False
            
    
# END CLASS kramer_matrix
##########################################

def main():
    mtrx = kramer_matrix_p2000(DEST, DEST_PORT, 1)

    mtrx.ident_switcher()

    print('loop')
    for input_num in range(1,9):
        print(input_num)
        for output in range(1,9):
            mtrx.set_output(output, input_num)
            mtrx.read_output(output)
        time.sleep(1) 


if __name__=="__main__":
    main()
