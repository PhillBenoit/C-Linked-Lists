#! /usr/bin/python3

import requests
from passwords import *

username = user()
password = pw()

print(requests.get('http://192.168.1.80:3000/basic-auth/user/password', auth=(username, password), timeout=1).text)
