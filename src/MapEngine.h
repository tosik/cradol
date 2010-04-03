
#pragma once

#include "MapObject.h"


/*
MapEngine はマップに対する操作を統括するエンジン。
登録した MapObject は、マップに存在するオブジェクトである。
自立して動く Character は登録できない。

キャラクタが動くとき、そのマップのコリジョンを判定し移動を制限する必要がある。
こういう時は、MapEngine にキャラクタの移動先を教えることで移動可能か判定できる。
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
