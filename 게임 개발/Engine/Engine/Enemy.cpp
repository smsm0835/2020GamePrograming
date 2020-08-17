#include "stdafx.h"
#include "Enemy.h"
Enemy::Enemy() {
	gravity = 9.8;

	EnemyAnimation = new Animation(10);
	EnemyAnimation->AddFrame("Resources/Image/player-stop.png");
	EnemyAnimation->AddFrame("Resources/Image/player-run.png");
	AddChild(EnemyAnimation);
    EnemyAnimation->setScale(0.5, 0.5);
	rect = EnemyAnimation->getRect();
}

Enemy::~Enemy() {

}

void Enemy::Render() {
	Object::Render();
	EnemyAnimation->Render();
}

void Enemy::Update(float dTime) {
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);
	if (getPosY() > 510) {
		setPos(getPosX(), 510);
	}

	EnemyAnimation->Update(dTime);
}