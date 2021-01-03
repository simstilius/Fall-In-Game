#include <iostream>
//#include <ctime>
#include <cstdlib>

#include "Player.h"



class Trap
{
public:
	int pos_x;
	int pos_y;
public:
	Trap(int x, int y) :
		pos_x(x),
		pos_y(y) {}
};

class Ladder
{
public:
	int pos_x;
	int pos_y;
public:
	Ladder(int x, int y) :
		pos_x(x),
		pos_y(y) {}
};

class Grid
{
public:
	const int width;
	const int height;
	Trap traps[3] = { Trap(3,3), Trap(13,2), Trap(6, 17) };
	Ladder ladder = Ladder(5, 5);


public:
	Grid(int w, int h) :
		width(w),
		height(h) {}

public:
	void Draw(Player& player);

};

void Grid::Draw(Player& player)
{
	system("cls");

	for (int i = 0; i < height; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < width; j++)
		{
			if (player.pos_x == j && player.pos_y == i)
			{
				std::cout << player.avatar << " ";
			}
			else if (traps[0].pos_x == j && traps[0].pos_y == i)
			{
				std::cout << "@ ";
			}
			else if (traps[1].pos_x == j && traps[1].pos_y == i)
			{
				std::cout << "@ ";
			}
			else if (traps[2].pos_x == j && traps[2].pos_y == i)
			{
				std::cout << "@ ";
			}
			else if (ladder.pos_x == j && ladder.pos_y == i)
			{
				std::cout << "E ";
			}
			else
			{
				std::cout << "# ";
			}
		}
	}
	std::cout << std::endl;

}


int main()
{

	Grid grid(20, 20);
	Player player(4, 3);
	char move(' ');
	bool lost(false);
	bool won(false);

	do
	{
		// check if lost
		for (int i = 0; i < 3; i++)
		{
			if (player.pos_x == grid.traps[i].pos_x && player.pos_y == grid.traps[i].pos_y)
			{
				lost = true;
				player.avatar = 'X';
			}
		}
		// check if won
		{
			if (player.pos_x == grid.ladder.pos_x && player.pos_y == grid.ladder.pos_y)
			{
				won = true;
				player.avatar = 'S';
			}
		}

		grid.Draw(player);

		if (!lost && !won)
		{
			std::cin >> move;
			switch (move)
			{
				case 'w':
				{
					if (player.pos_y != 0)
					{
						player.Move(0, -1);
					}
					break;
				}
				case 'a':
				{
					if (player.pos_x != 0)
					{
						player.Move(-1, 0);
					}
					break;
				}
				case 's':
				{
					if (player.pos_y != grid.height - 1)
					{
						player.Move(0, 1);
					}
					break;
				}
				case 'd':
				{
					if (player.pos_x != grid.width - 1)
					{
						player.Move(1, 0);
					}
					break;
				}
				default:
				{
					// do nothing
				}
			}
		}
		else
		{
			if (lost)
				std::cout << "You fell into the trap :(" << std::endl;
			else if (won)
				std::cout << "You escpaed :)" << std::endl;
		}

	} while (move != 'e' && !lost && !won);


	return 0;
}

