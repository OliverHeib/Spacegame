#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include <ncurses.h>
#include <locale.h>

int screenSetUp();
int reDraw();
struct winsize w;

int main()
{
    char input;
    
    start_color();
    screenSetUp();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(0));
    init_pair(1, COLOR_RED, COLOR_BLACK);
    reDraw();
    while ((input=getch()) != 'q')
    {
        switch (input)
        {
        case 'r':
            reDraw();
            break;
        
        default:
            break;
        }
    }

    endwin();

    return 0;

}

int screenSetUp()
{
    start_color();
    setlocale(LC_CTYPE, "");
    initscr();
    reDraw();
    noecho();
    refresh();

    return 0;
}

int reDraw()
{
    erase();
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    WINDOW * guide = newwin((stdscr->_maxy)*0.25+1, (stdscr->_maxx)+1, (stdscr->_maxy)*0.75, 0);
    attron(COLOR_PAIR(0));
    attroff(COLOR_PAIR(0));
    mvprintw(1,1, "yyyyyyyyyyyy");
    refresh();
    start_color();
    box(guide,ACS_VLINE,ACS_HLINE);
    wattron(guide, COLOR_PAIR(1));
    attron(COLOR_PAIR(1));
    mvwprintw(guide,0, 1, " Hitchhiker's Guide to the Galaxy ");
    wattron(guide, COLOR_PAIR(1));
    attroff(COLOR_PAIR(1));
    wrefresh(guide);
    // printw("hello world!\u2505");
    // mvprintw(2,2,"\u250C\u2500\u2500\u2500\u2510");
    // mvprintw(3,2,"\u2502\u2592\u2592\u2592\u2502");
    // mvprintw(4,2,"\u2514\u2500\u2500\u2500\u2518");
    // mvprintw(5,2,"\u2554\u2550\u2550\u2550\u2557");
    // mvprintw(6,2,"\u2551\u2592\u2592\u2592\u2551");
    // mvprintw(7,2,"\u255A\u2550\u2550\u2550\u255D");
    // mvprintw(8,2,"\u2572");
    // mvprintw(9,3,"\u2572");
    // mvprintw(10,4,"\u2572");
    // for(int i = 0; i<=w.ws_col; i++)
    // {
    //     mvprintw(w.ws_row*0.75, i, "\u2550");
    // }
    // mvprintw(w.ws_row*0.75+1, 1, "Hitchhiker's Guide to the Galaxy");
    // mvprintw(w.ws_row*0.85, w.ws_row*0.10, "Don't Panic");
    return 0;
}