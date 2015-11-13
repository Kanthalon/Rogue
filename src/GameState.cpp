/**
* Provides the Rogue GameState example in the GQE library.
*
* @file src/GameState.cpp
* @author Ryan Lindeman
* @date 20110704 - Initial Release
* @date 20110721 - Remove * from GetAsset() calls since it now returns TYPE&
* @date 20110831 - Support new SFML2 snapshot changes
* @date 20120421 - Use arial.ttf font since SFML 2 crashes on exit when using default font
*/
#include "GameState.hpp"
#include <GQE/Core/interfaces/IApp.hpp>

GameState::GameState(GQE::IApp& theApp) :
GQE::IState("Game",theApp),
	mBackground("resources/Board.png", GQE::AssetLoadNow),
	mPlayer("resources/Player.png", GQE::AssetLoadNow),
	mB("resources/Empty.png", GQE::AssetLoadNow)
{
	map[2][3] = 1;
	map[5][3] = 1;
	map[0][4] = 1;
	map[1][4] = 1;
	map[2][4] = 1;
	map[3][4] = 1;
	map[4][4] = 1;
	map[5][4] = 1;
	map[6][4] = 1;
	map[7][4] = 1;
}

GameState::~GameState(void)
{
}

void GameState::DoInit(void)
{
	// First call our base class implementation
	IState::DoInit();

	mBackgroundSprite.setTexture(mBackground.GetAsset());
	for (int i = 0; i < MAP_X; i++)
	{
		for (int j = 0; j < MAP_Y; j++)
		{
			if (map[i][j] == 1)
			{
				mBlock[i][j] = Block(1, i*50, j*50);
			}
			else
			{
				mBlock[i][j] = Block(0, i*50, j*50);
			}
		}
	}
	// Call ReInit to reset the board
	ReInit();

	// Make sure our update loop is only called 30 times per second
	mApp.SetUpdateRate(30.0f);
}

void GameState::ReInit(void)
{

	mCursor.setTexture(mPlayer.GetAsset());

	// Set Cursor scale to be 25% of original image
	mCursor.setScale(0.25f, 0.25f);


}

void GameState::HandleEvents(sf::Event theEvent)
{
	// Exit program if Escape key is pressed
	if((theEvent.type == sf::Event::KeyReleased) && (theEvent.key.code == sf::Keyboard::Escape))
	{
		// Signal the application to exit
		mApp.Quit(GQE::StatusAppOK);
	}
}

void GameState::UpdateFixed(void)
{

}

void GameState::UpdateVariable(float theElapsedTime)
{
	// Draw the current player image at the mouse position
	mCursor.setPosition(sf::Mouse::getPosition(mApp.mWindow).x-32.0f,
		sf::Mouse::getPosition(mApp.mWindow).y-25.25f);
}

void GameState::Draw(void)
{
	mApp.mWindow.draw(mBackgroundSprite);
	for (int i = 0; i < MAP_X; i++)
	{
		for (int j = 0; j < MAP_Y; j++)
		{
			mApp.mWindow.draw(mBlock[i][j].getSprite());
		}
	}
	// Draw our cursor
	mApp.mWindow.draw(mCursor);
}

void GameState::HandleCleanup(void)
{
}

/**
* Copyright (c) 2010-2011 Ryan Lindeman
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
