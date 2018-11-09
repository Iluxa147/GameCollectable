/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd_( wnd ),
	gfx_( wnd )
{
}

void Game::Go()
{
	gfx_.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx_.EndFrame();
}

void Game::UpdateModel()
{

	if (wnd_.kbd.IsKeyPressed(VK_RIGHT))
	{
		xMovable_ += 3;
	}
	if (wnd_.kbd.IsKeyPressed(VK_LEFT))
	{
		xMovable_ -= 3;
	}
	if (wnd_.kbd.IsKeyPressed(VK_UP))
	{
		yMovable_ -= 3;
	}
	if (wnd_.kbd.IsKeyPressed(VK_DOWN))
	{
		yMovable_ += 3;
	}
	
	if (xMovable_ + 5 >= gfx_.ScreenWidth)
	{
		xMovable_ = gfx_.ScreenWidth - 6;
	}
	if (xMovable_ - 5 <= 0)
	{
		xMovable_ = 5;
	}
	if (yMovable_ + 5 >= gfx_.ScreenHeight)
	{
		yMovable_ = gfx_.ScreenHeight - 6;
	}
	if (yMovable_ - 5 <= 0)
	{
		yMovable_ = 5;
	}

	isCollided_ = isCollided(xMovable_, yMovable_, xStatic_, yStatic_);


}

void Game::ComposeFrame()
{

	int rMovable, gMovable, bMovable;
	int rStatic = 0, gStatic = 255, bStatic = 0;

	if (isCollided_)
	{
		rMovable = 255;
		gMovable = bMovable = 0;
	}
	else
	{
		rMovable = gMovable = bMovable = 255;
	}

	DrawCross(xMovable_, yMovable_, rMovable, gMovable, bMovable);
	DrawCross(xStatic_, yStatic_, rStatic, gStatic, bStatic);
}

void Game::DrawCross(int x, int y, int r, int g, int b) // TODO hardcode time!
{
	gfx_.PutPixel(-5 + x, y, r, g, b);
	gfx_.PutPixel(-4 + x, y, r, g, b);
	gfx_.PutPixel(-3 + x, y, r, g, b);
	gfx_.PutPixel(3 + x, y, r, g, b);
	gfx_.PutPixel(4 + x, y, r, g, b);
	gfx_.PutPixel(5 + x, y, r, g, b);
	gfx_.PutPixel(x, -5 + y, r, g, b);
	gfx_.PutPixel(x, -4 + y, r, g, b);
	gfx_.PutPixel(x, -3 + y, r, g, b);
	gfx_.PutPixel(x, 3 + y, r, g, b);
	gfx_.PutPixel(x, 4 + y, r, g, b);
	gfx_.PutPixel(x, 5 + y, r, g, b);

}

bool Game::isCollided(int box0x, int box0y, int box1x, int box1y)
{
	const int LBox0 = box0x - 5;
	const int RBox0 = box0x + 5;
	const int TBox0 = box0y - 5;
	const int BBox0 = box0y + 5;

	const int LBox1 = box1x - 5;
	const int RBox1 = box1x + 5;
	const int TBox1 = box1y - 5;
	const int BBox1 = box1y + 5;

	return
		LBox0 <= RBox1 &&
		RBox0 >= LBox1 &&
		TBox0 <= BBox1 &&
		BBox0 >= TBox1;
}
