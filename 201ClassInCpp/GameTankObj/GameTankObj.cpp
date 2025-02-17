#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <locale.h>
#include "../ClassInCpp/consts.h"
#include "../ClassInCpp/strutils.h"
#include "../ClassInCpp/consoleroutine.h"
#include "../ClassInCpp/tgeom.h"
#include "../ClassInCpp/tpoint.h"
#include "../ClassInCpp/trect.h"
#include "../ClassInCpp/tcircle.h"
#include "../ClassInCpp/list2link.h"
#include "../ClassInCpp/gameengine.h"

void gameOnKeyLeft(GameEngine *Sender) {
	if ((Sender->Tank->getX() > Sender->Console->getX()) && (1 != list2_contains(Sender->Map, Sender->Tank->getX() - 1, Sender->Tank->getY()))) {
		Sender->Tank->setX(Sender->Tank->getX() - 1);
	}
}

void gameOnKeyRight(GameEngine *Sender) {
	if ((Sender->Tank->getX() < Sender->Console->getWidth()) && (1 != list2_contains(Sender->Map, Sender->Tank->getX() + 1, Sender->Tank->getY()))) {
		Sender->Tank->setX(Sender->Tank->getX() + 1);
	}
}

void gameOnKeyUp(GameEngine *Sender) {
	if( (Sender->Tank->getY() > Sender->Console->getY()) && (1 != list2_contains(Sender->Map, Sender->Tank->getX(), Sender->Tank->getY()-1))) {
		Sender->Tank->setY(Sender->Tank->getY() - 1);
	}
}


void gameOnKeyDown(GameEngine *Sender) {
	if( (Sender->Tank->getY() < Sender->Console->getHeight()) && (1 != list2_contains(Sender->Map, Sender->Tank->getX(), Sender->Tank->getY() + 1))) {
		Sender->Tank->setY(Sender->Tank->getY() + 1);
	}
}


void gameOnKeyF1(GameEngine *Sender) {
	Sender->boom = new TCircle();
	Sender->boom->setBgColor(clLightMagenta);
	Sender->boom->setColor(clBlack);
	Sender->boom->setX(Sender->Tank->getX());
	Sender->boom->setY(Sender->Tank->getY());
	TCircle *boom1 = (TCircle *)Sender->boom;
	boom1->setR(20);
	boom1->PrintSlowBoom();
	list2 *p = list2_gotofirst(Sender->Map);
	while (NULL != p) {
		if (1 == Sender->boom->Contains(p->geom->getX(), p->geom->getY())) {
			list2 *ptemp = p->next;
			if (p == list2_gotofirst(Sender->Map)) {
				Sender->Map = list2_gotolast(Sender->Map);
			}
			if (p == list2_gotolast(Sender->Map)) {
				Sender->Map = list2_gotofirst(Sender->Map);
			}
			if (1 == list2_count(Sender->Map)) {
				Sender->Map = NULL;
			}
			/*if (p == wasOnObject) {
				wasOnObject = NULL;
			}*/
			list2_del(p);
			p = ptemp;
		}
		else {
			p = p->next;
		}
	}

}

void gameOnKeyDelete(GameEngine *Sender) {
}


void editorOnKeyLeft(GameEngine *Sender) {
	if (Sender->Tank->getX() > Sender->Console->getX()) {
		Sender->Tank->setX(Sender->Tank->getX() - 1);
	}
}

void editorOnKeyDown(GameEngine *Sender) {
	if (Sender->Tank->getY() < Sender->Console->getHeight()) {
		Sender->Tank->setY(Sender->Tank->getY() + 1);
	}
}
void editorOnKeyF6(GameEngine *Sender) {
	if (0 == list2_contains(Sender->Map, Sender->Tank->getX(), Sender->Tank->getY())) {
		Sender->Map =Sender->Map_add_TPoint(Sender->Map,Sender->Tank->getX(), Sender->Tank->getY(), ptShop, clBlack, clLightCyan);
		list2_print(Sender->Map);
	}

}




int main(int argc, char* argv[]) {
	int EditorMode = 0;
	char *param1 = (char *)malloc(MAX_PATH * sizeof(char));
	nullStr(param1, MAX_PATH);

	if (1 < argc) {
		strcpy_s(param1, MAX_PATH, argv[1]);
	}

	strtoupper(param1);

	GameEngine *Game = new GameEngine();

	if (0 == strcmp("EDITOR", param1)) {
		EditorMode = 1;
		Game->Tank->setTyp(ptPen);
		Game->onKeyLeft = &editorOnKeyLeft;
		Game->onKeyF6 = &editorOnKeyF6;
		Game->onKeyDown = &editorOnKeyDown;
	}
	else {

		Game->Tank->setTyp(ptTank);
		Game->Map = list2_loadfromfile(NULL, "c:\\map3.txt");
		Game->onKeyLeft = &gameOnKeyLeft;
		Game->onKeyF1 = &gameOnKeyF1;
		Game->onKeyDelete = &gameOnKeyDelete;
	}

	Game->Run();

	delete Game;

	return 0;
}