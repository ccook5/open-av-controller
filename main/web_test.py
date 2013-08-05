import web
import os
        
urls = (
    '/(.*)',            'index',
    '/static/js/(.*)',     'javascripts', #this is where the static javascripts folder is located....
    '/static/images/(.*)', 'images',      #this is where the static images folder is located....
    '/static/css/(.*)',    'css'          #this is where the static css folder is located....
)
app = web.application(urls, globals())

class index:
    def GET(self, name):
        html = """
        <!doctype html>
 
<html lang="en">
 <head>
  <meta charset="utf-8" />
  
  <title>AV Controller</title>
  
  <link rel="stylesheet" href="http://code.jquery.com/ui/1.10.3/themes/smoothness/jquery-ui.css" />
  
  <script src="http://code.jquery.com/jquery-1.9.1.js"></script>
  <script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>


  <script type="text/javascript" src="./static/js/engage.itoggle/easing.js"></script>
  <script type="text/javascript" src="./static/js/engage.itoggle/engage.itoggle.1.7.js"></script>
  <link href="./static/js/engage.itoggle/engage.itoggle.css" rel="stylesheet" type="text/css" />

  <script type="text/javascript" src="./static/js/main.js"></script>
  <link href="./static/css/main.css" rel="stylesheet" type="text/css" />

 </head>
 <body>
  <h1>AV Controller</h1>
  
  <div id="itoggle" class="project">
  <table>
    <colgroup></colgroup><colgroup></colgroup><colgroup></colgroup><colgroup></colgroup>
    <colgroup></colgroup><colgroup></colgroup><colgroup></colgroup><colgroup></colgroup>
    <colgroup></colgroup>
   <thead>
    <td>Output:</td><td>Main Screen</td><td>Right Side Screen</td><td>Left Side Screen</td>
    <td>Rear Screen</td><td>Stage Plasma</td><td>Outside Hall</td>
    <td>Reception</td><td>Preview</td>
   </thead>
   <tr>
    <td>Enable:</td>
    <td><input type="checkbox" id="check1" /><label for="check1">OFF</label></td>
    <td><input type="checkbox" id="check2" /><label for="check2">OFF</label></td>
    <td><input type="checkbox" id="check3" /><label for="check3">OFF</label></td>
    <td><input type="checkbox" id="check4" /><label for="check4">OFF</label></td>
    <td><input type="checkbox" id="check5" /><label for="check5">OFF</label></td>
    <td><input type="checkbox" id="check6" /><label for="check6">OFF</label></td>
    <td><input type="checkbox" id="check7" /><label for="check7">OFF</label></td>
    <td><input type="checkbox" id="check8" /><label for="check8">OFF</label></td>
   </tr>
   <tr>
    <td>Input:</td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
    <td>
     <select class="select_input">     </select>
    </td>
   </tr>
   <tr>
    <td>Status:</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
    <td>Waiting...</td>
   </tr>
  </table>
  </div>
  <submit />
 </body>
</html>
        """
        return html

class images:
    def GET(self,name):
        print(name)
        ext = name.split(".")[-1] # Gather extension

        cType = {
            "png":"images/png",
            "jpg":"images/jpeg",
            "gif":"images/gif",
            "ico":"images/x-icon"            }

        if name in os.listdir('static/images'):  # Security
            web.header("Content-Type", cType[ext]) # Set the Header
            return open('static/images/%s'%name,"rb").read() # Notice 'rb' for reading images
        else:
            raise web.notfound()

class css:
    def GET(self,name):
        print(name)
        ext = name.split(".")[-1] # Gather extension

        cType = {
            "css":"text/css"
        }

        if name in os.listdir('static/css'):  # Security
            web.header("Content-Type", cType[ext]) # Set the Header
            return open('static/css/%s'%name,"rb").read() # Notice 'rb' for reading images
        else:
            raise web.notfound()

class javascripts:
    def GET(self,name):
        return 'javascripts'
        print(name)
        ext = name.split(".")[-1] # Gather extension

        cType = {
            "js":"application/javacript"
        }

        if name in os.listdir('static/js'):  # Security
            web.header("Content-Type", cType[ext]) # Set the Header
            return open('static/js/%s'%name,"rb").read() # Notice 'rb' for reading images
        else:
            raise web.notfound()

if __name__ == "__main__":
    app.run()
