
#include "SceneMain.h"
#include "SceneID.h"
#include "basic/GlobalInstance.h"
#include "utility/KeyManager.h"

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

		AddSceneEntity(m_pCharacter);
	}

	void SceneMain::Finalize()
	{
		delete m_pCharacter;
	}

	void SceneMain::Update(unsigned int elapsed_time)
	{
		BlueCarrot::utility::Position<float> move(0, 0);

		BlueCarrot::utility::KeyManager * key = BlueCarrot::GetGlobalInstance()->GetKeyManager();
		if ( key->IsPushing(BlueCarrot::utility::key::Left) )
		{
			move.left = -5;
		}
		if ( key->IsPushing(BlueCarrot::utility::key::Right) )
		{
			move.left = 5;
		}
		if ( key->IsPushing(BlueCarrot::utility::key::Up) )
		{
			move.top = -5;
		}
		if ( key->IsPushing(BlueCarrot::utility::key::Down) )
		{
			move.top = 5;
		}

		m_pCharacter->Move(move);

		BlueCarrot::SceneRendering::Update(elapsed_time);
	}

}
