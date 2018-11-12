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

void Dude::DrawDude(Graphics& gfx) const
{
	gfx.PutPixel(-5 + x_, y_, 255, 255, 255);
	gfx.PutPixel(-4 + x_, y_, 255, 255, 255);
	gfx.PutPixel(-3 + x_, y_, 255, 255, 255);
	gfx.PutPixel(3 + x_, y_,  255, 255, 255);
	gfx.PutPixel(4 + x_, y_,  255, 255, 255);
	gfx.PutPixel(5 + x_, y_,  255, 255, 255);
	gfx.PutPixel(x_, -5 + y_, 255, 255, 255);
	gfx.PutPixel(x_, -4 + y_, 255, 255, 255);
	gfx.PutPixel(x_, -3 + y_, 255, 255, 255);
	gfx.PutPixel(x_, 3 + y_,  255, 255, 255);
	gfx.PutPixel(x_, 4 + y_,  255, 255, 255);
	gfx.PutPixel(x_, 5 + y_,  255, 255, 255);

}
