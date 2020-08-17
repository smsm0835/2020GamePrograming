#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include <list>
//Object Headers
#include "Number.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Bridge.h"
#include "Coin.h"
#include "Obstacle.h"

#include "GameScene2.h"

class GameScene2 : public Scene
{
private:
	int score, coinCounter;
	bool backgroundInstatiate, bridgeInstantiate, obstacleInstantiate;
	float coinInstDelayTimer, obstacleInstDelayTimer;

	std::list<Background*> backgroundList;
	std::list<Coin*> coinList;
	Bridge* bridge;
	Obstacle* obstacle;
	Number* numArray[4];
	Player* player;
	Enemy* enemy;
public:
	GameScene2();
	~GameScene2();

	void Render();
	void Update(float dTime);

	void CollisionCheck();
	void EnemyCheck(float dTime);
	void OptimizationObject();
	void InstantiateObject();

	void TimerSetting(float dTime);
	void UISetting();
};