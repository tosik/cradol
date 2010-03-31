
#include "basic/Main.h"
#include "for/win/MainFunction.h"

#include "SceneMain.h"
#include "SceneID.h"

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	// Windows �p�̃A�v���P�[�V�����̏ꍇ�́A���̊֐��Ɉ��������̂܂܎󂯓n��
	return BlueCarrot::WindowsEntryPoint(hThisInst, hPrevInst, lpszArgs, nWinMode);
}


BlueCarrot::SceneBase * BlueCarrot::callback::CreateScene(BlueCarrot::SceneID scene_id)
{
	switch ( scene_id )
	{
	case cradol::SCENE_MAIN:
		return new cradol::SceneMain();

	default:
		return NULL;
	}
}

BlueCarrot::SceneID BlueCarrot::callback::GetStartupSceneID()
{
	return cradol::SCENE_MAIN;
}

BlueCarrot::utility::Size<int> BlueCarrot::callback::GetScreenSize()
{
	return BlueCarrot::utility::Size<int>(640, 480);
}
