import web

import subprocess
        
urls = (
    '/', 'hello',
    '/api/enable/(\d+)',        'enable',
    '/api/disable/(\d+)',       'disable',
    '/api/enable_toggle/(\d+)', 'enable_toggle',
    '/api/input/(\d+)',         'input',
    '/api/status/(\d+)',        'status'
)
app = web.application(urls, globals())

class hello:        
    def GET(self):
        web.redirect('static/')

class enable:
    def GET(self, id):
        id = int(id)
        print 'enable', id
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
            data = subprocess.check_output(["python", "pjlink/cli.py", "-p", "mainhallcentre", "errors"])    
            data += subprocess.check_output(["python", "pjlink/cli.py", "-p", "mainhallcentre", "lamps"])    
            return data
        else:
            return 'ok'
        raise web.seeother('/')

if __name__ == "__main__":
    app.run()
