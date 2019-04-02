//sig trapping, command aliases, file name completion, cmd line ediing, array, job control, arithmetic operations performing abiliy,
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#define BUFSIZE 1024
#define PORT 8080
#define TOK_BUFSIZE 64
#define TOK_DELIM " "
int i =0, j=0;
char hist[50][50];
char history[10]="hist";
char quit[5]="quit";
char serv[6]="remsoc";
//keep all externals below this else it aint workin
#include "history.h"
#include "client.h"
#include "shell.h"
int main(int argc, char **argv){
	cmd_loop();
  return EXIT_SUCCESS;
}