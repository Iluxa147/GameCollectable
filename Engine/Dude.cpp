#include "Dude.h"

void Dude::OnBorder()
{
	if (x_ + width >= Graphics::ScreenWidth)
	{
		x_ = (Graphics::ScreenWidth-1) - width;
	}
	else if (x_ - width <= 0)
	{
		x_ = width;
	}

	if (y_ + height >= Graphics::ScreenHeight)
	{
		y_ = (Graphics::ScreenHeight - 1) - height;
	}
	else if (y_ - height <= 0)
	{
		y_ = height;
	}

}