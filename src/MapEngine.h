
#pragma once

#include "MapObject.h"


/*
MapEngine �̓}�b�v�ɑ΂��鑀��𓝊�����G���W���B
�o�^���� MapObject �́A�}�b�v�ɑ��݂���I�u�W�F�N�g�ł���B
�������ē��� Character �͓o�^�ł��Ȃ��B

�L�����N�^�������Ƃ��A���̃}�b�v�̃R���W�����𔻒肵�ړ��𐧌�����K�v������B
�����������́AMapEngine �ɃL�����N�^�̈ړ���������邱�Ƃňړ��\������ł���B
*/

namespace cradol
{
	class MapEngine
	{
	public:
		MapEngine() {}

		void AddMapObject(MapObject * pMapObject)
		{
			m_MapObjectList.push_back(pMapObject);
		}

		//bool CanMove(BlueCarrot::utility::Position<float> position);

	private:
		std::vector<MapObject *> m_MapObjectList;
	};
}
