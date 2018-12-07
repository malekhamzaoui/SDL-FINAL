
#ifndef __GameManager__
#define __GameManager__
#pragma once

#include "Player.h"
#include "Enemy.h"
#include "AnimatedGraphics.h"
#include "MenuButton.h"




class GameObject;
class InputHandler;
class GameStateMachine;


enum game_states {

		MENU=0,
		PLAY=1,
		GAMEOVER=2

};


class GameManager {

private :

	SDL_Window *g_pWindow;
	SDL_Renderer *g_pRenderer;
	

	int m_currentFrame;

	bool m_bRunning;
	

	std::vector<GameObject*>m_gameObject;

	static GameManager* s_pInstance; //instance static pour singelton

	//gamestate
	enum game_states m_currentGameState;


	GameStateMachine *m_pGameStateMachine;

	int m_gameWidth;
	int m_gameHeight;



	GameManager();



public:

	
	~GameManager();
	int init(char *title, int xpos, int ypos, int height, int width, int flag);
	void update();
	void render();
	void handleEvents();
	inline bool running() { return m_bRunning; }
	void setRunning(bool run);
	void clean();
	void draw();
	void quit();

	GameStateMachine *getStateMachine() { return m_pGameStateMachine; }

	//create the public instance function
	static GameManager* Instance(){
	
		if (s_pInstance == 0) {

			s_pInstance = new GameManager();

			return s_pInstance;
		}

		return s_pInstance;
	
	
	}

	SDL_Renderer *getRenderer()const { return g_pRenderer; }

	int getGameWidth() {
		return m_gameWidth;
	}

	int getGameHeight() {
		return m_gameHeight;
	}





};

//def du type TheGameManager sous type de GameManager
typedef GameManager TheGameManager;


#endif // !GameManager
