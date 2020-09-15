#include <ncurses.h>
#include "controller/controller.h"

int main(void) {
    char mines, state, out;
    int ch;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    out = 0;
    controller_init();
    for (; !out;) {
        ch = getch();
        switch (ch) {
        case KEY_UP:
        case 'W':
        case 'w':
            controller_move(CONTROLLER_UP);
            break;
        case KEY_DOWN:
        case 'S':
        case 's':
            controller_move(CONTROLLER_DOWN);
            break;
        case KEY_LEFT:
        case 'A':
        case 'a':
            controller_move(CONTROLLER_LEFT);
            break;
        case KEY_RIGHT:
        case 'D':
        case 'd':
            controller_move(CONTORLLER_RIGHT);
            break;
        case 'Z':
        case 'z':
        case 'J':
        case 'j':
            out = controller_check();
            break;
        case 'X':
        case 'x':
        case 'K':
        case 'k':
            controller_mark();
            break;
        case 'Q':
        case 'q':
            out = 1;
            break;
        }
    }
    endwin();
    return 0;
}
