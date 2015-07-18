//
//  session.h
//  unix_network_program
//
//  Created by 太田浩二 on 2015/07/18.
//
//
extern void session_init(int soc,
												 char mc, int mx, int my,
												 char pc, int px, int py);
extern void session_loop();