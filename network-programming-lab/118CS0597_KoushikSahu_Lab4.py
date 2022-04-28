import socket 
import argparse

def find_service_name(port: int, protocol: str) -> str: 
    try:
        service_name = socket.getservbyport(port, protocol)
    except:
        raise Exception(f"Can't find service name. Check if {protocol} connection available on the port.")
    return service_name
     

def main() -> None:
    parser: argparse.ArgumentParser = argparse.ArgumentParser(
            description='Get name of service from port number and protocol name'
        )

    parser.add_argument('--port',  type=int, dest="port", required=False, help="specify port")
    parser.add_argument('--protocol',  type=str, dest="protocol", required=False, help="specify protocol name (tcp/upd)")

    args: argparse.Namespace = parser.parse_args()
    port: int = args.port or 80
    protocolname: str = args.protocol or 'tcp'

    print(f'Service name: {find_service_name(port, protocolname)}')


if __name__ == '__main__':
    main()

