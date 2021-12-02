#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// 現在の位置 (pixel)
	double vx;	
	double y;
	double vy;	// 現在の移動速度 (pixel/s)
	Timer elapsed;	// 前回のupdateからの経過時間計測用
public:
	FlyingObject();
	virtual ~FlyingObject();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
};