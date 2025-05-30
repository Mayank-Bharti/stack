import socket
import ssl

# Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1', 8443))
server_socket.listen(5)
print("Secure Server Listening on port 8443...")

# Setup SSL context
context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
context.load_cert_chain(certfile="server.crt", keyfile="server.key")

while True:
    client_socket, addr = server_socket.accept()
    print(f"Connection from {addr}")
    with context.wrap_socket(client_socket, server_side=True) as secure_conn:
        data = secure_conn.recv(1024)
        print("Secure Data Received:", data.decode())
        secure_conn.sendall(b"Secure Hello from Server!")
