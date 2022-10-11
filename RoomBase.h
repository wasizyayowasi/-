#pragma once

class RoomBase {
	RoomBase(){}
	virtual ~RoomBase(){}

	virtual void init() {}
	virtual void end(){}

	virtual void update(){}
	virtual void draw(){}

	virtual bool isEnd() { return false; }
};