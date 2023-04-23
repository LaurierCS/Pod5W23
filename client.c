#include <arpa/inet.h>
#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 5ebac210212d41731ccf063cfae292811494038a
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
  
int main(int argc, char const* argv[])
{
    int connect_status, client_fd;  // creating a socket file handler/descriptor and connection status
    struct sockaddr_in address; // stores a address and port #

    char* hello = "Hello from client"; // actual msg to send
    char buffer[1024] = { 0 }; // used for communication --> will hold msg from server

    // Creating socket and "identifying" w/ file descriptior
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Could not create socket\n"); 
        exit(EXIT_FAILURE);
    }
  
    // Assigning address info
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
  
    // Handling Server IP:
<<<<<<< HEAD
    char* ip = "10.0.0.93"; 
=======
    char* ip = "127.0.0.1"
>>>>>>> 5ebac210212d41731ccf063cfae292811494038a

    // Converting IPV4 address to network address structure
    if (inet_pton(AF_INET, ip, &address.sin_addr) <= 0) {
        perror("\nError: Invalid address/Address not supported \n");
        return(EXIT_FAILURE);
    }
  
<<<<<<< HEAD
    if ((connect_status = connect(client_fd, (struct sockaddr*)&address, sizeof(address))) < 0) {
        perror("Error: Conenction Failed \n");
        return -1;
    }

=======
    if ((status = connect(client_fd, (struct sockaddr*)&address, sizeof(address))) < 0) {
        error("Error: Conenction Failed \n");
        return -1;
    }
>>>>>>> 5ebac210212d41731ccf063cfae292811494038a
    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    ssize_t socket_status = read(client_fd, buffer, 1024);
    printf("%s\n", buffer);
  
    // closing the connected socket
    close(client_fd);
    return 0;
}