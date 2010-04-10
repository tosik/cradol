
#include "SceneMain.h"
#include "SceneID.h"
#include "basic/GlobalInstance.h"
#include "utility/KeyManager.h"
#include "Boutaoshi.h"
#include "debug/Debug.h"
#include "Player.h"

namespace cradol
{

	SceneMain::SceneMain()
		: BlueCarrot::SceneRendering(SCENE_MAIN)
		, m_Maze(31, 21)
		, m_Player(BlueCarrot::utility::Position<int>(1, 1), Top, BlueCarrot::utility::Size<int>(m_Maze.GetSizeX(), m_Maze.GetSizeY()))
	{
	}

	void SceneMain::Initialize()
	{
		automaze::Boutaoshi::generateMaze(m_Maze);

		m_pWallRenderer = new WallRenderer();
		for ( std::vector<WallRenderingEntity *>::const_iterator it = m_pWallRenderer->GetEntities().begin() ;
			it != m_pWallRenderer->GetEntities().end() ; it ++ )
			AddSceneEntity(*it);

		AddSceneEntity(m_Player.GetMap());
	}

	void SceneMain::Finalize()
	{
		for ( std::vector<WallRenderingEntity *>::const_iterator it = m_pWallRenderer->GetEntities().begin() ;
			it != m_pWallRenderer->GetEntities().end() ; it ++ )
			RemoveSceneEntity(*it);
		delete m_pWallRenderer;
	}


	BlueCarrot::utility::Position<int> roll(BlueCarrot::utility::Position<int> v, Direction d)
	{
		switch ( d )
		{
		case Top:
			return v;

		case Right:
			return BlueCarrot::utility::Position<int>(- v.top, v.left);

		case Bottom:
			return BlueCarrot::utility::Position<int>(- v.left, - v.top);

		case Left:
			return BlueCarrot::utility::Position<int>(v.top, - v.left);
		}

		return BlueCarrot::utility::Position<int>(0, 0);
	}

	void SceneMain::Update(unsigned int elapsed_time)
	{
		{
			BlueCarrot::utility::KeyManager * key = BlueCarrot::GetGlobalInstance()->GetKeyManager();

			if ( key->IsJustPushing(BlueCarrot::utility::key::Left) )
				m_Player.TurnLeft();
			if ( key->IsJustPushing(BlueCarrot::utility::key::Right) )
				m_Player.TurnRight();

			BlueCarrot::utility::Position<int> next(0, 0);
			BlueCarrot::utility::Position<int> dir(0, 0);
			if ( key->IsJustPushing(BlueCarrot::utility::key::Up) )
				dir = BlueCarrot::utility::Position<int>(0, -1);
			if ( key->IsJustPushing(BlueCarrot::utility::key::Down) )
				dir = BlueCarrot::utility::Position<int>(0, 1);
			next = m_Player.GetPosition() + roll(dir, m_Player.GetDirection());

			if ( ! m_Maze.IsWall(next.left, next.top) )
				m_Player.SetPosition(next);

			// debug show
			if ( key->IsJustPushing(BlueCarrot::utility::key::OK) )
				DebugShow();
		}

		{
			bool walls[10] = {false, false, false, false, false, false, false, false, false, false};

			/*
			5 6 7 8 9
			2 3 4
			0 ^ 1

			^ is player look at top
			*/

			BlueCarrot::utility::Position<int> v[10] = {
				BlueCarrot::utility::Position<int>(-1,  0),
				BlueCarrot::utility::Position<int>( 1,  0),
				BlueCarrot::utility::Position<int>(-1, -1),
				BlueCarrot::utility::Position<int>( 0, -1),
				BlueCarrot::utility::Position<int>( 1, -1),
				BlueCarrot::utility::Position<int>(-2, -2),
				BlueCarrot::utility::Position<int>(-1, -2),
				BlueCarrot::utility::Position<int>( 0, -2),
				BlueCarrot::utility::Position<int>( 1, -2),
				BlueCarrot::utility::Position<int>( 2, -2),
			};
			for ( int i = 0 ; i < 10 ; i ++ )
			{
				BlueCarrot::utility::Position<int> p = m_Player.GetPosition() + roll(v[i], m_Player.GetDirection());
				if ( p.left < 0 || p.top < 0 || p.left >= m_Maze.GetSizeX() || p.top >= m_Maze.GetSizeY() )
					walls[i] = true;
				else
					walls[i] = m_Maze.IsWall(p.left, p.top);
			}

			m_pWallRenderer->SetWallState(walls);
		}
	}

	void SceneMain::DebugShow()
	{
		for ( int y = 0 ; y < m_Maze.GetSizeY() ; y ++ )
		{
			for ( int x = 0 ; x < m_Maze.GetSizeX() ; x ++ )
			{
				if ( m_Player.GetPosition() == BlueCarrot::utility::Position<int>(x, y) )
				{
					switch ( m_Player.GetDirection() )
					{
					case Top:
						DebugOut("^^");
						break;
					case Right:
						DebugOut("->");
						break;
					case Bottom:
						DebugOut("vv");
						break;
					case Left:
						DebugOut("<-");
						break;
					}
				}
				else if ( m_Player.GetMap()->IsMarked(BlueCarrot::utility::Position<int>(x, y)) )
				{
					DebugOut("!!");
				}
				else if ( m_Maze.IsWall(x, y) )
				{
					DebugOut("%%%%");
				}
				else
				{
					DebugOut("  ");
				}
			}
			DebugOut("\n");
		}
	}

}
