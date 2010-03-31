
#include "Character.h"

namespace cradol
{

	Character::Character()
		: SceneEntitySprite("../resource/master/trial/reversi/white.tga")
	{
		SetSize(BlueCarrot::utility::Size<float>(50, 50));
		EnableAlphablending();
	}

}
