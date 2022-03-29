from http import client
import socket
import sys
import argparse

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
        s.connect((host, port))
        msg = s.recv(4096).decode("utf-8")

        msg = ""
        while msg != "stop":
            msg = input("> ")
            s.send(msg.encode())
        print(f"server: {msg}")
        s.close()
    except socket.error as err:
        s.close()
        print(err)


run(host, port)
