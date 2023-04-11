## Basic Socket Programming:
* Referenced from https://www.geeksforgeeks.org/socket-programming-cc/

### Server
1. Creating a Socket
    - `int sockfd = socket(domain, type, protocol)`
    - sockfd --> a descriptor for the socket
    - domain --> Specifies communication domain (AF_LOCAL for same host and AF_INET b/w different hosts)
    - type --> protocol type (SOCK_STREAM for TCP and SOCK_DGRAM for udp)
    - `int setsockopt(int sockfd, int level, int optname,  const void *optval, socklen_t optlen);`
        - changing socket options => reusing ip addresses and ports
2. Binding a Socket
    - `int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
    - Binds socket to the address and port number specified in addr
    - ie. socket knows what ip address and application the recieving host to deliver the msg too
3. Listening to a socket:
    - `int listen(int sockfd, int backlog);`
    - Server listens to a socket and waits for a client to make a connection with the server. 
    - Backlog defines max length of the queue for pending connections to the server 
4. Accepting a socket connection
    - `int new_socket = accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`
    - Accepts the first connection request on the queue of pending connections
    - Returns file descriptor refering to that communication socket
    - Connection is established and ready for communication

### Client
1. Creating a Socket (Same as server)
2. Connect to socket
    - `int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
    - Connects the socket to the address specified

