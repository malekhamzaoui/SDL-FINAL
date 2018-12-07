#ifndef __BaseCreator__
#define __BaseCreator__
#pragma once

#include "GameObject.h"


class BaseCreator
{
public:

	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

#endif

