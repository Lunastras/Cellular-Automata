#include "pch.h"
#include "olcConsoleGameEngine.h"
#include <iostream>

using namespace std;

class OneLoneCoder_GameOfLife : public olcConsoleGameEngine
{

public:
	OneLoneCoder_GameOfLife() {
		m_sAppName = L"Game Of Life";
	}

private:
	int *m_output;
	int *m_state;

protected:

	virtual bool OnUserCreate()
	{
		m_output = new int[ScreenWidth() * ScreenHeight()];
		m_state = new int[ScreenWidth() * ScreenHeight()];
		memset(m_output, 0, ScreenWidth() * ScreenHeight() * sizeof(int));
		memset(m_state, 0, ScreenWidth() * ScreenHeight() * sizeof(int));
		

		for (int i = 0; i < ScreenWidth()*ScreenHeight(); i++)
			m_state[i] = rand() % 2;

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		auto cell = [&](int x, int y)
		{
			return m_output[y * ScreenWidth() + x];
		};

		for (int i = 0; i < ScreenWidth() * ScreenHeight(); i++)
			m_output[i] = m_state[i];

		for (int x = 1; x < ScreenWidth() - 1; x++)
			for (int y = 1; y < ScreenHeight() - 1; y++)
			{
				int nNeighbours = cell(x - 1, y - 1) + cell(x - 0, y - 1) +
					cell(x + 1, y - 1) + cell(x - 1, y - 0) +
					cell(x + 1, y - 0) + cell(x - 1, y + 1) +
					cell(x - 0, y + 1) + cell(x + 1, y + 1);

				if (cell(x, y) == 1)
					m_state[y*ScreenWidth() + x] = nNeighbours == 2 || nNeighbours == 3;
				else m_state[y*ScreenWidth() + x] = nNeighbours == 3;

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
		OneLoneCoder_GameOfLife game;
		game.ConstructConsole(160, 100, 8, 8);
		game.Start();

		return 0;
	}

