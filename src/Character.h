
#pragma once

#include "MapObject.h"

namespace cradol
{

	class Character
		: public MapObject
	{
	public:
		Character();
		void Update(unsigned int elapsed_time);
	};

}
