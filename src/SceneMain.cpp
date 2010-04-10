
#include "SceneMain.h"
#include "SceneID.h"
#include "basic/GlobalInstance.h"
#include "utility/KeyManager.h"
#include "Boutaoshi.h"
#include "debug/Debug.h"

namespace cradol
{

	SceneMain::SceneMain()
		: BlueCarrot::SceneRendering(SCENE_MAIN)
		, m_Maze(31, 21)
	{
	}

	void SceneMain::Initialize()
	{
		automaze::Boutaoshi::generateMaze(m_Maze);
		for ( int y = 0 ; y < m_Maze.GetSizeY() ; y ++ )
		{
			for ( int x = 0 ; x < m_Maze.GetSizeX() ; x ++ )
			{
				if ( m_Maze.IsWall(x, y) )
					DebugOut("%%%%");
				else
					DebugOut("  ");
			}
			DebugOut("\n");
		}
	}

	void SceneMain::Finalize()
	{
	}

	void SceneMain::Update(unsigned int elapsed_time)
	{
	}

}
