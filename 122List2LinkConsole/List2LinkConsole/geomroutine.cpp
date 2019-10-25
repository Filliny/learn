#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "consoleroutine.h"
#include "geomroutine.h"

int PointInRect(   // ���������� "1", ���� ����� ������ ��������������, � "0" ���� �� ������
	short pointX,  // ���������� � �����
	short pointY,  // ���������� Y �����
	short left,    // ���������� X �������� ������ ���� ��������������
	short top,     // ���������� Y �������� ������ ���� ��������������
	short width,   // ������ ��������������
	short height   // ������ ��������������
) {
	int result = 0;
	if ((pointX >= left) && (pointX <= (left + width))
		&& (pointY >= top) && (pointY <= (top + height))) {
		result = 1;
	}
	return result;
}

int PointInCircle(   // ���������� "1", ���� ����� ������ ����������, � "0" ���� �� ������
	short pointX,  // ���������� � �����
	short pointY,  // ���������� Y �����
	short Xo,      // ���������� � ������ ����������
	short Yo,      // ���������� Y ������ ����������
	short radius   // ������ ����������
) {
	int result = 0;
	if (((Xo - pointX)*(Xo - pointX) + (Yo - pointY)*(Yo - pointY)) <= (radius*radius)) {
		result = 1;
	}
	return result;
}

void CirclePrint(short Xo, short Yo, short R) {
	consoleSetColors(clWhite, clWhite);
	for (int x = (Xo - R); x <= (Xo + R); x++) {
		for (int y = (Yo - R); y <= (Yo + R); y++) {
			if (1 == PointInCircle(x, y, Xo, Yo, R)) {
				consoleGotoXY(x, y);
				printf(" ");
			}
		}
	}
}

void CirclePrintClear(short Xo, short Yo, short R) {
	consoleSetColors(clBlack, clBlack);
	for (int x = (Xo - R); x <= (Xo + R); x++) {
		for (int y = (Yo - R); y <= (Yo + R); y++) {
			if (1 == PointInCircle(x, y, Xo, Yo, R)) {
				consoleGotoXY(x, y);
				printf(" ");
			}
		}
	}
}
void RectPrint(short left, short top, short height, short width) {
	consoleSetColors(clYellow, clYellow);
	for (int x = left; x <= (left + width); x++) {
		for (int y = top; y <= (top + height); y++) {
			consoleGotoXY(x, y);
			printf(" ");
		}
	}
}

void RectPrintClear(short left, short top, short height, short width) {
	consoleSetColors(clBlack, clBlack);
	for (int x = left; x <= (left + width); x++) {
		for (int y = top; y <= (top + height); y++) {
			consoleGotoXY(x, y);
			printf(" ");
		}
	}
}