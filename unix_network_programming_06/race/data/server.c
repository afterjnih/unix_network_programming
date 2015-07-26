//
//  server.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/07/26.
//
//


#include <stdio.h>
#include "race.h"
#include "mylib.h"
#include "sessionman.h"

main(int argc, char *argv[])



{
	int num;
	int final;
	int soc_waiting;
	int maxfd;
	
	
	if(argc != 3){
		fprintf(stderr, "Usage: s players stages\n");
		exit(1);
	}
	
	
	if((num = atoi(argv[1])) <=0 || num > MAX_PLAYERS){
		fprintf(stderr, "players limit= %d\n", MAX_PLAYERS);
		exit(1);
	}
	if((final = atoi(argv[2])) <= 0 || final > MAX_STAGES){
		fprintf(stderr, "stage limit= %d\n", MAX_STAGES);
		eixt(1);
	}
	
	
	if((soc_waiting = mserver_socket(PORT, num)) == -1){
		fprintf(stderr, "cannot setup server\n");
		exit(1);
	}
	
	
	
	maccept = mserver_maccept(soc_waiting, num, enter);
	
	
	sessionman_init(num, final, maxfd);
	
	
	sessionman_loop();
}