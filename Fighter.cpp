#include "ShootingApp.h"
#include "Fighter.h"

Fighter::Fighter() : FlyingObject(), dir(STOP)
{
}

Fighter::~Fighter()
{
}

void Fighter::init()
{
	FlyingObject::init();

	x = 400;
	vx = 200;
	y = 200;
	vy = 200;
}

void Fighter::cleanup()
{
	FlyingObject::cleanup();
}

void Fighter::update()
{
	FlyingObject::update();

	double dx = 0;
	double dy = 0;
	double dt = elapsed.get();

	if (dir & LEFT)
		dx -= vx * dt;
	if (dir & RIGHT)
		dx += vx * dt;
	if (dir & FORE)
		dy -= vy * dt;
	if (dir & BACK)
		dy += vy * dt;

	x += dx;
	y += dy;
	elapsed.reset();
}

void Fighter::draw()
{
	LPCWSTR c;

	c = TEXT("|");
	TextOut(App::hDC, (int)x-2, (int)y-22, c, lstrlen(c));
	c = TEXT("--+--");
	TextOut(App::hDC, (int)x-28, (int)y-8, c, lstrlen(c));
	c = TEXT("-+-");
	TextOut(App::hDC, (int)x-17, (int)y+6, c, lstrlen(c));
	radius = 30;

	drawDebug();
}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}