#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

INT WINAPI WinMain(HINSTANCE hInstance
	, HINSTANCE hprevinstance, LPSTR, INT cmdShow) {
	srand(GetTickCount());

	Application app;
	Console console;

	if (CONSOLE_ON) {
		console.OpenConsole();
	}

	app.InitWindow(hInstance);
	app.InitD3D(app.FloatWindow(hInstance, cmdShow));
	app.InitDeltaTime();
	app.InitManager();

	return app.DoMainLoop(new MainScene());
}