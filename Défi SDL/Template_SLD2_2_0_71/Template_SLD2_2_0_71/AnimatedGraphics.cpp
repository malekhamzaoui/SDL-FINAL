#include "AnimatedGraphics.h"

/*AnimatedGraphics::AnimatedGraphics( LoaderParams * pParams, int animSpeed):SDLGameObject(),m_animSpeed(animSpeed)
{
	load(pParams);
}*/

AnimatedGraphics::AnimatedGraphics() :SDLGameObject() {


}

void AnimatedGraphics::load(LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphics::draw()
{
	SDLGameObject::draw();
}

void AnimatedGraphics::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 5));
}

void AnimatedGraphics::clean()
{
	SDLGameObject::clean();
}
