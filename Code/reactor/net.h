#ifndef __NET_H
#define __NET_H

int TCPAccept(char* er, char* ip, int ip_len, int port);

int TCPConnect(char* err, char *addr, int port);

int TCPServer(char* err, int port);


#endif