#include "ShootingApp.h"
#include "Sound.h"

void ShootingApp::init() {
	App::init();
	fighter.init();
	fos.push_back(&fighter);
	for (int i = 0; i < N_ENEMY_A; i++) {
		enemyA[i].init();
		enemies.push_back(&enemyA[i]);
		fos.push_back(&enemyA[i]);
	}
	for (int i = 0; i < N_ENEMY_B; i++) {
		enemyB[i].init();
		enemies.push_back(&enemyB[i]);
		fos.push_back(&enemyB[i]);
	}
	for (size_t i = 0; i < N_MISSILE; i++) {
		fighter.loadMissile(&missile[i]);
		missiles.push_back(&missile[i]);
		fos.push_back(&missile[i]);
	}
	score.init();
	Sound::getInstance()->registerFile(TEXT("M:/music/explosion.mp3"), TEXT("explosion"));
	Sound::getInstance()->registerFile(TEXT("M:/music/CHIPTUNE.mp3"), TEXT("shoot"));
	Sound::getInstance()->registerFile(TEXT("M:/music/orchestral_mission.mp3"), TEXT("bgm"));
	Sound::getInstance()->request(TEXT("bgm"));
}

void ShootingApp::cleanup() {
	App::cleanup();
	for (size_t i = 0; i < fos.size(); i++) {
		fos[i]->cleanup();
	}
	fos.clear();
	enemies.clear();
	missiles.clear();
	Sound::getInstance()->cleanup();
}

void ShootingApp::update() {
	App::update();
	for (size_t i = 0; i < fos.size(); i++) {
		if (fos[i]->status & FlyingObject::ACTIVE) {
			fos[i]->update();
		}
	}
	for (size_t i = 0; i < enemies.size(); i++) { // すべての敵機について衝突判定
		if (!(enemies[i]->status & FlyingObject::ACTIVE)) {
			// アクティブでなければ
			continue; // 判定しない
		}
		for (size_t j = 0; j < missiles.size(); j++) {// すべてのミサイルについて
				//TCHAR str[30];
				//wsprintf(str, TEXT("missiles:%d"), missiles.size());
				//OutputDebugString(str);
			if (enemies[i]->checkCollision(missiles[j])) { // 衝突していたら
				OutputDebugString(TEXT("missile\n"));
				score.add(enemies[i]->point);
			}
		}
		enemies[i]->checkCollision(&fighter); // 自機との衝突判定
	}
	for (size_t i = 0; i < enemies.size(); i++) {
		if (!enemies[i]->status) {
			enemies[i]->init();
		}
	}
	if (!fighter.status) {
		cleanup();
		init();
	}
}

void ShootingApp::draw() {
	App::draw();
	for (size_t i = 0; i < fos.size(); i++) {
		if (fos[i]->status & FlyingObject::ACTIVE) {
			fos[i]->draw();
		}
	}
	score.draw(10, 10);
	Sound::getInstance()->play();
}

void ShootingApp::keyDown(WPARAM key) {
	switch (key) {
	case VK_LEFT:
		fighter.move(Fighter::LEFT);
		break;
	case VK_RIGHT:
		fighter.move(Fighter::RIGHT);
		break;
	case VK_UP:
		fighter.move(Fighter::FORE);
		break;
	case VK_DOWN:
		fighter.move(Fighter::BACK);
		break;
	case VK_SPACE:
		fighter.shoot();
		break;
	}
}

void ShootingApp::keyUp(WPARAM key) {
	switch (key) {
	case VK_LEFT:
		fighter.stop(Fighter::LEFT);
		break;
	case VK_RIGHT:
		fighter.stop(Fighter::RIGHT);
		break;
	case VK_UP:
		fighter.stop(Fighter::FORE);
		break;
	case VK_DOWN:
		fighter.stop(Fighter::BACK);
		break;
	}
}