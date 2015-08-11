//
//  client.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/08/12.
//
//



#include <stdio.h>
#include "mtalk2.h"
#include "session.h"

main()
{
	char hostname[HOSTNAME_LENGTH];
	
	
	printf("input server's hostname: ");
	fgets(hostname, HOSTNAME_LENGTH, stdin);
	chop_newline(hostname, HOSTNAME_LENGTH);
	
	
	if(session_setupclient(hostname, PORT) < 0)
		exit(1);
	
	
	session_init();
	
	
	session_loop();
}
