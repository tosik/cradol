
#pragma once

#include "MapObject.h"

namespace cradol
{

	class Brick
		: public MapObject
	{
	public:
		Brick();
		void Update(unsigned int elapsed_time);
	};

}
