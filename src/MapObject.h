
#pragma once

#include "entity/SceneEntitySprite.h"
#include "PhysicalObject.h"
#include <string>

namespace cradol
{

	class MapObject
		: public BlueCarrot::entity::SceneEntitySprite
	{
	public:
		MapObject(std::string filename);
		void Update(unsigned int elapsed_time);
		void Jump();

	private:
		PhysicalObject m_PhysicalObject;
	};

}
