#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// ���݂̈ʒu (pixel)
	double vx;	// ���݂̈ړ����x (pixel/s)
	double y;
	double vy;
	double radius;
	Timer mtimer;
	Timer elapsed;	// �O���update����̌o�ߎ��Ԍv���p
public:
	enum STATUS {
		ACTIVE = 1,
		COLLISION = 2
	};

	unsigned int status;
	FlyingObject();
	virtual ~FlyingObject();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	virtual void drawDebug();
};