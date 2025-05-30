import socket
client = socket.socket()
client.connect(('127.0.0.1', 12345))
with open("small.txt", "rb") as f:
    data = f.read()
    client.send(data)
print("File sent.")
client.close()