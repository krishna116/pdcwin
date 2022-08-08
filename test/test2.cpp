#include "curses.h"

void ColorPrint(const char* s){
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, 2, 10, s);
    attroff(COLOR_PAIR(1));
}

int main() {
    initscr();
    if(!has_colors()){
        printw("color is unsupported.");
    }else{
        ColorPrint("Hello World");
    }
    refresh();
    getch();
    endwin();
    return 0;
}