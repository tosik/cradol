
#include "Character.h"

namespace cradol
{

	Character::Character()
		: MapObject("../resource/master/trial/reversi/white.tga")
	{
	}

	void Character::Update(unsigned int elapsed_time)
	{
		MapObject::Update(elapsed_time);
	}

}
