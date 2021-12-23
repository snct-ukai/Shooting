#include "ShootingApp.h"
#include "Fighter.h"
#include "Sound.h"

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
	y = 500;
	vy = 200;
	radius = 30;
}

void Fighter::cleanup()
{
	FlyingObject::cleanup();
	missiles.clear();
}

void Fighter::update()
{
	if (status & COLLISION) {
		if (etimer.get() > 0.5) {
			cleanup();
		}
		return;
	}
	FlyingObject::update();

	double dx = 0;
	double dy = 0;
	double dt = elapsed.get();
	if (x > 0 && x < 800) {
		if (dir & LEFT)
			dx -= vx * dt;
		if (dir & RIGHT)
			dx += vx * dt;
		x += dx;
	}
	else {
		x = x <= 0 ? 1 : 799;
	}
	if (y > 0 && y < 600) {
		if (dir & FORE)
			dy -= vy * dt;
		if (dir & BACK)
			dy += vy * dt;
		y += dy;
	}
	else {
		y = y <= 0 ? 1 : 599;
	}
	elapsed.reset();
}

void Fighter::draw()
{

	if (status & COLLISION) {
		drawExplosion();
		return;
	}
	LPCWSTR c;

	c = TEXT("|");
	TextOut(App::hDC, (int)x-2, (int)y-22, c, lstrlen(c));
	c = TEXT("--+--");
	TextOut(App::hDC, (int)x-28, (int)y-8, c, lstrlen(c));
	c = TEXT("-+-");
	TextOut(App::hDC, (int)x-17, (int)y+6, c, lstrlen(c));

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

void Fighter::loadMissile(Missile* m) {
	missiles.push_back(m);
}

void Fighter::shoot() {
	for (size_t i = 0; i < missiles.size(); i++) {
		if (!(missiles[i]->status & ACTIVE)) {
			missiles[i]->init();
			missiles[i]->fire(x, y - radius, 0, -400);
			Sound::getInstance()->request(TEXT("shoot"));
			return;
		}
	}
}