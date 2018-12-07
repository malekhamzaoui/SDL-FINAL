#ifndef __AnimatedGraphics__
#define __AnimatedGraphics__
#pragma once


#include "SDLGameObject.h"
#include "BaseCreator.h"


class AnimatedGraphics :public SDLGameObject {
	//inhertit from SDLGameObject

private :
	int m_animSpeed;
public:

	//AnimatedGraphics(LoaderParams *pParams,int animSpeed);
	AnimatedGraphics();
	void load(LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();



};

class AnimatedGraphicCreator :public BaseCreator {


	GameObject* createGameObject()const {

		return new AnimatedGraphics();
	}

};

#endif
