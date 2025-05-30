import socket
server = socket.socket()
server.bind(('0.0.0.0', 12345))
server.listen(1)
print("Server listening...")
client, addr = server.accept()
print("Connected by", addr)
meta = client.recv(1024).decode()
filename, size = meta.split("|")
size = int(size)
with open("received_" + filename, "wb") as f:
    received = 0
    while received < size:
        data = client.recv(4096)
        if not data:
            break
        f.write(data)
        received += len(data)
print("Large file received.")
client.close()
server.close()