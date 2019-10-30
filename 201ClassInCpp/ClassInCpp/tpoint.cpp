#include "pch.h"
#include <iostream>
#include "consts.h"
#include "strutils.h"
#include "tgeom.h"
#include "tpoint.h"
#include "consoleroutine.h"

TPoint::TPoint() {
	TGeom::TGeom();
	setSymb('.');
	strcpy_s(name, defaultNameLength, "TPoint");
}

TPointType TPoint::getTyp() {
	return typ;
};

void TPoint::setTyp(const TPointType TYP) {
	if (TYP != typ) {
		Erase();
		typ = TYP;
	}
};

char TPoint::getSymb() {
	char s = TGeom::getSymb();
	switch (getTyp()) {
	   case ptBank : { s = 'B'; break; }
	   case ptHouse: { s = 'H'; break; }
	   case ptCafe : { s = 'C'; break; }
	   case ptShop : { s = 'S'; break; }
	   case ptTank : { s = 'T'; break; }
	   case ptPen  : { s = ' '; break; }
	}
	return s;
};

void TPoint::SaveToFile(FILE *fileHandle) {
	fprintf_s(fileHandle, "TPOIN|%d|%d|%d|%d|%d|%c|%d|%s\n", id, getX(), getY(), getColor(), getBgColor(), getSymb(), (int)typ, name);
}

int TPoint::LoadFromStr(char *buffer) {
	int result = 0;
	char *p_block = (char *)malloc(defaultNameLength * sizeof(char));
	char *parser = buffer;
	parser = parseItem(parser, '|', p_block);
	parser = parseItem(parser, '|', p_block); id = atoi(p_block);
	parser = parseItem(parser, '|', p_block); setX( atoi(p_block) );
	parser = parseItem(parser, '|', p_block); setY( atoi(p_block) );
	parser = parseItem(parser, '|', p_block); setColor( (ConsoleColors)atoi(p_block) );
	parser = parseItem(parser, '|', p_block); setBgColor( (ConsoleColors)atoi(p_block) );
	parser = parseItem(parser, '|', p_block); setSymb( *p_block );
	parser = parseItem(parser, '|', p_block); setTyp( (TPointType)atoi(p_block) );
	parser = parseItem(parser, '\n', p_block); strcpy_s(name, strlen(p_block) + 1, p_block);
	free(p_block);
	return result;
}
