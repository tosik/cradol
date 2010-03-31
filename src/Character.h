
#pragma once

#include "entity/SceneEntitySprite.h"

namespace cradol
{

	class Character
		: public BlueCarrot::entity::SceneEntitySprite
	{
	public:
		Character();
		void Update(unsigned int elapsed_time);
	};

}
