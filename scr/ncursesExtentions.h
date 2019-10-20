#ifndef NCURSESEXTENTIONS_H
#define NCURSESEXTENTIONS_H

int exBox(WINDOW * Win);
int exBoxAltChar(WINDOW * win, int colour, char topLeft[20], char Top[20], char topRight[20], char right[20], char bottomRight[20], char bottom[20], char bottomLeft[20], char left[20]);
int test(WINDOW * win, char topLeft[20]);

#endif