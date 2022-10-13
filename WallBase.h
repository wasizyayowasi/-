#pragma once

class WallBase {
public:
	WallBase(){}
	virtual ~WallBase(){}

	virtual void init() {}
	virtual void end() {}

	virtual void update() {}

	virtual bool isEnd() { return false; }
};