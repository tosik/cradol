
#include "basic/Main.h"
#include "for/win/MainFunction.h"

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	// Windows �p�̃A�v���P�[�V�����̏ꍇ�́A���̊֐��Ɉ��������̂܂܎󂯓n��
	return BlueCarrot::WindowsEntryPoint(hThisInst, hPrevInst, lpszArgs, nWinMode);
}



BlueCarrot::SceneBase * BlueCarrot::callback::CreateScene(BlueCarrot::SceneID scene_id)
{
	// TODO : �V�[����Ԃ��Ă�
	return NULL;
}

BlueCarrot::SceneID BlueCarrot::callback::GetStartupSceneID()
{
	// TODO : �X�^�[�g���̃V�[�� ID ��Ԃ��Ă�
	return 0;
}

BlueCarrot::utility::Size<int> BlueCarrot::callback::GetScreenSize()
{
	return BlueCarrot::utility::Size<int>(640, 480);
}
