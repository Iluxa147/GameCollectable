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

Game::Game(MainWindow& wnd) :
	wnd_(wnd),
	gfx_(wnd)
{
	Carpet0_.x_ = 20;
	Carpet0_.y_ = 20;
	Carpet1_.x_ = 100;
	Carpet1_.y_ = 100;
	Carpet2_.x_ = 400;
	Carpet2_.y_ = 400;

	Carpet0_.vx_ = 0;
	Carpet0_.vy_ = 0;
	Carpet1_.vx_ = -5;
	Carpet1_.vy_ = -5;
	Carpet2_.vx_ = -5;
	Carpet2_.vy_ = -5;

	point0_.x = 100;
	point0_.y = 100;
	point0_.color = Colors::Magenta;
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
		point0_.x += 3;

		x0+=3;

		Dude0_.x_ += 3;
	}
	if (wnd_.kbd.IsKeyPressed(VK_LEFT))
	{
		point0_.x -= 3;

		x0-=3;

		Dude0_.x_ -= 3;
	}
	if (wnd_.kbd.IsKeyPressed(VK_UP))
	{
		point0_.y -= 3;

		y0-=3;

		Dude0_.y_ -= 3;
	}
	if (wnd_.kbd.IsKeyPressed(VK_DOWN))
	{
		point0_.y += 3;

		y0+=3;

		Dude0_.y_ += 3;
	}

	if (wnd_.mouse.IsLeftPressed())
	{
		x1 = wnd_.mouse.GetPosX();
		y1 = wnd_.mouse.GetPosY();
	}

	/*if (wnd_.kbd.IsKeyPressed('D'))
	{
		squareLengthX+=3;
	}

	if (wnd_.kbd.IsKeyPressed('A'))
	{
		squareLengthX -= 3;
	}

	if (wnd_.kbd.IsKeyPressed('W'))
	{
		squareHeightY -= 3;
	}

	if (wnd_.kbd.IsKeyPressed('S'))
	{
		squareHeightY += 3;
	}*/

	Dude0_.OnBorder();
	//Dude0_.x_ = OnBorderX(Dude0_.x_);
	//Dude0_.y_ = OnBorderY(Dude0_.y_);
	

	Carpet0_.UpdateCarpet();
	Carpet1_.UpdateCarpet();
	Carpet2_.UpdateCarpet();


	/*carpet1X_ += carpet1VX_;
	carpet1Y_ += carpet1VY_;

	{
		const int carpet1XHold = carpet1X_;
		const int carpet1YHold = carpet1Y_;

		carpet1X_ = OnBorderX(carpet1X_);
		if (carpet1X_ != carpet1XHold)
		{
			carpet1VX_ = -carpet1VX_;
		}

		carpet1Y_ = OnBorderY(carpet1Y_);
		if (carpet1Y_ != carpet1YHold)
		{
			carpet1VY_ = -carpet1VY_;
		}
	}*/

	Carpet0_.isCollided(Dude0_);
	//isCollided_ = isCollided(Dude0_.x_, Dude0_.y_, Carpet0_.x_, Carpet0_.y_);


}

void Game::ComposeFrame()
{

	gfx_.DrawRect(point0_, x1, y1);

	int rMovable, gMovable, bMovable;
	int rStatic = 0, gStatic = 255, bStatic = 0;



	if (Carpet0_.isCollected_ || Carpet1_.isCollected_ || Carpet2_.isCollected_)
	{
		rMovable = 255;
		gMovable = bMovable = 0;
	}
	else
	{
		rMovable = gMovable = bMovable = 255;
	}

	Dude0_.DrawDude(gfx_);
	
	Carpet0_.DrawCarpet(gfx_);
	Carpet1_.DrawCarpet(gfx_);
	Carpet2_.DrawCarpet(gfx_);

	//DrawCross(Dude0_.x_, Dude0_.y_, rMovable, gMovable, bMovable);

	//DrawCross(Carpet0_.x_, Carpet0_.y_, rStatic, gStatic, bStatic);
	//DrawCross(Carpet1_.x_, Carpet1_.y_, rStatic, gStatic, bStatic);
	//DrawCross(Carpet2_.x_, Carpet2_.y_, rStatic, gStatic, bStatic);

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
