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
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.bind((host, port))
        while True:
            data, addr = s.recvfrom(1024)
            print(f"{addr}: {data.decode()}")
            s.sendto(data, addr)
    except socket.error as err:
        s.close()
        print(err)
    except KeyboardInterrupt:
        sys.exit()


run(host, port)
