import socket
from binascii import hexlify, unhexlify


"""
    Author: Koushik Sahu
    Created: 2022-01-18 13:34 IST
"""


def get_remoteip(url):
    ipv4_addr = ''
    try:
        ipv4_addr = socket.gethostbyname(url)
        print(f'IP address of {url}: {ipv4_addr}')
    except:
        print(f'Unable to find the IP address for {url}')

    ipv6_addr = to_ipv6(ipv4_addr)
    print(f'Converting to IPv6: {ipv6_addr}')
    ipv4_addr_conv = to_ipv4(ipv6_addr)
    print(f'Converting back to IPv4: {ipv4_addr_conv}')


def to_ipv6(ipv4_addr):
    packed_ip_addr = socket.inet_aton(ipv4_addr)
    ipv6_addr = hexlify(packed_ip_addr).decode('utf-8')
    ipv6_addr = '2002:' + ipv6_addr[:4] + ':' + ipv6_addr[-4:] + '::'
    return ipv6_addr


def to_ipv4(ipv6_addr):
    prts = ipv6_addr.split(':')
    hx = bytes(prts[1]+prts[2], 'utf-8')
    addr = unhexlify(hx)
    ipv4_addr = socket.inet_ntoa(addr)
    return ipv4_addr


if __name__ == '__main__':
    get_remoteip('nitrkl.ac.in')
    
