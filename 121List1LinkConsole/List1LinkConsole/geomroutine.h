#ifndef GEOMROUTINE_H
#define GEOMROUTINE_H

int PointInRect(   // ���������� "1", ���� ����� ������ ��������������, � "0" ���� �� ������
	short pointX,  // ���������� � �����
	short pointY,  // ���������� Y �����
	short left,    // ���������� X �������� ������ ���� ��������������
	short top,     // ���������� Y �������� ������ ���� ��������������
	short width,   // ������ ��������������
	short height   // ������ ��������������
);

int PointInCircle( // ���������� "1", ���� ����� ������ ����������, � "0" ���� �� ������
	short pointX,  // ���������� � �����
	short pointY,  // ���������� Y �����
	short Xo,      // ���������� � ������ ����������
	short Yo,      // ���������� Y ������ ����������
	short radius   // ������ ����������
);

void CirclePrint(short Xo, short Yo, short R);
void CirclePrintClear(short Xo, short Yo, short R);
void RectPrint(short left, short top, short height, short width);
void RectPrintClear(short left, short top, short height, short width);

#endif