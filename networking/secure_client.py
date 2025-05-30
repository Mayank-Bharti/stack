import socket
import ssl

# Create a TCP connection
client_socket = socket.create_connection(('127.0.0.1', 8443))

# Setup SSL context
context = ssl.create_default_context()
context.check_hostname = False
context.verify_mode = ssl.CERT_NONE  # Not for production use

with context.wrap_socket(client_socket, server_hostname='localhost') as secure_conn:
    secure_conn.sendall(b"Hello Secure Server!")
    data = secure_conn.recv(1024)
    print("Secure Data from Server:", data.decode())
