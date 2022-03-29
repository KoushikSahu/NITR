import argparse
import socket
import sys

parser = argparse.ArgumentParser(description='Socket chat app')
parser.add_argument('--host', type=str, required=True,
                    help="specify host")
parser.add_argument('--port', type=int, required=True,
                    help="specify port number")

args = parser.parse_args()

host = args.host
port = args.port


def run(host, port):
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((host, port))
        s.listen(3)
        while True:
            conn, addr = s.accept()
            print(f"Connected by {addr}")
            msg = f"Connected to server {host}:{port}"
            conn.send(msg.encode())

            while True:
                msg = conn.recv(4096).decode("utf-8")
                if(msg == "stop"):
                    break
                print(f"{addr}: {msg}")
            conn.close()
            print("Client disconnected")
    except socket.error as err:
        conn.close()
        s.close()
        print(err)
    except KeyboardInterrupt:
        sys.exit()


run(host, port)
