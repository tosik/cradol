
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
		BlueCarrot::utility::KeyManager * key = BlueCarrot::GetGlobalInstance()->GetKeyManager();
		if ( key->IsJustPushing(BlueCarrot::utility::key::OK) )
		{
			m_pCharacter->Jump();
		}

		BlueCarrot::SceneRendering::Update(elapsed_time);
	}

}
