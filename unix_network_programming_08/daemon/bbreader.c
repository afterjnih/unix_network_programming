//
//  bbreader.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/09/04.
//
//
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#include "mylib.h"
#include "bb.h"

extern void session(int soc);

main()
{
	int soc = -1;
	char hostname[HOSTNAME_LENGTH];
	

	printf("input server's hostname: ");
	fgets(hostname, HOSTNAME_LENGTH, stdin);
	chop_newline(hostname, HOSTNAME_LENGTH);
	
	
	if((soc = setup_client(hostname, PORT)) < 0){
		exit(1);
	}
	
	
	session(soc);
}
