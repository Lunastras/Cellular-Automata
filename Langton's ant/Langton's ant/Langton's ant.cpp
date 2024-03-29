

#include "pch.h"
#include <iostream>
#include "olcConsoleGameEngine.h"

using namespace std;

int inX = 50;
int inY = 50;
char dir = 'w';

class Langtons_ant : public olcConsoleGameEngine
{
public:
	Langtons_ant() 
	{
		m_sAppName = L"Langton's Ant";
	}

private:
	int *m_output;
	int *m_state;


protected:

	virtual bool OnUserCreate() 
	{
		m_output = new int[ScreenWidth() * ScreenHeight()];
		m_state = new int[ScreenWidth() * ScreenHeight()];
	
		memset(m_output, -1, ScreenWidth() * ScreenHeight() * sizeof(int));
		
		//for (int i = 0; i < ScreenWidth()*ScreenHeight(); i++)
			//m_output[i] = rand() % 2;
		
		return 1;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		
		auto cell = [&](int x, int y)
		{
			return m_output[y * ScreenWidth() + x];
		};

		
		
		

			if (cell(inX, inY) == 0)
			{
				m_output[inY*ScreenWidth() + inX] = 1;

				if (dir == 'n')
				{
					inX++;
					dir = 'e';
				}
				else
				if (dir == 's')
				{
					inX--;
					dir = 'w';
				}
				else
				if (dir == 'e')
				{
					inY++;
					dir = 's';
				}
				else
				if (dir == 'w')
				{
					inY--;
					dir = 'n';
				}


			}
			else 
			{
				m_output[inY*ScreenWidth() + inX] = 0;


				if (dir == 'n')
				{
					inX--;
					dir = 'w';
				}
				else
				if (dir == 's')
				{
					inX++;
					dir = 'e';
				}
				else
				if (dir == 'e')
				{
					inY--;
					dir = 'n';
				}
				else
				if (dir == 'w')
				{
					inY++;
					dir = 's';
				}

				

			}

			

			

		for(int x = 0; x < ScreenWidth() ; x++)
			for (int y = 0; y < ScreenWidth(); y++)
			{
				

				if (cell(x, y) == 1)
					Draw(x, y, PIXEL_SOLID, FG_WHITE);

				else
					Draw(x, y, PIXEL_SOLID, FG_BLACK);

			}

	
		return 1;
	}
};

int main()
{
	Langtons_ant game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();
	cout << dir << endl;

	return 0;
}

