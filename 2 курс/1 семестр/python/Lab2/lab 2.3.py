import os
path = os.path.dirname(__file__)
for address, dirs, files in os.walk(path):
   for file in files:
       if file.endswith(".py"):
            print(address + "/" + file)