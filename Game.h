#ifndef _GAME_H
#define _GAME_H


#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameState;

class Game
{
public:
	enum States {MAIN_MENU, HIGHSCORES, GAMEPLAY, GAME_OVER};
	
	Game();
	~Game();

	sf::RenderWindow* getWindow() { return &window; }

	void run();
	static const sf::Time timePerFrame;
	void changeState(States nextState, unsigned score = 0);

private:
	bool gameRunning;
	sf::RenderWindow window;
	
	GameState* currentState;

	void handleEvents();
	void update(sf::Time dt);
	void render();
	void gameOver();
};

#endif