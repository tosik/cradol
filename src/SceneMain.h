
#pragma once

#include "scene/SceneRendering.h"
#include "Maze.h"


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
		automaze::Maze m_Maze;
	};

}
