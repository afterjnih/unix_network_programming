//
//  client.c
//  unix_network_program_02
//
//  Created by 太田浩二 on 2015/07/11.
//
//

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT (in_port_t)50000
#define BUF_LEN 512

main()
{
    
    struct hostent *server_ent;
    struct sockaddr_in server;
    int soc;
    char hostname[]="server";
    char buf[BUF_LEN];
    
    
    if((server_ent = gethostbyname(hostname)) == NULL){
        perror("gethoustbyname");
        exit(1);
    }
    
    
    memset((char *)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy((char *)&server.sin_addr, server_ent->h_addr,
           server_ent->h_length);
    
    
    if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        exit(1);
    }
    
    
    if(connect(soc, (struct sockaddr *)&server, sizeof(server)) == -1){
        perror("connect");
        exit(1);
    }
    
    
    write(1, "Wait\n", 5);
    
    
    do{
        int n;
        
        n = read(soc, buf, BUF_LEN);
        write(1, buf, n);
        n = read(0, buf, BUF_LEN);
        write(soc, buf, n);
    }
    while(strncmp(buf, "quit", 4) != 0);
    
    close(soc);
}
