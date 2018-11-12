#pragma once
#include "Graphics.h"
#include "Dude.h"

class Carpet
{
public:
	void UpdateCarpet();
	void isCollided(const Dude& dude);
	void DrawCarpet(Graphics& gfx) const; //const because readonly

public:
	int x_;
	int y_;
	int vx_;
	int vy_;
	bool isCollected_ = false;
	static constexpr int width = 5;
	static constexpr int height = 5;
};