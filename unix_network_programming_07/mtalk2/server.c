//
//  server.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/08/11.
//
//



#include <stdio.h>
#include "mtalk2.h"
#include "sessionman.h"

main()
{
	
	if(sessionman_init(PORT) == -1){
		fprintf(stderr, "cannot setup server \n");
		exit(1);
	}
	
	
	sessionman_loop();
}
