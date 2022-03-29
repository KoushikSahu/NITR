import os
import sys
import argparse
import socket


"""
    Author: Koushik Sahu
    Created: 2022-03-29 13:34 IST
"""


class TCPServer():
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.connection_count = 0

    def start(self):
        print(f'Running TCP server on {self.host}:{self.port}')
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind((self.host, self.port))
            s.listen()

            while True:
                try:
                    conn, addr = s.accept()
                    self.connection_count += 1
                    with conn:
                        print(f'Connected by {addr}')
                        response_text = TCPServer.http_response(f'client {addr} connected to server {self.connection_count} times')
                        conn.sendall(response_text)
                except KeyboardInterrupt:
                    print('Interrupted')
                    try:
                        sys.exit(0)
                    except SystemExit:
                        os._exit(0)

    @staticmethod
    def http_response(text):
        response_text = f'HTTP/1.0 200 OK\n\n{text}'
        return response_text.encode()


def main():
    parser = argparse.ArgumentParser(description="start a tcp server that returns http response")
    parser.add_argument('--host', type=str, help='host to start server on', default='127.0.0.1')
    parser.add_argument('--port', type=int, help='port to start server on', default=8080)
    args = parser.parse_args()

    ts = TCPServer(args.host, args.port)
    ts.start()


if __name__ == '__main__':
    main()

