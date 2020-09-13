#include "Interface.h"

void Interface::boader()
{
    drawAtPoint(0, 0, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓", "");
    for (int i = 1; i < HEIGHT - 1; i++)
    {
        drawAtPoint(0, i, "〓", "");
        drawAtPoint(WIDTH - 2, i, "〓", "");
    }
    drawAtPoint(0, HEIGHT - 1, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓", "");
}

void Interface::menuface()
{
    string str = "mode con cols=" + to_string(WIDTH) + "lines=" + to_string(HEIGHT);
    system(str.c_str());
    SetConsoleTitle((LPCSTR)"BATTLE CITY");
    boader();
    drawAtPoint(12, 4, ".____      ._______._______._.    .______.    _____._____._________     __", "");
    drawAtPoint(12, 5, "|  _ \\   /\\|__. .__|__. .__| |    | .____|   / ____|_. ._|__. .__\\ \\   / /", "");
    drawAtPoint(12, 6, "| |_) | /  \\  | |     | |  | |    | |__.    | |      | |    | |   \\ \\_/ /", "");
    drawAtPoint(12, 7, "|  _ < / /\\ \\ | |     | |  | |    |  __|    | |      | |    | |    \\   /", "");
    drawAtPoint(12, 8, "| |_) / ____ \\| |     | |  | |____| |____.  | |____._| |_.  | |     | |", "");
    drawAtPoint(12, 9, "|____/_/    \\_\\_|     |_|  |______|______|   \\_____|_____|  |_|     |_|", "");
    drawAtPoint(42, 15, "Game Start", "");
    drawAtPoint(42, 17, "Mode Change", "");
    drawAtPoint(42, 19, "Exit", "");
    drawAtPoint(38, 15, "※", "");
}

void Interface::random(list<Tank*> &enemy, int &count)
{
    if (enemy.empty())
    {
        Tank* tank = new Tank(86, 2, ENEMY);
        enemy.push_back(tank);
        tank = new ArmoredCar(20, 2, ENEMY);
        enemy.push_back(tank);
        tank = new HeavyTank(50, 2, ENEMY);
        enemy.push_back(tank);
        if (mode == HARD)
        {
            tank = new DoubleTank(12, 2, ENEMY);
            enemy.push_back(tank);
            tank = new DoubleTank(76, 2, ENEMY);
            enemy.push_back(tank);
        }
    }
    
    list<Tank*>::iterator iter = enemy.begin();
    while (iter != enemy.end())
    {
        vector<Bullet*>::iterator bullet = (*iter)->bullets.begin();
        while (bullet != (*iter)->bullets.end())
        {
            int res = (*bullet)->run();
            if (res == -1 || (*bullet)->is_coll())
                bullet = (*iter)->bullets.erase(bullet);
            else
            {
                (*bullet)->draw(true);
                bullet++;
            }
        }

        if ((*iter)->getLife() <= 0)
        {
            if ((*iter)->bullets.size() <= 0)
            {
                iter = enemy.erase(iter);
                if (mode == EASY)
                {
                    if (--count <= 0)
                        return;
                }
                Tank* tank = nullptr;
                srand((unsigned)clock());
                int type = 0;
                if (mode == EASY || mode == NORMAL)
                    type = rand() % 3;
                else if (mode == HARD)
                {
                    type = rand() % 5;
                }
                short x = rand() % 46 + 2;
                while (map.map[2][x] || map.map[2][x - 1] || map.map[2][x + 1] || map.map[3][x - 1] || map.map[3][x] || map.map[3][x + 1])
                    x = rand() % 46 + 2;
                switch (type)
                {
                case 0:tank = new Tank(x * 2, 2, ENEMY); break;
                case 1:tank = new ArmoredCar(x * 2, 2, ENEMY); break;
                case 2:tank = new HeavyTank(x * 2, 2, ENEMY); break;
                case 3:tank = new DoubleTank(x * 2, 2, ENEMY); break;
                case 4:tank = new DoubleTank(x * 2, 2, ENEMY); break;
                default:
                    break;
                }
                enemy.push_back(tank);
            }
            else
                iter++;
        }
        else
        {
            srand((unsigned)clock());
            DIR flag = (DIR)(rand() % 50);
            if (flag >= 13 && flag <= 17 || flag >= 25 && flag <= 29)
            {
                DIR direct = (DIR)(flag % 4);
                (*iter)->move(direct);
            }
            (*iter)->draw(true);
            
            if (flag >= 3 && flag <= 6 && (*iter)->getLife())
                (*iter)->addBullet();
            iter++;
        }
    }
}

void Interface::status(list<Tank*> fri, list<Tank*> enemy, int &count)
{
    list<Tank*>::iterator iter;
    int i = 0;

    if (mode == EASY)
    {
        string num = to_string(count);
        drawAtPoint(110, 4, "Enemies", "");
        drawAtPoint(113, 5, num.c_str(), "");
    }
    
    for (iter = fri.begin(); iter != fri.end(); iter++)
    {
        string name = "Player " + to_string(i + 1);
        drawAtPoint(110, 23 + i * 3, name.c_str(), "");
        string item = "HP: " + to_string((*iter)->getLife());
        drawAtPoint(110, 23 + i * 3 + 1, item.c_str(), "");
        item = "Power: " + to_string((*iter)->getPower());
        drawAtPoint(110, 23 + i * 3 + 2, item.c_str(), "");
        item = "Speed: " + to_string((*iter)->getSpeed());
        drawAtPoint(110, 23 + i * 3 + 3, item.c_str(), "");
        item = "Volume: " + to_string((*iter)->getVolume());
        drawAtPoint(110, 23 + i * 3 + 4, item.c_str(), "");
        i++;
    }
    i = 0;
    for (iter = enemy.begin(); iter != enemy.end(); iter++)
    {
        string name = "Enemy " + to_string(i + 1);
        drawAtPoint(110, 7 + i * 3, name.c_str(), "");
        string life = "HP: " + to_string((*iter)->getLife());
        drawAtPoint(110, 7 + i * 3 + 1, life.c_str(), "");
        i++;
    }
}

void Interface::buff()
{
    int a;
    srand((unsigned)clock());
    if (rand() % 9000 >= 30 && rand() % 9000 <= 40)
    {
        short x = rand() % 48 + 1;
        short y = rand() % 34 + 1;
        BUFFTYPE type = BUFFTYPE(rand() % 4 + LIFEBUFF);
        if (!map.map[y][x])
        {
            map.map[y][x] = new Buff(x * 2, y, BUFF, type);
            map.map[y][x]->draw(true);
            a = 0;
        }
    }
}

void Interface::win()
{
    string str = "mode con cols=" + to_string(WIDTH) + "lines=" + to_string(HEIGHT);
    system(str.c_str());
    system("cls");
    boader();
    short x = 22;
    short y = 10;
    for (int i = 0; i < 3; i++)
    {
        drawAtPoint(x, y + 0, "__     ______  _    _  __          _______._   _   _", "");
        drawAtPoint(x, y + 1, "\\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | | |", "");
        drawAtPoint(x, y + 2, " \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | | |", "");
        drawAtPoint(x, y + 3, "  \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | | |", "");
        drawAtPoint(x, y + 4, "   | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  | |_|", "");
        drawAtPoint(x, y + 5, "   |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_| (_)", "");
        Sleep(500);
        drawAtPoint(x, y + 0, "                                                     ", "");
        drawAtPoint(x, y + 1, "                                                     ", "");
        drawAtPoint(x, y + 2, "                                                     ", "");
        drawAtPoint(x, y + 3, "                                                     ", "");
        drawAtPoint(x, y + 4, "                                                     ", "");
        drawAtPoint(x, y + 5, "                                                     ", "");
        Sleep(500);
    }
    drawAtPoint(x, y + 0, "__     ______  _    _  __          _______._   _   _", "");
    drawAtPoint(x, y + 1, "\\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | | |", "");
    drawAtPoint(x, y + 2, " \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | | |", "");
    drawAtPoint(x, y + 3, "  \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | | |", "");
    drawAtPoint(x, y + 4, "   | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  | |_|", "");
    drawAtPoint(x, y + 5, "   |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_| (_)", "");
    drawAtPoint(x + 20, y + 10, "", "");
    system("pause");
}

void Interface::gameover()
{
    string str = "mode con cols=" + to_string(WIDTH) + "lines=" + to_string(HEIGHT);
    system(str.c_str());
    system("cls");
    boader();
    short x = 18;
    short y = 10;
    for (int i = 0; i < 3; i++)
    {
        drawAtPoint(x, y + 0, "  _____.        .__  __.______.   ______      ________._____", "");
        drawAtPoint(x, y + 1, " / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\", "");
        drawAtPoint(x, y + 2, "| | .__.  /  \\  | \\  / | |__.   | |  | \\ \\  / /| |__  | |__) |", "");
        drawAtPoint(x, y + 3, "| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /", "");
        drawAtPoint(x, y + 4, "| |__| |/ ____ \\| |  | | |____. | |__| | \\  /  | |____| | \\ \\", "");
        drawAtPoint(x, y + 5, " \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\", "");
        Sleep(500);
        drawAtPoint(x, y + 0, "                                                              ", "");
        drawAtPoint(x, y + 1, "                                                              ", "");
        drawAtPoint(x, y + 2, "                                                              ", "");
        drawAtPoint(x, y + 3, "                                                              ", "");
        drawAtPoint(x, y + 4, "                                                              ", "");
        drawAtPoint(x, y + 5, "                                                              ", "");
        Sleep(500);
    }
    drawAtPoint(x, y + 0, "  _____.        .__  __.______.   ______      ________._____", "");
    drawAtPoint(x, y + 1, " / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\", "");
    drawAtPoint(x, y + 2, "| | .__.  /  \\  | \\  / | |__.   | |  | \\ \\  / /| |__  | |__) |", "");
    drawAtPoint(x, y + 3, "| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /", "");
    drawAtPoint(x, y + 4, "| |__| |/ ____ \\| |  | | |____. | |__| | \\  /  | |____| | \\ \\", "");
    drawAtPoint(x, y + 5, " \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\", "");
    Sleep(500);

    str = "Your score is " + to_string(score);
    drawAtPoint(x + 22, y + 8, str.c_str(), "");
    drawAtPoint(x + 22, y + 10, "", "");
    system("pause");
}

void Interface::setting()
{
    string str = "mode con cols=" + to_string(WIDTH) + "lines=" + to_string(HEIGHT);
    system(str.c_str());
    system("cls");
    boader();
    short x = 24;
    short y = 4;
    drawAtPoint(x, y + 0, "  _____.______._______._______._____._  ._. _____.", "");
    drawAtPoint(x, y + 1, " / ____| .____|__. .__|__. .__|_. ._| \\ | |/ ____|", "");
    drawAtPoint(x, y + 2, "| (___ | |__.    | |     | |    | | |  \\| | |  __.", "");
    drawAtPoint(x, y + 3, " \\___ \\| .__|    | |     | |    | | | . ` | | |_ |", "");
    drawAtPoint(x, y + 4, ".____) | |____.  | |     | |  ._| |_| |\\  | |__| |", "");
    drawAtPoint(x, y + 5, "|_____/|______|  |_|     |_|  |_____|_| \\_|\\_____|", "");
    drawAtPoint(46, y + 11, "Easy", "");
    drawAtPoint(46, y + 13, "Normal", "");
    drawAtPoint(46, y + 15, "Hard", "");
    drawAtPoint(42, y + 11, "※", "");

    int choice = 0;

    int ch1, ch2;
    while (1)
    {
        string str;
        Sleep(50);
        if (_kbhit())
        {
            ch1 = _getch();
            switch (ch1)
            {
            case 224:
                ch2 = _getch();
                switch (ch2)
                {
                case 72:
                    drawAtPoint(42, y + 11 + choice * 2, "  ", "");
                    if (choice > 0)
                        choice--;
                    drawAtPoint(42, y + 11 + choice * 2, "※", "");
                    break;
                case 80:
                    drawAtPoint(42, y + 11 + choice * 2, "  ", "");
                    if (choice < 2)
                        choice++;
                    drawAtPoint(42, y + 11 + choice * 2, "※", "");
                    break;
                default:
                    break;
                }
                break;
            case 13:
            case 108:
                switch (choice)
                {
                case 0:
                    mode = EASY;
                    break;
                case 1:
                    mode = NORMAL;
                    break;
                case 2:
                    mode = HARD;
                default:
                    break;
                }
                return;
            default:
                //cout << ch1 << " ";
                break;
            }
        }
    }
}

int Interface::run()
{
    int ch, ch2;
    bool run = true;
    boader();
    map = {};
    map.createWall();
    list<Tank*> enemy;
    list<Tank*> friendly;
    int count = 15;
    
    Tank test(20, 33, SELF);
    friendly.push_back(&test);

    drawAtPoint(104, 30, "◎", RED);
    drawAtPoint(107, 30, "Add Life (up to 10)", "");
    drawAtPoint(104, 31, "◎", YELLOW);
    drawAtPoint(107, 31, "Add Power (up to 5)", "");
    drawAtPoint(104, 32, "◎", BLUE);
    drawAtPoint(107, 32, "Add Speed (up to 4)", "");
    drawAtPoint(104, 33, "◎", GREEN);
    drawAtPoint(107, 33, "Add Volume (up to 10)", "");
    
    while (run)
    {
        if (!active)
        {
            gameover();
            break;
        }
        Sleep(50);
        random(enemy, count);
        if (count <= 0)
        {
            win();
            break;
        }
        buff();
        if (_kbhit())
        {
            ch = _getch();
            switch (ch)
            {
            case 224:
                ch2 = _getch();
                switch (ch2)
                {
                case 72:test.move(UP); break;
                case 80:test.move(DOWN); break;
                case 75:test.move(LEFT); break;
                case 77:test.move(RIGHT); break;
                default:
                    break;
                }
                break;
            case 27:run = false; break;
            case 32:
                if (test.getLife())
                    test.addBullet();
                break;
            case 13:
            case 108:
            {
                bool pause = true;
                int temp;
                while (pause)
                {
                    if (_kbhit())
                    {
                        temp= _getch();
                        if (temp == 13 || temp == 108)
                            break;
                    }
                }
            }
            break;
            default:
                //cout << ch << " ";
                break;
            }
        }
        
        

        if (test.getLife())
            test.draw(true);
        
        vector<Bullet*>::iterator iter = test.bullets.begin();
        while (iter != test.bullets.end())
        {
            int res = (*iter)->run();
            if (res == -1 || (*iter)->is_coll())
                iter = test.bullets.erase(iter);
            else
            {
                (*iter)->draw(true);
                iter++;
            }
        }

        status(friendly, enemy, count);


#ifdef DEBUG
        TEST
#endif
        
    }
    return 0;
}

int Interface::menu()
{
    menuface();
    int choice = 0;
    int ch1, ch2;
    while (1)
    {
        string str;
        Sleep(50);
        if (_kbhit())
        {
            ch1 = _getch();
            switch (ch1)
            {
            case 224:
                ch2 = _getch();
                switch (ch2)
                {
                case 72:
                    drawAtPoint(38, 15 + choice * 2, "  ", "");
                    if (choice > 0)
                        choice--;
                    drawAtPoint(38, 15 + choice * 2, "※", "");
                    break;
                case 80:
                    drawAtPoint(38, 15 + choice * 2, "  ", "");
                    if (choice < 2)
                        choice++;
                    drawAtPoint(38, 15 + choice * 2, "※", "");
                    break;
                default:
                    break;
                }
                break;
            case 13:
            case 108:
                switch (choice)
                {
                case 0:
                    system("cls");
                    str = "mode con cols=" + to_string(WIDTH + 30) + "lines=" + to_string(HEIGHT);
                    system(str.c_str());
                    drawAtPoint(0, 0, "", "");
                    active = true;
                    SetConsoleTitle((LPCSTR)"SCORE: 0");
                    run();
                    system("cls");
                    menuface();
                    mode = EASY;
                    break;
                case 1:
                    setting();
                    menuface();
                    choice = 0;
                    break;
                case 2:return 0;
                default:
                    break;
                }
            default:
                //cout << ch1 << " ";
                break;
            }
        }
    }
    return 0;
}
