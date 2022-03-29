from datetime import datetime
import socket
import time 

SEND_BUF_SIZE = 1024
RECV_BUF_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('localhost', 1234))
s.listen(1)

# change socket send buffer size
old_send_bufsize = s.getsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF)
s.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, SEND_BUF_SIZE)
new_send_bufsize = s.getsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF)
print(f"Old send buffer size = {old_send_bufsize}")
print(f"New send buffer size = {new_send_bufsize}\n")

# change socket receive buffer size
old_recv_bufsize = s.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
s.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, SEND_BUF_SIZE)
new_recv_bufsize = s.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
print(f"Old recv buffer size = {old_recv_bufsize}")
print(f"New recv buffer size = {new_recv_bufsize}\n")

while True:
    conn, addr = s.accept()
    msg = conn.recv(RECV_BUF_SIZE).decode()
    
    time.sleep(10)
    while msg:
        msg = conn.recv(RECV_BUF_SIZE).decode()
    print('All data received', datetime.now())

    conn.close()
    break

