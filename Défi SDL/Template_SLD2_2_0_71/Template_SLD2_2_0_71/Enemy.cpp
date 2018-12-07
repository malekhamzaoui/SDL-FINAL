#include "Enemy.h"

int j = 0;


Enemy::Enemy() :SDLGameObject()
{
	
}

void Enemy::draw()
{
	SDLGameObject::draw();
	std::cout << "draw Enemy" << std::endl;
}



void Enemy::update()
{
	
	int Frame = (int)((SDL_GetTicks() / 100) % 5);
	SDLGameObject::setCurrentFrame(Frame);

	if (m_position.getY() < 0)
		m_velocity.setY(2);
	else if (m_position.getY() > 400)
		m_velocity.setY(-2);

	SDLGameObject::update();


}

void Enemy::clean()
{
	SDLGameObject::clean();
	//std::cout << "Clean Enemy" << std::endl;
}

void Enemy::load(LoaderParams * pParams)
{
	/*m_velocity.setY(2);
	m_velocity.setX(0.001);*/
	SDLGameObject::load(pParams);
	m_velocity.setX(0.001);
	m_velocity.setY(2);
	
}
