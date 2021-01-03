#pragma once

class Player
{
public:
	int pos_x;
	int pos_y;
	char avatar;

public:
	Player(int x, int y) :
		pos_x(x),
		pos_y(y),
		avatar('O') {}

public:
	void Move(int del_x, int del_y);
};


