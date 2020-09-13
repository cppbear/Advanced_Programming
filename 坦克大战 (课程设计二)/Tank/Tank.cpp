#include "Tank.h"
#include "Buff.h"

void Tank::changeDirect(DIR dir)
{
	direct = dir;
	for (int i = y - 1; i <= y + 1; i++)
		for (int j = (x - 2) / 2; j <= (x + 2) / 2; j++)
			map.map[i][j] = this;
	switch (dir)
	{
	case UP:
		map.map[y - 1][(x - 2) / 2] = map.map[y - 1][(x + 2) / 2] = nullptr;
		break;
	case DOWN:
		map.map[y + 1][(x - 2) / 2] = map.map[y + 1][(x + 2) /2] = nullptr;
		break;
	case LEFT:
		map.map[y - 1][(x - 2) / 2] = map.map[y + 1][(x - 2) / 2] = nullptr;
		break;
	case RIGHT:
		map.map[y - 1][(x + 2) / 2] = map.map[y + 1][(x + 2) / 2] = nullptr;
		break;
	default:
		break;
	}
}

void Tank::move(DIR dir)
{
	if (life <= 0)
		return;
	draw(false);
	if (direct != dir)
	{
		//changeDirect(dir);
		
		if (!collisionTurn())
		{
			changeDirect(dir);
		}
		
	}
	else
	{
		for (int i = 0; i < speed; i++)
		{
			if (collisionForward(dir))
				return;
			switch (dir)
			{
			case UP:
				if (y > 2)
				{
					map.map[y + 1][x / 2 - 1] = map.map[y + 1][x / 2] = map.map[y + 1][x / 2 + 1] = nullptr;
					y -= 1;
					map.map[y - 1][x / 2] = map.map[y][x / 2 - 1] = map.map[y][x / 2 + 1] = this;
				}
				break;
			case DOWN:
				if (y < HEIGHT - 3)
				{
					map.map[y - 1][x / 2 - 1] = map.map[y - 1][x / 2] = map.map[y - 1][x / 2 + 1] = nullptr;
					y += 1;
					map.map[y + 1][x / 2] = map.map[y][x / 2 - 1] = map.map[y][x / 2 + 1] = this;
				}
				break;
			case LEFT:
				if (x > 4)
				{
					map.map[y - 1][x / 2 + 1] = map.map[y][x / 2 + 1] = map.map[y + 1][x / 2 + 1] = nullptr;
					x -= 2;
					map.map[y][x / 2 - 1] = map.map[y - 1][x / 2] = map.map[y + 1][x / 2] = this;
				}
				break;
			case RIGHT:
				if (x < WIDTH - 6)
				{
					map.map[y - 1][x / 2 - 1] = map.map[y][x / 2 - 1] = map.map[y + 1][x / 2 - 1] = nullptr;
					x += 2;
					map.map[y][x / 2 + 1] = map.map[y - 1][x / 2] = map.map[y + 1][x / 2] = this;
				}
				break;
			default:
				break;
			}
		}
	}
}

