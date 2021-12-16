#pragma once
#include "FlyingObject.h"
class Missile :
    public FlyingObject
{
private:
    double x;
    double y;
    double vx;
    double vy;
public:
    Missile();
    void init();
    void update();
    void draw();
    void fire(double x, double y, double vx, double vy);
    ~Missile();
};