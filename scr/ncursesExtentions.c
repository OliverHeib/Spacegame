#include <ncurses.h>

int exBox(WINDOW * win)
{
    wattron(win, COLOR_PAIR(5));
    box(win,ACS_VLINE,ACS_HLINE);
    for(int i = 1; i < win->_maxy; i++)
    {
        for(int j = 1; j < win->_maxx; j++)
        {
            mvwprintw(win, i, j, " ");
        }
    }
    wattroff(win, COLOR_PAIR(5));
    wrefresh(win);
}

int test(WINDOW * win, char topLeft[20])
{
    mvwprintw(win, 0, 0, topLeft);
}

int exBoxAltChar(WINDOW * win, int colour, char topLeft[20], char Top[20], char topRight[20], char right[20], char bottomRight[20], char bottom[20], char bottomLeft[20], char left[20])
{
    wattron(win, COLOR_PAIR(colour));
    
    mvwprintw(win, 0, 0, topLeft);
    mvwprintw(win, 0, win->_maxx, topRight);
    mvwprintw(win, win->_maxy, 0, bottomLeft);
    mvwprintw(win, win->_maxy, win->_maxx, bottomRight);
    // for(int a = 1; a < win->_maxx; a++)
    // {
    //     mvwprintw(win, 0, a, Top);
    // }

    for(int i = 1; i < win->_maxy; i++)
    {
        mvwprintw(win, i, 0, left);
        mvwprintw(win, i, win->_maxx, right);
        for(int j = 1; j < win->_maxx; j++)
        {
            mvwprintw(win, i, j, " ");
            mvwprintw(win, 0, j, Top);
            mvwprintw(win, win->_maxy, j, bottom);
        }
    }
    wattroff(win, COLOR_PAIR(5));
    wrefresh(win);
}
