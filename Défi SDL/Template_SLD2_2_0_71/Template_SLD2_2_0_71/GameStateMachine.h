#ifndef __GameStateMachine__
#define __GameStateMachine__
#pragma once

#include "GameState.h"
#include "define.h"

class GameStateMachine{


public :

	void pushState(GameState *pState);
	void changeState(GameState *pState);
	void popState();
	void update();
	void render();


private :

	std::vector<GameState*>m_gameStates;



};

#endif
