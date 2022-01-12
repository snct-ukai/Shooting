#define _USE_MATH_DEFINES	// Visual C++‚ÅM_PI‚ðŽg‚¦‚é‚æ‚¤‚É
#include <cmath>
#include "ShootingApp.h"
#include "EnemyB.h"

EnemyB::EnemyB()
{
}


EnemyB::~EnemyB()
{
}

void EnemyB::init()
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	// M_PI‚ÍƒÎ

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = 100 + 400 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 20;

	point = 100;
}

void EnemyB::update()
{
	if (status & COLLISION) {
		if (etimer.get() > 0.5) {
			cleanup();
		}
		return;
	}
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	// update‚ÌŠÔŠu‚ª’·‚·‚¬‚é‚Æ‚«‚ÍA‹­§“I‚Édt‚ðÝ’è
	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	dx = vx * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	if (x > 800) {
		x -= 800;
	}
	else if (x < 0) {
		x += 800;
	}

	elapsed.reset();
}

void EnemyB::draw()
{
	if (status & COLLISION) {
		drawExplosion();
		return;
	}
	LPCWSTR c;

	c = TEXT("*");
	TextOut(App::hDC, (int)x - 6, (int)y + 6, c, lstrlen(c));
	c = TEXT("**");
	TextOut(App::hDC, (int)x - 12, (int)y - 8, c, lstrlen(c));
	c = TEXT("**");
	TextOut(App::hDC, (int)x - 12, (int)y - 22, c, lstrlen(c));
}