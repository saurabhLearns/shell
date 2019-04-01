//sig trapping, command aliases, file name completion, cmd line ediing, array, job control, arithmetic operations performing abiliy,
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " "
int i =0, j=0;
char hist[50][50];
char history[10]="hist";
char quit[5]="quit";
//keep all externals below this else it aint workin

#include "history.h"
#include "shell.h"

int main(int argc, char **argv){
	cmd_loop();
  return EXIT_SUCCESS;
}

