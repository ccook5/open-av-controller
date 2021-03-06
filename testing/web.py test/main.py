import web

import subprocess
        
urls = (
    '/', 'root',
    '/api/enable/(\d+)',        'enable',
    '/api/disable/(\d+)',       'disable',
    '/api/input/(\d+)',         'input',
    '/api/status/(\d+)',        'status'
)
app = web.application(urls, globals())

class root:        
    def GET(self):
        web.redirect('static/')

class enable:
    def GET(self, id):
        id = int(id)
        print 'enable', id
        raise web.seeother('/')
        
class disable:
    def GET(self, id):
        id = int(id)
        print 'disable', id
        raise web.seeother('/')
        
class input:
    def GET(self, id):
        id = int(id)
        print 'enable', id
        raise web.seeother('/')
        
class status:
    def GET(self, id):
        id = int(id)
        
        if id == 1:
            data = subprocess.check_output(["python", "../pjlink/cli.py", "-p", "mainhallcentre", "errors"])    
            data += subprocess.check_output(["python", "../pjlink/cli.py", "-p", "mainhallcentre", "lamps"])    
            return data
        else:
            return 'ok'
        raise web.seeother('/')

if __name__ == "__main__":
    app.run()
