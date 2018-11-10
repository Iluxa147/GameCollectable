#include "Carpet.h"
#include "Graphics.h"

void Carpet::UpdateCarpet()
{
	x_ += vx_;
	y_ += vy_;

	if (x_ + width >= Graphics::ScreenWidth)
	{
		x_ = (Graphics::ScreenWidth-1) - width;
		vx_ = -vx_;
	}
	else if (x_ - width <= 0)
	{
		x_ = width;
		vx_ = -vx_;
	}

	if (y_ + height >= Graphics::ScreenHeight)
	{
		y_ = (Graphics::ScreenHeight - 1) - height;
		vy_ = -vy_;
	}
	else if (y_ - height <= 0)
	{
		y_ = height;
		vy_ = -vy_;
	}
}

void Carpet::isCollided(int dudeX, int dudeY, int dudeW, int dudeH)
{
	if (
		x_ - width <= dudeX + dudeW &&
		x_ + width >= dudeX + dudeW &&
		y_ - height <= dudeY + dudeH &&
		y_ + height >= dudeY - dudeH)
	{
		isCollected_ = true;
	}
	else
	{
		isCollected_ = false;
	}
}
