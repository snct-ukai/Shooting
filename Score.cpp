#include "Score.h"
#include "ShootingApp.h"

Score::Score() :score(0){}

void Score::init() {
	score = 0;
}

void Score::add(int point) {
	score += point;
}

void Score::draw(int x, int y) {
	TCHAR str[10];
	wsprintf(str, TEXT("%d"), score);
	TextOut(App::hDC, x, y, str, lstrlen(str));
}