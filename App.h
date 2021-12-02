#pragma once
#include <Windows.h>

class App
{
public:
	static HWND hWnd;
	static HDC hDC;

	App();
	virtual ~App();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	virtual void keyDown(WPARAM key);
	virtual void keyUp(WPARAM key);
};