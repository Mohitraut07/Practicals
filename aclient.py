import socket
import threading

def receive_messages(client_socket):
    while True:
        try:
            data = client_socket.recv(1024).decode("ascii")
            if not data:
                break
            print('Msg from Server:', data)
        except socket.error as e:
            print("Error receiving data:", e)
            break

def send_messages(client_socket):
    while True:
        try:
            msg = input('Send your msg:\n')
            client_socket.send(msg.encode())
            if msg.lower().strip() == "bye":
                break
        except socket.error as e:
            print("Error sending data:", e)
            break

def main():
    # print("hi")
    client_socket = socket.socket()

    server_ip = '192.168.137.174'  # Change this to the IP address of your server
    port = 8080

    try:
        client_socket.connect((server_ip, port))
        print('Connected to server')

        receive_thread = threading.Thread(target=receive_messages, args=(client_socket,))
        send_thread = threading.Thread(target=send_messages, args=(client_socket,))

        receive_thread.start()
        send_thread.start()

        receive_thread.join()
        send_thread.join()

    except socket.error as e:
        print("Error connecting to server:", e)

    client_socket.close()

if __name__ == "__main__":
    main()

