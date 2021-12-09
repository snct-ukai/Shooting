#include "ShootingApp.h"
#include "Missile.h"

Missile::Missile(): x(0), y(0), vx(0), vy(0){}

void Missile::init()
{
	FlyingObject::init();
	vx = vy = 0;
	radius = 10;
}
void Missile::update()
{
	if (x < 0 || x > 799 || y < 0 || y > 599) // ��ʂ���͂ݏo����A�~�T�C���͂Ȃ��Ȃ�B
		cleanup();
	double dt = elapsed.get();
	x += vx * dt;
	y += vy * dt;
	elapsed.reset();
}
void Missile::draw()
{
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
}
void Missile::fire(double x, double y, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}


Missile::~Missile(){}