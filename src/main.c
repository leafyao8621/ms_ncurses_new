#include <ncurses.h>
#include "controller/controller.h"
#include "core/core.h"
int main(void) {
    core_initialize();
    core_log(1, stdout);
    /*
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
            controller_move(CONTROLLER_UP);
            break;
        case KEY_DOWN:
            controller_move(CONTROLLER_DOWN);
            break;
        case KEY_LEFT:
            controller_move(CONTROLLER_LEFT);
            break;
        case KEY_RIGHT:
            controller_move(CONTORLLER_RIGHT);
            break;
        case 'Z':
        case 'z':
            out = controller_check();
            break;
        case 'X':
        case 'x':
            controller_mark();
            break;
        case 'Q':
        case 'q':
            out = 1;
            break;
        }
    }
    endwin();
    */
    return 0;
}
