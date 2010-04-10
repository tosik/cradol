
#pragma once

#include "scene/SceneRendering.h"
#include "Maze.h"
#include "WallRenderer.h"
#include "Player.h"


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

		void DebugShow();

	private:
		automaze::Maze m_Maze;
		WallRenderer * m_pWallRenderer;
		Player m_Player;
	};

}
