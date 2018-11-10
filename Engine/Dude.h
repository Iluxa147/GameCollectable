#pragma once
#include "Graphics.h"

class Dude
{
public:
	void OnBorder();

public:
	int x_ = Graphics::ScreenWidth / 2;
	int y_ = Graphics::ScreenHeight / 2;;

	static constexpr int width = 5;
	static constexpr int height = 5;
};