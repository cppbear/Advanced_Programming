#include "Map.h"

void Map::createWall()
{
	for (int i = 11; i < 24; i++)
	{
		for (int j = 6; j < 18; j++)
		{
			map[i][j] = new Wall(j * 2, i);
		}
	}
	for (int i = 11; i < 24; i++)
	{
		for (int j = 32; j < 44; j++)
		{
			map[i][j] = new Wall(j * 2, i);
		}
	}
	
	for (int i = 15; i < 20; i++)
	{
		for (int j = 20; j < 30; j++)
		{
			map[i][j] = new Wall(j * 2, i);
		}
	}
	for (int i = 10; i < 30; i++)
	{
		for (int j = 23; j < 27; j++)
		{
			map[i][j] = new Wall(j * 2, i);
		}
	}
	
	for (int i = 16; i < 19; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			map[i][j] = new Wall(j * 2, i);
		}
	}
	for (int i = 16; i < 19; i++)
	{
		for (int j = 44; j < 49; j++)
		{
			map[i][j] = new Wall(j * 2, i);
		}
	}

	for (int i = 5; i < 10; i++)
	{
		for (int j = 21; j < 29; j++)
		{
			map[i][j] = new IronWall(j * 2, i);
		}
	}
	for (int i = 15; i < 20; i++)
	{
		for (int j = 6; j < 11; j++)
		{
			map[i][j] = new IronWall(j * 2, i);
		}
		for (int j = 17; j < 20; j++)
		{
			map[i][j] = new IronWall(j * 2, i);
		}
	}
	for (int i = 15; i < 20; i++)
	{
		for (int j = 30; j < 33; j++)
		{
			map[i][j] = new IronWall(j * 2, i);
		}
		for (int j = 39; j < 44; j++)
		{
			map[i][j] = new IronWall(j * 2, i);
		}
	}

	for (int j = 21; j < 29; j++)
	{
		map[30][j] = new Wall(j * 2, 30);
		map[31][j] = new Wall(j * 2, 31);
	}
	for (int i = 32; i < 35; i++)
	{
		map[i][21] = new Wall(42, i);
		map[i][22] = new Wall(44, i);
		map[i][27] = new Wall(54, i);
		map[i][28] = new Wall(56, i);
	}
	for (int i = 32; i < 35; i++)
	{
		for (int j = 23; j < 27; j++)
			map[i][j] = new Base(j * 2, i);
	}
}
