#include "Player.h"

void Player::Move(int del_x, int del_y)
{
	pos_x += del_x;
	pos_y += del_y;
}