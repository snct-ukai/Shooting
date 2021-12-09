#pragma once
#include <vector>
#include "Missile.h"
#include "FlyingObject.h"

class Fighter : public FlyingObject
{
	unsigned int dir;		// Œ»İ‚ÌˆÚ“®•ûŒü
	std::vector<Missile*> missiles;

public:
	enum DIRECTION {
		STOP = 0,
		FORE = 1,
		BACK = 2,
		LEFT = 4,
		RIGHT = 8
	};

	Fighter();
	~Fighter();

	void init();
	void cleanup();
	void update();
	void draw();
	void loadMissile(Missile* m);
	void shoot();

	void move(DIRECTION dir);
	void stop(DIRECTION dir);
};
