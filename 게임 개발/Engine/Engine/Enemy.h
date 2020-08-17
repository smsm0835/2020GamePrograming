#pragma once
#include "Object.h"
#include "Animation.h"

class Enemy : public Object
{
private:
	Animation* EnemyAnimation;
	float gravity;
	bool doubleJump, isJump;

public:
	Enemy();
	~Enemy();

	void Render();
	void Update(float dTime);

};