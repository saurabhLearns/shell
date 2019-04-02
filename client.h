void cmd_rem(){
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    //char *hello = "Hello from client"; 
    char server_ip[20];
    printf("Enter server ip: ");
    scanf("%s",server_ip);
    char cmd[20];
    scanf("%s",cmd);
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){ 
        printf("\n Socket creation error \n"); 
        
    }
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, server_ip, &serv_addr.sin_addr)<=0)  { 
        printf("\nInvalid address/ Address not supported \n");  
    } 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
        printf("\nConnection Failed \n"); 
    }
    send(sock , cmd , strlen(cmd) , 0 ); 
    printf("command sent\n"); 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
}
