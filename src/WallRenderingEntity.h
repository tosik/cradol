
#pragma once

#include "entity/SceneEntitySprite.h"


namespace cradol
{
	class WallRenderingEntity
		: public BlueCarrot::entity::SceneEntitySprite
	{
	public:
		WallRenderingEntity(std::string filename)
			: SceneEntitySprite(filename)
		{
			EnableAlphatest();
			SetRect(BlueCarrot::utility::Rect<float>(0, 0, 300, 300));
		}
	};
}
