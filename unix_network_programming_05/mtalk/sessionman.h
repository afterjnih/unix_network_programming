//
//  sessionman.h
//  unix_network_program
//
//  Created by 太田浩二 on 2015/07/19.
//
//
#include <sys/types.h>
#include <netinet/in.h>

#define PORT (in_port_t)50002
#define MAX_ATTENDANTS 5

extern void enter();
extern void sessionman_init(int num, int maxfd);
extern void sessionman_loop();