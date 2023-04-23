#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

// argc - number of arguments
// argv - list of actual arguements
int main(int argc, char const* argv[])
{
<<<<<<< HEAD
	int server_fd, socket_pipe; // creating a socket file handler/descriptor and the socket pipe for communication
=======
	int server_fd, socket; // creating a socket file handler/descriptor and the socket pipe for communication
>>>>>>> 5ebac210212d41731ccf063cfae292811494038a
	struct sockaddr_in address; // stores a address and port # 
	int opt = 1; // options for socket: setting to 1 indicates we can reuse address and port (multiple endpoints?)
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 }; // used for communication --> will hold msg from client
	char* hello = "Hello from server"; // actual msg to send

	// Creating socket and "identifying" w/ file descriptior
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
		perror("Error: Could not create socket\n"); 
		exit(EXIT_FAILURE);
	}

	// Setting socket options: reusability of address and port
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
		perror("Error: Could not set options");
		exit(EXIT_FAILURE);
	}

	// Assigning address info
	address.sin_family = AF_INET; // server ip address set as ipv4
	address.sin_addr.s_addr = INADDR_ANY; // storing ip address of the server (server pc) as server ip address
	address.sin_port = htons(PORT); // setting the port of the server

	// Binding
	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	// Listinging "Actively waiting to make a connection"
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}

	// TLS Protocol Implementation here:


	// Accepting a connection
<<<<<<< HEAD
	if ((socket_pipe = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
=======
	if ((socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
>>>>>>> 5ebac210212d41731ccf063cfae292811494038a
		perror("accept");
		exit(EXIT_FAILURE);
	}

	// Read from the socket:
	ssize_t socket_status = read(socket_pipe, buffer, 1024);

	if (socket_status < 0) {
		perror("Error: Failed to read from socket\n");
		exit(EXIT_FAILURE);
	}
	 
	printf("%s\n", buffer); // print msg from buffer
	send(socket_pipe, hello, strlen(hello), 0); // send msg to client
	printf("Hello message sent\n");

	// closing the connected socket
	close(socket_pipe);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}
