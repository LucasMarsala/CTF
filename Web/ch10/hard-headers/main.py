#!/usr/bin/python3.8


import base64
import requests

r = requests.Session()
reponse = r.post("http://54.38.232.200:30085/index.php")

get = reponse.headers['Get-flag']
print(get)
get_byte = bytes(get, 'utf-8')
header_byte = base64.b64decode(get_byte)
header = header_byte.decode('ascii')
print(header)
reponse = r.post("http://54.38.232.200:30085/index.php", data={'MasterInput' : header})
print(reponse.content)
