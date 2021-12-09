#pragma once
#include <vector>
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "Missile.h"
#include "Score.h"
#define N_MISSILE 10
#define N_ENEMY_A 2

class ShootingApp :
    public App
{
    Fighter fighter;
    EnemyA enemyA[N_ENEMY_A];
    Missile missile[N_MISSILE];
    std::vector<FlyingObject*> fos;
    std::vector<Enemy*> enemies;
    std::vector<Missile*> missiles;
    Score score;
    void init();
    void cleanup();
    void update();
    void draw();
    void keyDown(WPARAM key);
    void keyUp(WPARAM key);
};