//
//  session.h
//  unix_network_program
//
//  Created by 太田浩二 on 2015/07/19.
//
//
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT (in_port_t)50002
#define HOSTNAME_LENGTH 64

extern void session_init(int soc);
extern void session_loop();