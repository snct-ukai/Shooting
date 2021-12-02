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

	c = TEXT("*");
	TextOut(App::hDC, (int)x, (int)y, c, lstrlen(c));
}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}