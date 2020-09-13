#include "Bullet.h"
#include "Tank.h"
#include "Buff.h"

int Bullet::run()
{
	for (int i = 0; i < speed; i++)
	{
		draw(false);
		if (map.map[y][x / 2] && map.map[y][x / 2]->getType() == type)
			map.map[y][x / 2] = nullptr;
		if (x <= 2 || x >= WIDTH - 4 || y <= 1 || y >= HEIGHT - 2)
			return -1;
		if (coll || collision())
		{
			return -1;
		}
		switch (direct)
		{
		case UP:
			y -= 1;
			break;
		case DOWN:
			y += 1;
			break;
		case LEFT:
			x -= 2;
			break;
		case RIGHT:
			x += 2;
			break;
		default:
			break;
		}
		map.map[y][x / 2] = this;
	}
	return 0;
}

void Bullet::draw(bool filling)
{
	if (filling)
		drawAtPoint(x, y, "¡ñ", GOLD);
	else
		drawAtPoint(x, y, "  ", "");
}

bool Bullet::collision()
{
	Element* p;
	TYPE opptype;
	BUFFTYPE buff;
	switch (direct)
	{
	case UP:
		if (map.map[y - 1][x / 2])
		{	
			p = map.map[y - 1][x / 2];
			opptype = p->getType();
			if (opptype == WALL || power >= 2 && opptype == IRONWALL)
			{
				p->draw(false);
				map.map[y - 1][x / 2] = nullptr;
			}
			else if (opptype == BASE)
			{
				if (belong->getCamp() == ENEMY)
				{
					active = false;
				}
			}
			else if (opptype == TANK)
			{
				if (belong->getCamp() != ((Tank*)p)->getCamp())
				{
					((Tank*)p)->reduceLife(power);
				}
			}
			else if (opptype == BULLET)
			{
				((Bullet*)p)->coll = true;
			}
			else if (opptype == BUFF)
			{
				buff = ((Buff*)p)->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					belong->addLife(false, 1);
					break;
				case SPEEDBUFF:
					belong->addSpeed(1);
					break;
				case POWERBUFF:
					belong->powerUp();
					break;
				case VOLUMEBUFF:
					belong->volumeUP();
					break;
				default:
					break;
				}
				map.map[y - 1][x / 2] = nullptr;
				p->draw(false);
			}
			return true;
		}
		break;
	case DOWN:
		if (map.map[y + 1][x / 2])
		{
			p = map.map[y + 1][x / 2];
			opptype = p->getType();
			if (opptype == WALL || power >= 2 && opptype == IRONWALL)
			{
				p->draw(false);
				map.map[y + 1][x / 2] = nullptr;
			}
			else if (opptype == BASE)
			{
				if (belong->getCamp() == ENEMY)
				{
					active = false;
				}
			}
			else if (opptype == TANK)
			{
				if (belong->getCamp() != ((Tank*)p)->getCamp())
				{
					((Tank*)p)->reduceLife(power);
				}
			}
			else if (opptype == BULLET)
			{
				((Bullet*)p)->coll = true;
			}
			else if (opptype == BUFF)
			{
				buff = ((Buff*)p)->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					belong->addLife(false, 1);
					break;
				case SPEEDBUFF:
					belong->addSpeed(1);
					break;
				case POWERBUFF:
					belong->powerUp();
					break;
				case VOLUMEBUFF:
					belong->volumeUP();
					break;
				default:
					break;
				}
				map.map[y + 1][x / 2] = nullptr;
				p->draw(false);
			}
			return true;
		}
		break;
	case LEFT:
		if (map.map[y][x / 2 - 1])
		{
			p = map.map[y][x / 2 - 1];
			opptype = p->getType();
			if (opptype == WALL || power >= 2 && opptype == IRONWALL)
			{
				p->draw(false);
				map.map[y][x / 2 - 1] = nullptr;
			}
			else if (opptype == BASE)
			{
				if (belong->getCamp() == ENEMY)
				{
					active = false;
				}
			}
			else if (opptype == TANK)
			{
				if (belong->getCamp() != ((Tank*)p)->getCamp())
				{
					((Tank*)p)->reduceLife(power);
				}
			}
			else if (opptype == BULLET)
			{
				((Bullet*)p)->coll = true;
			}
			else if (opptype == BUFF)
			{
				buff = ((Buff*)p)->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					belong->addLife(false, 1);
					break;
				case SPEEDBUFF:
					belong->addSpeed(1);
					break;
				case POWERBUFF:
					belong->powerUp();
					break;
				case VOLUMEBUFF:
					belong->volumeUP();
					break;
				default:
					break;
				}
				map.map[y][x / 2 - 1] = nullptr;
				p->draw(false);
			}
			return true;
		}
		break;
	case RIGHT:
		if (map.map[y][x / 2 + 1])
		{
			p = map.map[y][x / 2 + 1];
			opptype = p->getType();
			if (opptype == WALL || power >= 2 && opptype == IRONWALL)
			{
				p->draw(false);
				map.map[y][x / 2 + 1] = nullptr;
			}
			else if (opptype == BASE)
			{
				if (belong->getCamp() == ENEMY)
				{
					active = false;
				}
			}
			else if (opptype == TANK)
			{
				if (belong->getCamp() != ((Tank*)p)->getCamp())
				{
					((Tank*)p)->reduceLife(power);
				}
			}
			else if (opptype == BULLET)
			{
				((Bullet*)p)->coll = true;
			}
			else if (opptype == BUFF)
			{
				buff = ((Buff*)p)->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					belong->addLife(false, 1);
					break;
				case SPEEDBUFF:
					belong->addSpeed(1);
					break;
				case POWERBUFF:
					belong->powerUp();
					break;
				case VOLUMEBUFF:
					belong->volumeUP();
					break;
				default:
					break;
				}
				map.map[y][x / 2 + 1] = nullptr;
				p->draw(false);
			}
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}
