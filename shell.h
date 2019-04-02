char *cmd_read(void){
  int bufsize = BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char)*bufsize);
  int c;
  if (!buffer){
    	fprintf(stderr, "allocation error\n");
    	exit(EXIT_FAILURE);
  }
  while(1){
		//Read a character
  	c = getchar();
    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
    	buffer[position] = '\0';
    	return buffer;
    }
		else
      buffer[position] = c;
    position++;
    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
    	bufsize += BUFSIZE;
    	buffer = realloc(buffer, bufsize);
    	if (!buffer) {
    		fprintf(stderr, "HellShell: allocation error\n");
    		exit(EXIT_FAILURE);
    	}
    }
  }
}

char **cmd_args(char *line){
  int bufsize = TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;
  if (!tokens) {
   	fprintf(stderr, "allocation error\n");
   	exit(EXIT_FAILURE);
  }
  token = strtok(line, TOK_DELIM);
  while (token != NULL) {
   	tokens[position] = token;
   	position++;
		if (position >= bufsize) {
  		bufsize += TOK_BUFSIZE;
    	tokens = realloc(tokens, bufsize * sizeof(char*));
    	if (!tokens) {
    		fprintf(stderr, "allocation error\n");
    		exit(EXIT_FAILURE);
    	}
  	}	
  token = strtok(NULL, TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int cmd_exit(char **args){
	return 0;
}

int cmd_go(char **args){
  pid_t pid, wpid;
  int status;
  pid = fork();
  if (pid == 0) {	
		// Child process
   		if (execvp(args[0], args) == -1) 
  			perror("HellShell Error>");
    	exit(EXIT_FAILURE);
  	} 
	else if (pid < 0) // Error forking
		perror("HellShell:");
	else { 
		// Parent process
   		do {
  			wpid = waitpid(pid, &status, WUNTRACED);
    		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

int cmd_execute(char **args){
  int i;
  if (args[0] == NULL){
		printf("Write arguments");
		return 1;
	}
  return cmd_go(args);
}
void cmd_loop(void){
  char *line;
  char **args;
  int status;
  do{
		printf("HellShell> ");
   		line = cmd_read();
			cmd_hist(line);
			if(strcmp(line, history)==0){
				cmd_hist_print();
				continue;
			}
			if(strcmp(line, serv)==0){
				cmd_rem();
				continue;
			}
			if(strcmp(line, quit)==0)
				break;
   		args = cmd_args(line);
   		status = cmd_execute(args);
   		free(line);
   		free(args);
	}while (status);
}
