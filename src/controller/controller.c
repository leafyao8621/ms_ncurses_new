#include <ncurses.h>
#include "controller.h"
#include "../core/core.h"

static unsigned char r, c;
static char *bp;

static void render(char reveal) {
    bp = board;
    for (char i = 0; i < 8; ++i) {
        for (char j = 0; j < 8; ++j, ++bp) {
            if (reveal) {
                if (*bp & MINE) {
                    mvaddch(i + 1, j << 1, '*');
                } else {
                    mvprintw(i + 1, j << 1, "%hhu", *bp & CNT);
                }
            } else {
                if (*bp & CHECK) {
                    if (*bp & MINE) {
                        mvaddch(i + 1, j << 1, '*');
                    } else {
                        mvprintw(i + 1, j << 1, "%hhu", *bp & CNT);
                    }
                } else if (*bp & MARK) {
                    mvaddch(i + 1, j << 1, 'F');
                } else {
                    mvaddch(i + 1, j << 1, '_');
                }
            }
        }
    }
}

void controller_init(void) {
    r = 0;
    c = 0;
    core_initialize();
    render(0);
    mvaddstr(0, 0, "MINES: ");
    mvprintw(0, 7, "%3hhd", mines);
    move(r + 1, c);
}

void controller_move(char dir) {
    switch (dir) {
    case CONTROLLER_UP:
        --r;
        r &= 0x7;
        break;
    case CONTROLLER_DOWN:
        ++r;
        r &= 0x7;
        break;
    case CONTROLLER_LEFT:
        --c;
        c &= 0x7;
        break;
    case CONTORLLER_RIGHT:
        ++c;
        c &= 0x7;
        break;
    }
    move(r + 1, c << 1);
}

char controller_check(void) {
    char out = 0;
    core_check(r, c);
    if (state) {
        mvprintw(0, 0, "%11c", ' ');
        switch (state) {
        case WIN:
            mvaddstr(0, 0, "WIN");
            break;
        case LOSS:
            mvaddstr(0, 0, "LOSS");
            break;
        }
        render(1);
        mvaddstr(9, 0, "CONTINUE? [y/n]");
        int ch = 0;
        for (; ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n';) {
            ch = getch();
            switch (ch) {
            case 'Y':
            case 'y':
                mvprintw(9, 0, "%16c", ' ');
                controller_init();
                break;
            case 'N':
            case 'n':
                out = 1;
                break;
            }
        }
    } else {
        render(0);
        move(r + 1, c << 1);
    }
    return out;
}

void controller_mark(void) {
    core_mark(r, c);
    mvprintw(0, 7, "%3hhd", mines);
    render(0);
    move(r + 1, c << 1);
}
