#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// ���݂̈ʒu (pixel)
	double vx;	
	double y;
	double vy;	// ���݂̈ړ����x (pixel/s)
	Timer elapsed;	// �O���update����̌o�ߎ��Ԍv���p
public:
	FlyingObject();
	virtual ~FlyingObject();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
};