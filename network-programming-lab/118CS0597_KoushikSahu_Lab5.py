import ntplib
import time
import socket
import struct

"""
	Author: Koushik Sahu
	Created: 08 February 2022 Tue 13:40:49
"""


def RequestTimefromNtp(addr='0.in.pool.ntp.org'):
	nc = ntplib.NTPClient()
	response = nc.request(addr, version=3)
	return time.ctime(response.tx_time), response.tx_time


def sntp_client(addr='0.in.pool.ntp.org'):
	REF_TIME_1970 = 2208988800  
	client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	data = b'\x1b' + 47 * b'\0'
	client.sendto(data, (addr, 123))
	data, _ = client.recvfrom(1024)
	if data:
		t = struct.unpack('!12I', data)[10]
		t -= REF_TIME_1970
	return time.ctime(t), t


if __name__ == '__main__':
	print('Fetching time from NTP server using ntplib: ')
	print(RequestTimefromNtp())
	print('Using SNTP client: ')
	print(sntp_client())
	