void Tank::draw(bool filling)
{
	if (filling)
	{
		const char* color = camp == ENEMY ? MAGENTA : CYAN;
		switch (direct)
		{
		case UP:
			drawAtPoint(x, y - 1, "■", color);
			drawAtPoint(x - 2, y, "■■■", color);
			drawAtPoint(x - 2, y + 1, "■●■", color);
			break;
		case DOWN:
			drawAtPoint(x - 2, y - 1, "■●■", color);
			drawAtPoint(x - 2, y, "■■■", color);
			drawAtPoint(x, y + 1, "■", color);
			break;
		case LEFT:
			drawAtPoint(x, y - 1, "■■", color);
			drawAtPoint(x - 2, y, "■■●", color);
			drawAtPoint(x, y + 1, "■■", color);
			break;
		case RIGHT:
			drawAtPoint(x - 2, y - 1, "■■", color);
			drawAtPoint(x - 2, y, "●■■", color);
			drawAtPoint(x - 2, y + 1, "■■", color);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (direct)
		{
		case UP:
			drawAtPoint(x, y - 1, "  ", "");
			drawAtPoint(x - 2, y, "      ", "");
			drawAtPoint(x - 2, y + 1, "      ", "");
			break;
		case DOWN:
			drawAtPoint(x - 2, y - 1, "      ", "");
			drawAtPoint(x - 2, y, "      ", "");
			drawAtPoint(x, y + 1, "  ", "");
			break;
		case LEFT:
			drawAtPoint(x, y - 1, "    ", "");
			drawAtPoint(x - 2, y, "      ", "");
			drawAtPoint(x, y + 1, "    ", "");
			break;
		case RIGHT:
			drawAtPoint(x - 2, y - 1, "    ", "");
			drawAtPoint(x - 2, y, "      ", "");
			drawAtPoint(x - 2, y + 1, "    ", "");
			break;
		default:
			break;
		}
	}
}

void DoubleTank::draw(bool filling)
{
	if (filling)
	{
		const char* color = camp == ENEMY ? MAGENTA : CYAN;
		switch (direct)
		{
		case UP:
			drawAtPoint(x - 2, y - 1, "■  ■", color);
			drawAtPoint(x - 2, y, "■●■", color);
			drawAtPoint(x - 2, y + 1, "■■■", color);
			break;
		case DOWN:
			drawAtPoint(x - 2, y - 1, "■■■", color);
			drawAtPoint(x - 2, y, "■●■", color);
			drawAtPoint(x - 2, y + 1, "■  ■", color);
			break;
		case LEFT:
			drawAtPoint(x - 2, y - 1, "■■■", color);
			drawAtPoint(x, y, "●■", color);
			drawAtPoint(x - 2, y + 1, "■■■", color);
			break;
		case RIGHT:
			drawAtPoint(x - 2, y - 1, "■■■", color);
			drawAtPoint(x - 2, y, "■●", color);
			drawAtPoint(x - 2, y + 1, "■■■", color);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (direct)
		{
		case UP:
			drawAtPoint(x - 2, y - 1, "      ", "");
			drawAtPoint(x - 2, y, "      ", "");
			drawAtPoint(x - 2, y + 1, "      ", "");
			break;
		case DOWN:
			drawAtPoint(x - 2, y - 1, "      ", "");
			drawAtPoint(x - 2, y, "      ", "");
			drawAtPoint(x - 2, y + 1, "      ", "");
			break;
		case LEFT:
			drawAtPoint(x - 2, y - 1, "      ", "");
			drawAtPoint(x, y, "    ", "");
			drawAtPoint(x - 2, y + 1, "      ", "");
			break;
		case RIGHT:
			drawAtPoint(x - 2, y - 1, "      ", "");
			drawAtPoint(x - 2, y, "    ", "");
			drawAtPoint(x - 2, y + 1, "      ", "");
			break;
		default:
			break;
		}
	}
}

void Tank::addBullet()
{
	if (bullets.size() < volume)
	{
		Bullet* bullet = new Bullet(x, y, direct, this, power);
		bullets.push_back(bullet);
	}
}

void DoubleTank::addBullet()
{
	if (bullets.size() < 10)
	{
		switch (direct)
		{
		case UP:
		case DOWN:
		{
			Bullet* bullet = new Bullet(x - 2, y, direct, this, power);
			bullets.push_back(bullet);
			bullet = new Bullet(x + 2, y, direct, this, power);
			bullets.push_back(bullet);
		}
		break;
		case LEFT:
		case RIGHT:
		{
			Bullet* bullet = new Bullet(x, y - 1, direct, this, power);
			bullets.push_back(bullet);
			bullet = new Bullet(x, y + 1, direct, this, power);
			bullets.push_back(bullet);
		}
		default:
			break;
		}
	}
}

bool Tank::collisionTurn()
{
	if (map.map[y - 1][(x - 2) / 2] && (map.map[y - 1][(x - 2) / 2]->getType() == WALL || map.map[y - 1][(x - 2) / 2]->getType() == IRONWALL)
		||
		map.map[y - 1][(x + 2) / 2] && (map.map[y - 1][(x + 2) / 2]->getType() == WALL || map.map[y - 1][(x + 2) / 2]->getType() == IRONWALL)
		||
		map.map[y + 1][(x - 2) / 2] && (map.map[y + 1][(x - 2) / 2]->getType() == WALL || map.map[y + 1][(x - 2) / 2]->getType() == IRONWALL)
		||
		map.map[y + 1][(x + 2) / 2] && (map.map[y + 1][(x + 2) / 2]->getType() == WALL || map.map[y + 1][(x + 2) / 2]->getType() == IRONWALL))
		return true;
	else
	{
		BUFFTYPE buff;
		if (map.map[y - 1][(x - 2) / 2] && map.map[y - 1][(x - 2) / 2]->getType() == BUFF)
		{
			buff = ((Buff*)map.map[y - 1][(x - 2) / 2])->getBuff();
			switch (buff)
			{
			case LIFEBUFF:
				addLife(false, 1);
				break;
			case SPEEDBUFF:
				addSpeed(1);
				break;
			case POWERBUFF:
				powerUp();
				break;
			case VOLUMEBUFF:
				volumeUP();
				break;
			default:
				break;
			}
			map.map[y - 1][(x - 2) / 2]->draw(false);
			map.map[y - 1][(x - 2) / 2] = nullptr;
		}
		if (map.map[y - 1][(x + 2) / 2] && map.map[y - 1][(x + 2) / 2]->getType() == BUFF)
		{
			buff = ((Buff*)map.map[y - 1][(x + 2) / 2])->getBuff();
			switch (buff)
			{
			case LIFEBUFF:
				addLife(false, 1);
				break;
			case SPEEDBUFF:
				addSpeed(1);
				break;
			case POWERBUFF:
				powerUp();
				break;
			case VOLUMEBUFF:
				volumeUP();
				break;
			default:
				break;
			}
			map.map[y - 1][(x + 2) / 2]->draw(false);
			map.map[y - 1][(x + 2) / 2] = nullptr;
		}
		if (map.map[y + 1][(x - 2) / 2] && map.map[y + 1][(x - 2) / 2]->getType() == BUFF)
		{
			buff = ((Buff*)map.map[y + 1][(x - 2) / 2])->getBuff();
			switch (buff)
			{
			case LIFEBUFF:
				addLife(false, 1);
				break;
			case SPEEDBUFF:
				addSpeed(1);
				break;
			case POWERBUFF:
				powerUp();
				break;
			case VOLUMEBUFF:
				volumeUP();
				break;
			default:
				break;
			}
			map.map[y + 1][(x - 2) / 2]->draw(false);
			map.map[y + 1][(x - 2) / 2] = nullptr;
		}
		if (map.map[y + 1][(x + 2) / 2] && map.map[y + 1][(x + 2) / 2]->getType() == BUFF)
		{
			buff = ((Buff*)map.map[y + 1][(x + 2) / 2])->getBuff();
			switch (buff)
			{
			case LIFEBUFF:
				addLife(false, 1);
				break;
			case SPEEDBUFF:
				addSpeed(1);
				break;
			case POWERBUFF:
				powerUp();
				break;
			case VOLUMEBUFF:
				volumeUP();
				break;
			default:
				break;
			}
			map.map[y + 1][(x + 2) / 2]->draw(false);
			map.map[y + 1][(x + 2) / 2] = nullptr;
		}
	}
	return false;
}

bool Tank::collisionForward(DIR dir)
{
	BUFFTYPE buff;
	switch (dir)
	{
	case UP:
		if (map.map[y - 2][x / 2] && map.map[y - 2][x / 2]->getType() != BUFF
			||
			map.map[y - 2][(x - 2) / 2] && map.map[y - 2][(x - 2) / 2]->getType() != BUFF
			||
			map.map[y - 2][(x + 2) / 2] && map.map[y - 2][(x + 2) / 2]->getType() != BUFF)
			return true;
		else
		{
			if (map.map[y - 2][x / 2] && map.map[y - 2][x / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y - 2][x / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y - 2][x / 2]->draw(false);
				map.map[y - 2][x / 2] = nullptr;
			}
			if (map.map[y - 1][(x - 2) / 2] && map.map[y - 1][(x - 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y - 1][(x - 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y - 1][(x - 2) / 2]->draw(false);
				map.map[y - 1][(x - 2) / 2] = nullptr;
			}
			if (map.map[y - 1][(x + 2) / 2] && map.map[y - 1][(x + 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y - 1][(x + 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y - 1][(x + 2) / 2]->draw(false);
				map.map[y - 1][(x + 2) / 2] = nullptr;
			}
		}
		break;
	case DOWN:
		if (map.map[y + 2][x / 2] && map.map[y + 2][x / 2]->getType() != BUFF
			||
			map.map[y + 2][(x - 2) / 2] && map.map[y + 2][(x - 2) / 2]->getType() != BUFF
			||
			map.map[y + 2][(x + 2) / 2] && map.map[y + 2][(x + 2) / 2]->getType() != BUFF)
			return true;
		else
		{
			if (map.map[y + 2][x / 2] && map.map[y + 2][x / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y + 2][x / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y + 2][x / 2]->draw(false);
				map.map[y + 2][x / 2] = nullptr;
			}
			if (map.map[y + 1][(x - 2) / 2] && map.map[y + 1][(x - 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y + 1][(x - 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y + 1][(x - 2) / 2]->draw(false);
				map.map[y + 1][(x - 2) / 2] = nullptr;
			}
			if (map.map[y + 1][(x + 2) / 2] && map.map[y + 1][(x + 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y + 1][(x + 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y + 1][(x + 2) / 2]->draw(false);
				map.map[y + 1][(x + 2) / 2] = nullptr;
			}
		}
		break;
	case LEFT:
		if (map.map[y - 1][(x - 4) / 2] && map.map[y - 1][(x - 4) / 2]->getType() != BUFF
			||
			map.map[y][(x - 4) / 2] && map.map[y][(x - 4) / 2]->getType() != BUFF
			||
			map.map[y + 1][(x - 4) / 2] && map.map[y + 1][(x - 4) / 2]->getType() != BUFF)
			return true;
		else
		{
			if (map.map[y - 1][(x - 2) / 2] && map.map[y - 1][(x - 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y - 1][(x - 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y - 1][(x - 2) / 2]->draw(false);
				map.map[y - 1][(x - 2) / 2] = nullptr;
			}
			if (map.map[y][(x - 4) / 2] && map.map[y][(x - 4) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y][(x - 4) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y][(x - 4) / 2]->draw(false);
				map.map[y][(x - 4) / 2] = nullptr;
			}
			if (map.map[y + 1][(x - 2) / 2] && map.map[y + 1][(x - 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y + 1][(x - 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y + 1][(x - 2) / 2]->draw(false);
				map.map[y + 1][(x - 2) / 2] = nullptr;
			}
		}
		break;
	case RIGHT:
		if (map.map[y - 1][(x + 4) / 2] && map.map[y - 1][(x + 4) / 2]->getType() != BUFF
			||
			map.map[y][(x + 4) / 2] && map.map[y][(x + 4) / 2]->getType() != BUFF
			||
			map.map[y + 1][(x + 4) / 2] && map.map[y + 1][(x + 4) / 2]->getType() != BUFF)
			return true;
		else
		{
			if (map.map[y - 1][(x + 2) / 2] && map.map[y - 1][(x + 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y - 1][(x + 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y - 1][(x + 2) / 2]->draw(false);
				map.map[y - 1][(x + 2) / 2] = nullptr;
			}
			if (map.map[y][(x + 4) / 2] && map.map[y][(x + 4) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y][(x + 4) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y][(x + 4) / 2]->draw(false);
				map.map[y][(x + 4) / 2] = nullptr;
			}
			if (map.map[y + 1][(x + 2) / 2] && map.map[y + 1][(x + 2) / 2]->getType() == BUFF)
			{
				buff = ((Buff*)map.map[y + 1][(x + 2) / 2])->getBuff();
				switch (buff)
				{
				case LIFEBUFF:
					addLife(false, 1);
					break;
				case SPEEDBUFF:
					addSpeed(1);
					break;
				case POWERBUFF:
					powerUp();
					break;
				case VOLUMEBUFF:
					volumeUP();
					break;
				default:
					break;
				}
				map.map[y + 1][(x + 2) / 2]->draw(false);
				map.map[y + 1][(x + 2) / 2] = nullptr;
			}
		}
		break;
	default:
		break;
	}
	return false;
}

bool Tank::reduceLife(short damage)
{
	life -= damage;
	if (life <= 0)
	{
		if (camp == ENEMY)
		{
			score++;
			string str = "SCORE: " + to_string(score);
			SetConsoleTitle((LPCSTR)str.c_str());
		}
		if (camp == SELF)
		{
			active = false;
		}
		life = 0;
		for (int i = y - 1; i <= y + 1; i++)
		{
			for (int j = x / 2 - 1; j <= x / 2 + 1; j++)
			{
				if (map.map[i][j])
					map.map[i][j] = nullptr;
			}
		}
		draw(false);
		return true;
	}
	return false;
}

void Tank::addLife(bool force, short val)
{
	if (force)
		life += val;
	else if (life > 0 && life < 10)
		life += val;
}

void Tank::addSpeed(short val)
{
	if (life > 0 && speed < 4)
		speed += val;
}

void Tank::powerUp()
{
	if (life > 0 && power < 5)
		power++;
}

void Tank::volumeUP()
{
	if (life > 0 && volume < 10)
		volume++;
}
