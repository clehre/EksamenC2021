#ifndef _SOURCE_h
#define _SOURCE_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_PORT 80
#define MAXLINE 4096
#define SA struct sockaddr

#define SERVERIP "77.111.240.75"

int errorMsg(char *error);

#endif