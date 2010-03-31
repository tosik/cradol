
#pragma once

#include "scene/SceneRendering.h"

#include "Character.h"


namespace cradol
{

	class SceneMain
		: public BlueCarrot::SceneRendering
	{
	public:
		SceneMain();

		void Initialize();
		void Finalize();
		void Update(unsigned int elapsed_time);

	private:
		Character * m_pCharacter;

	};

}
