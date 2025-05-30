import socket
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('0.0.0.0', 12345))
print("UDP Server ready.")
data, addr = server.recvfrom(1024)
with open("udp_received.txt", "wb") as f:
    f.write(data)
print("UDP file received.")
server.close()