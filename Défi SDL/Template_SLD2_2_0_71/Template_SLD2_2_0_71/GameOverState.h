
#ifndef __GameOverState__
#define __GameOverState__
#pragma once


#include "GameObject.h"
#include "MenuState.h"

//class GameOverState : public GameState {
class GameOverState : public MenuState{

public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const {
		return s_gameOverID;
	}
	


private:

	static const std::string s_gameOverID;

	std::vector<GameObject*>m_gameObjects;

	//callback which button was clicked
	static void s_gameOverToMain();
	static void s_restartPlay();

	virtual void setCallbacks(const std::vector<callback>&callbacks);




};

#endif