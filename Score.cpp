#include "Score.h"
#include "ShootingApp.h"

Score::Score() :score(0){}

void Score::init() {
	score = 0;
	OutputDebugString(TEXT("init\n"));
}

void Score::add(int point) {
	score += point;
}

void Score::draw(int x, int y) {
	TCHAR str[20];
	wsprintf(str, TEXT("score:%d"), score);
	TextOut(App::hDC, x, y, str, lstrlen(str));
}