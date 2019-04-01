void cmd_hist(char *line){
	strcpy(hist[i], line);
	++i;
}

void cmd_hist_print(){
for(j = 0; j < i; j++){
		printf("%d: %s\n", j, hist[j]);
	}
	printf("\n");
}

