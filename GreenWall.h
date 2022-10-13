#pragma once
#include "WallBase.h"
#include "Player.h"

class GreenWall : public WallBase {
public:
	GreenWall(){}
	virtual ~GreenWall(){}

	bool update(Player& player);
};