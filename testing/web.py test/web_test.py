import web
import os
        
urls = (
    '/images/(.*)', 'images', #this is where the image folder is located....
    '/(.*)',        'hello'
)
app = web.application(urls, globals())

class hello:        
    def GET(self, name):
        if not name: 
            name = 'World'
        return 'Hello, ' + name + '!'


class images:
    def GET(self,name):
        print(name)
        ext = name.split(".")[-1] # Gather extension

        cType = {
            "png":"images/png",
            "jpg":"images/jpeg",
            "gif":"images/gif",
            "ico":"images/x-icon"            }

        if name in os.listdir('images'):  # Security
            web.header("Content-Type", cType[ext]) # Set the Header
            return open('images/%s'%name,"rb").read() # Notice 'rb' for reading images
        else:
            raise web.notfound()

if __name__ == "__main__":
    app.run()
