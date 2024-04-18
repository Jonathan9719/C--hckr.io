#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main() 
{

    WSADATA wsaData;

    int iResult;

    // initialize winsock
    iResult = WSAStartup(MAKEWORD(2, 1), &wsaData);
    if (iResult != 0) 
    {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }







    return 0;
}