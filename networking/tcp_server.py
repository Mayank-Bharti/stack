import socket

server = socket.socket()
server.bind(('192.168.84.117', 12345))
server.listen(1)

print("Server listening on 192.168.84.117:12345...")

client, addr = server.accept()
print("Connected by", addr)

data = client.recv(1024)
with open("received_small.txt", "wb") as f:
    f.write(data)

print("File received.")
client.close()
server.close()
