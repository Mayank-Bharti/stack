import socket
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
with open("small.txt", "rb") as f:
    data = f.read()
    client.sendto(data, ('127.0.0.1', 12345))
print("UDP file sent.")
client.close()