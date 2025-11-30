#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "message.h"

void err(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

// create a new socket
int createSocket() {
  int soc = socket(PF_INET, SOCK_STREAM, 0);
  if (soc < 0) { err("socket not created"); }
  return soc;
}

// connect given socket soc to server at "localhost" on port "2342"
void connectToTimeServer(int soc) {
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(2342);
  int retval = connect(soc, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (retval < 0) { err("connect failed"); }
}

// send time request message to the server
void sendTimeRequest(int soc, const time_request_t* timeRequest) {
  
}

// receive time respond message from the server and store it in timeRespond
void receiveTimeRespond(int soc, time_respond_t* timeRespond) {
}

int main(void) {
  int soc = createSocket();
  connectToTimeServer(soc);

  time_request_t timeRequest;
  time_respond_t timeRespond;

  timeRequest.timezone = +1; // CET
  sendTimeRequest(soc, &timeRequest);

  receiveTimeRespond(soc, &timeRespond);
  printf("Current time in Münster: %s", timeRespond.time);


  timeRequest.timezone = -5; // EST
  sendTimeRequest(soc, &timeRequest);

  receiveTimeRespond(soc, &timeRespond);
  printf("Current time in New York: %s", timeRespond.time);


  // send disconnect message
  timeRequest.timezone = 127; // magic number
  sendTimeRequest(soc, &timeRequest);

  close(soc);
}

