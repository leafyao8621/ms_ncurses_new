#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#define CONTROLLER_UP 0
#define CONTROLLER_DOWN 1
#define CONTROLLER_LEFT 2
#define CONTORLLER_RIGHT 3

void controller_init(void);
char controller_check(void);
void controller_mark(void);
void controller_move(char dir);

#endif
