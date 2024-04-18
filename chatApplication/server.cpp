#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main()
{
    int server_fd, new_socket;
    struct socaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILER);
    }

    // forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        memset(buffer, 0, sizeof(buffer)); // clear the buffer
        int bytes_read = read(new_socket, buffer, sizeof(buffer));
        if (bytes_read == 0)
        {
            cout << "Client disconnected" << endl;
            break;
        }

        cout << "Client: " << buffer << endl;

        // Echo the message back to the client
        send(new_socket, buffer, strlen(buffer), 0)

        // check if the message is a command to close the connection
        if (strcmp(buffer, "exit") == 0)
        {
            cout << "Exit command received. Closing connection." << endl;
            break;
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}