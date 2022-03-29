import socket


def run():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('old state: ', s.getsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR))
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    print('new state: ', s.getsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR))

    s.bind(('localhost', 8282))
    s.listen(1)

    while True:
        try:
            conn, addr = s.accept()
            print('Connected by ', addr)
        except KeyboardInterrupt:
            conn.close()
            s.close()
            break


run()

