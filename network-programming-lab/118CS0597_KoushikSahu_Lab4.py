import socket 
import argparse

def find_service_name(port: int, protocol: str) -> str: 
    return socket.getservbyport(port, protocol)
     

def main() -> None:
    parser: argparse.ArgumentParser = argparse.ArgumentParser(
            description='Get name of service from port number and protocol name'
        )

    parser.add_argument('--port',  type=int, dest="port", required=False, help="specify port")
    parser.add_argument('--protocol',  type=str, dest="protocol", required=False, help="specify port (tcp/upd)")

    args: argparse.Namespace = parser.parse_args()
    port: int = args.port or 80
    protocolname: str = args.protocol or 'tcp'

    print(f'Service name: {find_service_name(port, protocolname)}')


if __name__ == '__main__':
    main()

