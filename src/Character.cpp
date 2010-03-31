
#include "Character.h"

namespace cradol
{

	Character::Character()
		: SceneEntitySprite("../resource/master/trial/reversi/white.tga")
	{
		SetSize(BlueCarrot::utility::Size<float>(50, 50));
		EnableAlphablending();
	}

	void Character::Update(unsigned int elapsed_time)
	{
		Move(BlueCarrot::utility::Position<float>(1, 2));

		SceneEntitySprite::Update(elapsed_time);
	}

}
