
#include "SceneMain.h"
#include "SceneID.h"
#include "basic/GlobalInstance.h"
#include "utility/KeyManager.h"
#include "Brick.h"

namespace cradol
{

	SceneMain::SceneMain()
		: BlueCarrot::SceneRendering(SCENE_MAIN)
	{
	}

	void SceneMain::Initialize()
	{
		m_pCharacter = new Character();
		m_pCharacter->SetPosition(BlueCarrot::utility::Position<float>(100, 100));
		m_pCharacter->SetZ(1.0);

		AddSceneEntity(m_pCharacter);

		for ( int i = 0 ; i < 10 ; i ++ )
		{
			Brick * brick = new Brick();
			brick->SetPosition(BlueCarrot::utility::Position<float>(i * 32, 300));
			brick->SetZ(0.5);
			AddSceneEntity(brick);
			m_BrickList.push_back(brick);
		}
	}

	void SceneMain::Finalize()
	{
		{
			std::vector<Brick *>::iterator it = m_BrickList.begin();
			std::vector<Brick *>::iterator it_end = m_BrickList.end();
			for ( ; it != it_end ; it ++ )
				delete (*it);
		}

		delete m_pCharacter;
	}

	void SceneMain::Update(unsigned int elapsed_time)
	{
		BlueCarrot::utility::KeyManager * key = BlueCarrot::GetGlobalInstance()->GetKeyManager();
		if ( key->IsJustPushing(BlueCarrot::utility::key::OK) )
		{
			m_pCharacter->Jump();
		}

		BlueCarrot::SceneRendering::Update(elapsed_time);

		{
			std::vector<Brick *>::iterator it = m_BrickList.begin();
			std::vector<Brick *>::iterator it_end = m_BrickList.end();
			for ( ; it != it_end ; it ++ )
			{
				if ( m_pCharacter->IsIntersect(**it) )
				{
					m_pCharacter->Jump();
				}
			}
		}
	}

}
