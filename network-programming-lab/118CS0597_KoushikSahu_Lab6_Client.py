import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 1234))

blocking = 1

inp = input("enter type of socket [blocking/non-blocking]: ").lower()

if inp == "blocking":
    blocking = True
else:
    blocking = False
s.setblocking(blocking)

data = b"Hello World\n" *10*1024*1024
assert s.send(data)

