import socket
import os
from tqdm import tqdm

filename = "large_file.zip"
size = os.path.getsize(filename)
client = socket.socket()
client.connect(('127.0.0.1', 12345))
client.send(f"{filename}|{size}".encode())
progress = tqdm(total=size, unit="B", unit_scale=True)
with open(filename, "rb") as f:
    while True:
        data = f.read(4096)
        if not data:
            break
        client.sendall(data)
        progress.update(len(data))
print("Large file sent.")
client.close()