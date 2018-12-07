#include "GameOverState.h"
#include "GameManager.h"
#include "MenuButton.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "AnimatedGraphics.h"
#include "InputHandler.h"
#include "StateParser.h"


const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	if (!m_gameObjects.empty()) {
		for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
			m_gameObjects[i]->update();
		}
	}
}

void GameOverState::render()
{
	if (!m_gameObjects.empty()) {
		for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
			m_gameObjects[i]->draw();
		}
	}
}

bool GameOverState::onEnter()
{
	/*if (!TheTextureManager::Instance()->load("assets/gameover.png", "gameovertext", TheGameManager::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png", "mainButton", TheGameManager::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/restart.png", "restartButton", TheGameManager::Instance()->getRenderer()))
	{
		return false;
	}*/


	/*GameObject *gameOverText = new AnimatedGraphics(new LoaderParams((1024 / 2) - 85, 100, 190, 30, "gameovertext",1),2);
	
	m_gameObjects.push_back(gameOverText);*/
	
	//parse the state
	StateParser stateParser;

	stateParser.parseState("state.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);


	m_callbacks.push_back(0);

	m_callbacks.push_back(s_gameOverToMain);

	m_callbacks.push_back(s_restartPlay);

	setCallbacks(m_callbacks);

	std::cout << "entering GameOverState\n";
	return false;
}

bool GameOverState::onExit()
{
	return false;
}

void GameOverState::s_gameOverToMain()
{
	TheGameManager::Instance()->getStateMachine()->changeState(new MainMenuState());

}

void GameOverState::s_restartPlay()
{
	TheGameManager::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::setCallbacks(const std::vector<callback>& callbacks)
{
	MenuButton *pButton;
	//go through the game

	for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
		//if they are of type MenuButton then assign a callback
		//base on the id passed in from the file
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallBackID()]);
		}
	}
}
