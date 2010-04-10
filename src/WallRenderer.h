
#pragma once

#include "WallRenderingEntity.h"
#include <vector>


namespace cradol
{
	class WallRenderer
	{
	public:
		WallRenderer()
		{
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/0.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/1.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/2.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/3.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/4.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/5.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/6.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/7.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/8.png"));
			m_WallList.push_back(new WallRenderingEntity("../resource/master/maze/9.png"));

			m_WallList[0]->SetZ(7);
			m_WallList[1]->SetZ(9);
			m_WallList[2]->SetZ(4);
			m_WallList[3]->SetZ(8);
			m_WallList[4]->SetZ(6);
			m_WallList[5]->SetZ(0);
			m_WallList[6]->SetZ(2);
			m_WallList[7]->SetZ(5);
			m_WallList[8]->SetZ(3);
			m_WallList[9]->SetZ(1);
		}

		virtual ~WallRenderer()
		{
			for ( std::vector<WallRenderingEntity *>::iterator it = m_WallList.begin() ;
				it != m_WallList.end() ; it ++ )
				delete (*it);
		}

		const std::vector<WallRenderingEntity *> & GetEntities()
		{
			return m_WallList;
		}

		void SetWallState(bool w[10])
		{
			for ( int i = 0 ; i < 10 ; i ++ )
			if ( w[i] )
				m_WallList[i]->EnableRendering();
			else
				m_WallList[i]->DisableRendering();
		}

	private:
		std::vector<WallRenderingEntity *> m_WallList;
	};
}
