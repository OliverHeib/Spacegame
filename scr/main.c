#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include <ncurses.h>
#include <locale.h>

#include "ncursesExtentions.h"

enum ColourPair { DefaultColour = 0, TitleColour = 1, buttonColour = 2, terminalColour = 4, guideColour = 5 }; 


int screenSetUp();
int initDrawAll();
int initDrawMainWin(WINDOW * mainWin);
int initDrawGuideWin(WINDOW * guideWin);
int drawRoom1(WINDOW * mainWin);
int defColour();

int main()
{
    char input;
    
    start_color();
    screenSetUp();
    initDrawAll();

    endwin();

    return 0;

}

int screenSetUp()
{
    start_color();
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    defColour();
    wbkgd(stdscr, DefaultColour);
    refresh();

    return 0;
}

int defColour()
{
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLUE);
}

int initDrawAll()
{
    erase();
    defColour();
    WINDOW * guideWin = newwin((stdscr->_maxy)*0.25+2, (stdscr->_maxx)+1, (stdscr->_maxy)*0.75, 0);
    WINDOW * mainWin  = newwin((stdscr->_maxy)*0.75, (stdscr->_maxx)+1, 0, 0);
    WINDOW * chatWin  = newwin((stdscr->_maxy)*0.25-2, (stdscr->_maxx)/3, (stdscr->_maxy)*0.75+2, 36);
    refresh();

    initDrawMainWin(mainWin);    

    initDrawGuideWin(guideWin);

    box(chatWin, ACS_VLINE,ACS_HLINE);

    wattron(chatWin, COLOR_PAIR(terminalColour));
    mvwprintw(chatWin, 1,2, "\u2022 Game Loaded");
    wattroff(chatWin, COLOR_PAIR(terminalColour));

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

    return 0;
}

int initDrawGuideWin(WINDOW * guideWin)
{
    defColour();
    exBoxAltChar(guideWin, 5, "\u2500", "\u2500", "\u2500", " ", " ", " ", " ", " ");
    wattron(guideWin, COLOR_PAIR(1));
    mvwprintw(guideWin,0, 1, " Hitchhiker's guide to the Galaxy ");
    wattroff(guideWin, COLOR_PAIR(1));
    wattron(guideWin, COLOR_PAIR(2));
    mvwprintw(guideWin, (guideWin->_maxy)*0.3, (guideWin->_maxx)*0.9, " HP  ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.7, (guideWin->_maxx)*0.9, " AC  ");
    wattroff(guideWin, COLOR_PAIR(2));
    mvwprintw(guideWin, (guideWin->_maxy)*0.3+1, (guideWin->_maxx)*0.9, " 062 ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.7+1, (guideWin->_maxx)*0.9, " 030 ");
    wattron(guideWin, COLOR_PAIR(2));
    mvwprintw(guideWin, (guideWin->_maxy)*0.25, (guideWin->_maxx)*0.95, " INV ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.5, (guideWin->_maxx)*0.95, " CHA ");
    mvwprintw(guideWin, (guideWin->_maxy)*0.75, (guideWin->_maxx)*0.95, " MAP ");
    wattroff(guideWin, COLOR_PAIR(2));

    wattron(guideWin, COLOR_PAIR(guideColour));
    mvwprintw(guideWin, (guideWin->_maxy)*.5-6, 2, " _____                _  _    ");        
    mvwprintw(guideWin, (guideWin->_maxy)*.5-5, 2, "|  __ \\              ( )| |   ");
    mvwprintw(guideWin, (guideWin->_maxy)*.5-4, 2, "| |  | |  ___   _ __ |/ | |_  ");
    mvwprintw(guideWin, (guideWin->_maxy)*.5-3, 2, "| |  | | / _ \\ | '_ \\   | __| ");
    mvwprintw(guideWin, (guideWin->_maxy)*.5-2, 2, "| |__| || (_) || | | |  | |_  ");
    mvwprintw(guideWin, (guideWin->_maxy)*.5-1, 2, "|_____/  \\___/ |_| |_|   \\__| ");
    mvwprintw(guideWin, (guideWin->_maxy)*.5, 2, " _____               _        _ "); 
    mvwprintw(guideWin, (guideWin->_maxy)*.5+1, 2, "|  __ \\             (_)      | |");
    mvwprintw(guideWin, (guideWin->_maxy)*.5+2, 2, "| |__) |__ _  _ __   _   ___ | |");
    mvwprintw(guideWin, (guideWin->_maxy)*.5+3, 2, "|  ___// _` || '_ \\ | | / __|| |");
    mvwprintw(guideWin, (guideWin->_maxy)*.5+4, 2, "| |   | (_| || | | || || (__ |_|");
    mvwprintw(guideWin, (guideWin->_maxy)*.5+5, 2, "|_|    \\__,_||_| |_||_| \\___|(_)");
    wattroff(guideWin, COLOR_PAIR(guideColour));

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