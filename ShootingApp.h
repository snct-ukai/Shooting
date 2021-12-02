#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#define N_ENEMY_A 2

class ShootingApp :
    public App
{
    Fighter fighter;
    EnemyA enemyA[N_ENEMY_A];
    void init();
    void cleanup();
    void update();
    void draw();
    void keyDown(WPARAM key);
    void keyUp(WPARAM key);
};
