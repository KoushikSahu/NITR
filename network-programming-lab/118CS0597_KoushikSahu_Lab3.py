import socket
import sys
import argparse


if __name__ == '__main__':
    parser: argparse.ArgumentParser = argparse.ArgumentParser(description='Socket error ex.')
    parser.add_argument('--host', type=str, dest="host",
                        required=False, help="specify hostname")
    parser.add_argument('--port', type=int, dest="port",
                        required=False, help="specify port number")
    parser.add_argument('--file', type=str, dest="filename",
                        required=False, help="specify filename")

    args = parser.parse_args()
    host: str = args.host or "127.0.0.1"
    port: int = args.port or 8080
    filename: str = args.filename or "test_file.txt"
    msg: str = "Hello"

    print(f'Host: {host}')
    print(f'Port: {port}')
    print(f'Filename: {filename}')

    try:
        s: socket.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except socket.error as err:
        print("Failed to create socket: ", err)
        sys.exit()

    try:
        print(f'Socket default timeout before: {socket.getdefaulttimeout()}')
        socket.setdefaulttimeout(5.0)
        s.settimeout(5.0)
        print(f'Socket default timeout after: {socket.getdefaulttimeout()}')
    except socket.error as err:
        print("Failed to set socket timeout: ", err)
        sys.exit()

    try:
        s.connect((host, port))
    except socket.error as err:
        print("Failed to connect to host: ", err)
        sys.exit()

    try:
        s.sendall(msg.encode('utf-8'))
    except socket.error as err:
        print("Failed to send message: ", err)
        sys.exit()

