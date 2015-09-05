//
//  service.c
//  unix_network_program
//
//  Created by 太田浩二 on 2015/09/04.
//
//


#include <fcntl.h>
#include "bb.h"

#define DATA_DIR "/vagrant/unix_network_program/unix_network_programming_08/data"
#define MENUSTRING "1.呼び出し 2.休講 3.サークル 4.行事 9.終了 \n"


static int process(int soc, int item);


void service(int soc, char *myname)


{
	pid_t mypid;
	char buf[BUF_LENGTH];
	int item;
	
	mypid= (int)getpid();
	sprintf(buf, "This is %s[%d] serving you. \n",
					myname, (int)mypid);
	write(soc, buf, strlen(buf));
	
	do{
		write(soc, MENUSTRING, strlen(MENUSTRING));
		read(soc, buf, 20);
		sscanf(buf, "%d", &item);
	}
	while(process(soc, item));
	
	close(soc);
}


static int process(int soc, int item)


{
	int fd;
	int cnt;
	char filename[FILENAME_LENGTH];
	char buf[BUF_LENGTH];
	
	if(item == 9)
		return 0;
	
	
	sprintf(filename, "%s/data%d", DATA_DIR, item);
	
	
	if ((fd = open(filename, O_RDONLY)) == -1) {
		write(soc, "invalid number.\n", 17);
		return 1;
	}
	
	
	while((cnt=read(fd, buf, BUF_LENGTH)) != 0)
		write(soc, buf, cnt);
	
	
	close(fd);
	return 1;
}