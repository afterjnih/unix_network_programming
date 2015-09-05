//

//  session.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/09/05.
//
//


#include "bb.h"

void session(int soc)
{
	int width;
	fd_set mask;
	char buf[BUF_LENGTH];
	
	FD_ZERO(&mask);
	FD_SET(0, &mask);
	FD_SET(soc, &mask);
	width = soc + 1;
	
	while(1){
		int cnt;
		fd_set readOk;
		
		readOk = mask;
		select(width, &readOk, NULL, NULL, NULL);
		
		if(FD_ISSET(soc, (fd_set *)&readOk)){
			
			cnt = read(soc, buf, BUF_LENGTH);
			write(1, buf, cnt);
		}
		
		if(FD_ISSET(0, (fd_set *)&readOk)){
			
			cnt = read(0, buf, 80);
			write(soc, buf, cnt);
			
			
			if(buf[0] == '9') exit(0);
		}
	}
}