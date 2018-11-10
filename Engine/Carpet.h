#pragma once

class Carpet
{
public:
	void UpdateCarpet();
	void isCollided(int dudeX, int dudeY, int dudeW, int dudeH);

public:
	int x_;
	int y_;
	int vx_;
	int vy_;
	bool isCollected_ = false;
	static constexpr int width = 5;
	static constexpr int height = 5;
};