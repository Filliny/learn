#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "consoleroutine.h"
#include "geomroutine.h"
#include "tpointlist2.h"



int main() {
	short placeLeft   = 1; // минимальная координата X для поездок "танчика"
	short placeTop    = 1; // минимальная координата Y для поездок "танчика"
	short placeWidth  = consoleSizeX() - 1;
	short placeHeight = consoleSizeY() - 1;
	TPoint *tank = TPointCreate(0, (placeWidth / 2), (placeHeight / 2), "TANK", "", ptTank);

	TPoint *list = NULL;
/*
	for (int i = 0; i < 200; i++) {
		list = TPointIns(list, i, 
			((rand() % placeWidth ) + placeLeft), 
			((rand() % placeHeight) + placeTop), "", "", (TPointType)(rand() % 4));
	}
*/
	char *fileName = (char *)malloc(MAX_PATH * sizeof(char));
	strcpy_s(fileName, MAX_PATH, "d:\\map.txt");
	list = TPointLoadFromFile(list, fileName);
	free(fileName);


	TPointPrint(list);
	int flag = 0;
	int keyPressed = 0;
	do {
		TPointPrintItem(tank);
		consoleGotoXY(tank->x, tank->y);

		keyPressed = _getch(); // ждём нажатия клавиши пользователем

		consoleSetColors(clBlack, clBlack); // стираем с экрана танк в старом месте
		consoleGotoXY(tank->x, tank->y);    // по его координатам x и y 
		printf(" ");                        // выводим пробел
		switch (keyPressed){
		    case KEY_ESCAPE: {
			   flag = 1;
			   break;
			}
			case KEY_LEFT: {
				if( (tank->x > placeLeft) && (0 == TPointContains(list, (tank->x-1), tank->y) ) ) { 
					tank->x--;
				}
				break;
			}
			case KEY_RIGHT: {
				if( (tank->x < (placeLeft + placeWidth)) && (0 == TPointContains(list, (tank->x + 1), tank->y))) {
					tank->x++;
				}
				break;
			}
		    case KEY_UP: {
				if( (tank->y > placeTop) && (0 == TPointContains(list, tank->x, (tank->y-1)) ) ) {
					tank->y--;
				}
				break;
			}
		    case KEY_DOWN: {
				if( (tank->y < (placeTop + placeHeight)) && (0 == TPointContains(list, tank->x, (tank->y+1))) ) {
					tank->y++;
				}
				break;
		    }
		}
	} while (0 == flag);

	return 0;
}
