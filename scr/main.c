#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include <ncurses.h>
#include <locale.h>

struct winsize w;
//WINDOW * guideWin;


int screenSetUp();
int initDrawAll();
int initDrawMainWin(WINDOW * mainWin);
int initDrawGuideWin(WINDOW * guideWin);
int drawRoom1(WINDOW * mainWin);

int main()
{

    char input;
    
    start_color();
    screenSetUp();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(0));
    init_pair(1, COLOR_RED, COLOR_BLACK);
    initDrawAll();
    initDrawAll();
    while ((input=getch()) != 'q')
    {
        switch (input)
        {
        case 'r':
            initDrawAll();
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
    noecho();
    //refresh();

    return 0;
}

int initDrawAll()
{
    erase();
    start_color();
    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLUE);
    WINDOW * guideWin = newwin((stdscr->_maxy)*0.25+1, (stdscr->_maxx)+1, (stdscr->_maxy)*0.75, 0);
    WINDOW * mainWin  = newwin((stdscr->_maxy)*0.75, (stdscr->_maxx)+1, 0, 0);
    WINDOW * chatWin  = newwin((stdscr->_maxy)*0.25-3, (stdscr->_maxx)/3, (stdscr->_maxy)*0.75+2, 7);
    refresh();

    // WINDOW * guideWin2 = newwin((stdscr->_maxy)*0.25+1, (stdscr->_maxx)+1, (stdscr->_maxy)*0.75, 0);
    // wbkgd(guideWin2, COLOR_PAIR(5));
    // box(guideWin2,ACS_VLINE,ACS_HLINE);
    // wrefresh(guideWin2);

    initDrawMainWin(mainWin);

    wattron(guideWin, COLOR_PAIR(5));
    for(int i = 1; i < guideWin->_maxy; i++)
    {
        for(int j = 1; j < guideWin->_maxx; j++)
        {
            mvwprintw(guideWin, i, j, " ");
        }
    }
    wattroff(guideWin, COLOR_PAIR(5));
    wrefresh(guideWin);

    initDrawGuideWin(guideWin);

    box(chatWin, ACS_VLINE,ACS_HLINE);
    

    wattron(chatWin, COLOR_PAIR(4));
    mvwprintw(chatWin, 1,5, "Press q");
    wattroff(chatWin, COLOR_PAIR(4));

    wrefresh(chatWin);
    drawRoom1(mainWin);
    char input;
    bool stay = true;
    move(0,0);
    while (stay)
    {
        input=getch();
        switch (input)
        {
        case 'f':
            mvwprintw(mainWin, 22, 13, "@");
            wmove(mainWin, 22, 13);
            wrefresh(mainWin);
            break;

        case 'q':
            stay = false;
            break;
        
        default:
            break;
        }
    }
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
    // mvprintw(w.ws_row*0.75+1, 1, "Hitchhiker's guideWin to the Galaxy");
    // mvprintw(w.ws_row*0.85, w.ws_row*0.10, "Don't Panic");
    return 0;
}

int initDrawGuideWin(WINDOW * guideWin)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);
    box(guideWin,ACS_VLINE,ACS_HLINE);
    wattron(guideWin, COLOR_PAIR(1));
    mvwprintw(guideWin,0, 1, " Hitchhiker's guide to the Galaxy ");
    wattroff(guideWin, COLOR_PAIR(1));
    wattron(guideWin, COLOR_PAIR(2));
    mvwprintw(guideWin, (guideWin->_maxy)*0.3, (guideWin->_maxx)*0.7, " HP  ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.7, (guideWin->_maxx)*0.7, " AC  ");
    wattroff(guideWin, COLOR_PAIR(2));
    mvwprintw(guideWin, (guideWin->_maxy)*0.3+1, (guideWin->_maxx)*0.7, " 062 ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.7+1, (guideWin->_maxx)*0.7, " 030 ");
    wattron(guideWin, COLOR_PAIR(2));
    mvwprintw(guideWin, (guideWin->_maxy)*0.25, (guideWin->_maxx)*0.8, " INV ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.5, (guideWin->_maxx)*0.8, " CHA ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.75, (guideWin->_maxx)*0.8, " MAP ");
    wattroff(guideWin, COLOR_PAIR(2));
    wrefresh(guideWin);

    return 0;
}

int initDrawMainWin(WINDOW * mainWin)
{
    //box(mainWin,ACS_VLINE,ACS_HLINE);
    mvwprintw(mainWin,0, 1, " Space Game ");
    wrefresh(mainWin);

    return 0;
}

int drawRoom1(WINDOW * mainWin)
{
    mvwprintw(mainWin,20, 10, "-------");
    mvwprintw(mainWin,21, 10, "|.....|");
    mvwprintw(mainWin,22, 10, "|.....|");
    mvwprintw(mainWin,23, 10, "|.....|");
    mvwprintw(mainWin,24, 10, "|.....|");
    mvwprintw(mainWin,25, 10, "-------");
    wrefresh(mainWin);
}