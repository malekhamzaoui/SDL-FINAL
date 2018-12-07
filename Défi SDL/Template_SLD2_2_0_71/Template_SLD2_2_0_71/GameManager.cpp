
#include "GameManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"




//Static singleton
GameManager* GameManager::s_pInstance = 0;



/********************************************************************
BUT : INIT de SDL
ENTREES : titre, position fenetre, hauteur, largeur,flags gameObject
SORTIE : SDL init
*********************************************************************/

GameManager::GameManager() {

	g_pRenderer = NULL;
	g_pWindow = NULL;


}

GameManager::~GameManager()
{

	
		
}

int GameManager::init(char * title, int xpos, int ypos, int width, int height, int flags)
{
	// store the game width and height
	m_gameWidth = width;
	m_gameHeight = height;

	//initialize SDL

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//if succeeded create window, create our render
		if (g_pWindow != NULL) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
			if (g_pRenderer != NULL) {


				SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
				SDL_RenderClear(g_pRenderer);//clear the render to the draw color

				int flags = IMG_INIT_JPG | IMG_INIT_PNG;
				int initted = IMG_Init(flags);
				if ((initted&flags) != flags) {

					std::cerr << "IMG_Init: Failed to init required jpg and png support!\n";
					std::cerr << "IMG_Init:" << IMG_GetError();
					SDL_Delay(5000);
					return 0;

					// handle error
				}
			}
			else {
				std::cerr << "Failed to init renderer!\n";
				std::cerr << "Error" << SDL_GetError();
				SDL_Delay(5000);
				return 0;
			}


		}
		else {
			std::cerr << "Failed to init window!\n";
			std::cerr << "Error" << SDL_GetError();
			SDL_Delay(5000);
			return 0;
		}


	}
	else {

		std::cerr << "Fail to init SDL2\n";
		std::cerr << "Error" << SDL_GetError();
		SDL_Delay(5000);
		return 0;
	}

	TheInputHandler::Instance()->initialiseJoysticks();

	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());

	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());

	TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());

	TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());



	//Initial GameState
	m_currentGameState = game_states::MENU;

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());






	return 1;



}

void GameManager::update()
{

	m_pGameStateMachine->update();

}


void GameManager::render()
{

	//clear the render to the draw color and clear texture every frame
	SDL_RenderClear(g_pRenderer);

	m_pGameStateMachine->render();

	//loop throuh ou objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObject.size(); i++) {

		m_gameObject[i]->draw();
	}

	SDL_RenderPresent(g_pRenderer);
	//draw to screen

}

void GameManager::handleEvents()
{
	
	

	TheInputHandler::Instance()->update();//call update fct InputHandler, call SDL_Quit()

										  //Stop main game loop
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		this->setRunning(false);
	}else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_pGameStateMachine->changeState(new PlayState());
	}

}

void GameManager::setRunning(bool run)
{
	m_bRunning = run;
}

void GameManager::clean()
{
	TheInputHandler::Instance()->clean();
	assert(g_pRenderer != NULL);
	SDL_DestroyRenderer(g_pRenderer);

	assert(g_pWindow != NULL);
	SDL_DestroyWindow(g_pWindow);

	// unload the dynamically loaded image libraries
	IMG_Quit();
	//quit sdl2
	SDL_Quit();




}

//sur-definition draw()
void GameManager::draw()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObject.size(); i++) {

		m_gameObject[i]->draw();
	}


}

void GameManager::quit()
{
	SDL_Quit();
}







