#include "ShootingApp.h"
#include "Missile.h"

Missile::Missile(){}

void Missile::init()
{
	FlyingObject::init();
	vx = vy = 0;
	radius = 10;
}
void Missile::update()
{
	if (status & COLLISION) {
		if (etimer.get() > 0.5) {
			cleanup();
		}
		return;
	}
	if (x < 0 || x > 799 || y < 0 || y > 599) // 画面からはみ出たら、ミサイルはなくなる。
		cleanup();

	double dt = elapsed.get();
	x += vx * dt;
	y += vy * dt;
	elapsed.reset();
}
void Missile::draw()
{
	if (status & COLLISION) {
		drawExplosion();
		return;
	}
	LPCWSTR c;

	c = TEXT("**");
	TextOut(App::hDC, (int)x - 12, (int)y + 6, c, lstrlen(c));
	c = TEXT("**");
	TextOut(App::hDC, (int)x - 12, (int)y - 8, c, lstrlen(c));
}
void Missile::fire(double x, double y, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}

Missile::~Missile(){}