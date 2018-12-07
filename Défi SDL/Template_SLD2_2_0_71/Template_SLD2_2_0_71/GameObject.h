
#ifndef __GameObject__
#define __GameObject__
#pragma once


#include "define.h"
#include "TextureManager.h"
#include "LoaderParams.h"

class GameObject {

	public:
		

		

		inline virtual void draw()=0 {}


		inline virtual void update()=0 {}

		inline virtual void clean()=0 {}

		virtual void load(LoaderParams *pParams) = 0;
		//virtual void load(int x, int y, int width, int height, std::string textureId);


	
	
	protected :

		GameObject(){}
		virtual ~GameObject(){}

};

#endif