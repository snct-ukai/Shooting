#include "ShootingApp.h"
#include "FlyingObject.h"

FlyingObject::FlyingObject() : x(0), vx(0)
{
}


FlyingObject::~FlyingObject()
{
}

void FlyingObject::init()
{
	x = 0;
	vx = 0;
	elapsed.reset();
}

void FlyingObject::cleanup()
{
}

void FlyingObject::update()
{
}

void FlyingObject::draw()
{
}