#include "stdafx.h"
#include "Player.h"

Player::Player() {
	isJump = false;
	doubleJump = false;
	gravity = 9.8;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Image/player-stop.png");
	playerAnimation->AddFrame("Resources/Image/player-run.png");
	AddChild(playerAnimation);
	playerAnimation->setScale(0.5, 0.5);
	rect = playerAnimation->getRect();
}

Player::~Player() {

}

void Player::Render() {
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime) {
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);
	if (isJump) {
		setPos(getPosX(), getPosY() - 500 * dTime);
		if (doubleJump) {
			setPos(getPosX(), getPosY() - 500 * dTime);
		}
		if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
			doubleJump = true;
		}
	}
	if (getPosY() > 510) {
		setPos(getPosX(), 510);
		doubleJump = false;
		isJump = false;
	}

	if (inputManager->GetKeyState(VK_RIGHT) == KEY_ON) {
		setPos(getPosX() + 200 * dTime, getPosY());
	}
	if (inputManager->GetKeyState(VK_LEFT) == KEY_ON) {
		if(getPosX()>0)
		setPos(getPosX() - 200 * dTime, getPosY());
	}

	if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (getPosY() == 510) {
			isJump = true;
			gravity = 0;
		}
	}

	playerAnimation->Update(dTime);
}