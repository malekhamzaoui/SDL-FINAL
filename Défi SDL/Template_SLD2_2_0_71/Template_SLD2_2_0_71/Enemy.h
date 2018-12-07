
#ifndef __Enemy__
#define __Enemy__
#pragma once

#include "SDLGameObject.h"
#include "BaseCreator.h"


class Enemy :public SDLGameObject {
	//inhertit from SDLGameObject
public:

	//Enemy(const LoaderParams *pParams);
	Enemy();
	virtual void draw();
	virtual void update();
	virtual void clean();

	void load(LoaderParams *pParams);


};


class EnemyCreator :public BaseCreator {


	GameObject* createGameObject()const {

		return new Enemy();
	}

};

#endif
