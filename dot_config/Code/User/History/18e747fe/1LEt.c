#define _POSIX_C_SOURCE 200809L

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "message.h"

void err(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// create a new socket
int createSocket() {
    // create socket
    int soc = socket(PF_INET, SOCK_STREAM, 0);

    // socket not created
    if (soc < 0) {
        err("socket not created");
    }

    return soc;
}

// connect given socket soc to server at "localhost" on port "2342"
void connectToTimeServer(int soc) {
    // prepare server adress and port to connect to
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(2342);

    // conncet to server on port 2342
    int retval = connect(soc, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // connect to server on port 2342 failed
    if (retval < 0) {
        err("connect failed");
    }
}

// send time request message to the server
void sendTimeRequest(int soc, const time_request_t* timeRequest) {
    //
    ssize_t bytesSent = send(soc, timeRequest, sizeof(time_request_t), 0);
    
    // send failed
    if (bytesSent < 0) {
        err("send failed");
    }
}

// receive time respond message from the server and store it in timeRespond
void receiveTimeRespond(int soc, time_respond_t* timeRespond) {
    // Daten vom Server empfangen
    ssize_t bytesReceived = recv(soc, timeRespond, sizeof(time_respond_t), 0);
    if (bytesReceived < 0) {
        // Fehler beim Empfangen der Daten
        err("receive failed");
    }
}

int main(void) {
    int soc = createSocket();
    connectToTimeServer(soc);

    time_request_t timeRequest;
    time_respond_t timeRespond;

    timeRequest.timezone = +1;  // CET
    sendTimeRequest(soc, &timeRequest);

    receiveTimeRespond(soc, &timeRespond);
    printf("Current time in Münster: %s", timeRespond.time);

    timeRequest.timezone = -5;  // EST
    sendTimeRequest(soc, &timeRequest);

    receiveTimeRespond(soc, &timeRespond);
    printf("Current time in New York: %s", timeRespond.time);

    // send disconnect message
    timeRequest.timezone = 127;  // magic number
    sendTimeRequest(soc, &timeRequest);

    close(soc);
}
