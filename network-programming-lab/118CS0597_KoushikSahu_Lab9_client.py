import socket
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
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        msg = ""
        while msg != "stop":
            msg = input("> ")
            s.sendto(msg.encode(), (host, port))
            msg, _ = s.recvfrom(1024)
            msg = msg.decode()
            print(f"server: {msg}")
        s.close()
    except socket.error as err:
        s.close()
        print(err)


run(host, port)
