
#pragma once

#include "utility/Type.h"
#include "Direction.h"
#include <vector>
#include "entity/SceneEntitySprite.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"

namespace cradol
{
	class Map
		: public BlueCarrot::entity::SceneEntitySprite
	{
	public:
		Map(BlueCarrot::utility::Size<int> size)
			: SceneEntitySprite("../resource/master/maze/foormark.png")
		{
			m_Footmarks.resize(size.width);
			for ( int i = 0 ; i < size.width ; i ++ )
				m_Footmarks[i].resize(size.height);

			for ( int y = 0 ; y < size.height ; y ++ )
				for ( int x = 0 ; x < size.width ; x ++ )
					m_Footmarks[x][y] = false;

			EnableAlphatest();
			SetRect(BlueCarrot::utility::Rect<float>(0, 0, 16, 16));
			SetZ(10);
		}

		virtual ~Map()
		{
		}

		void Mark(BlueCarrot::utility::Position<int> pos)
		{
			m_Footmarks[pos.top][pos.left] = true;
		}

		void Unmark(BlueCarrot::utility::Position<int> pos)
		{
			m_Footmarks[pos.top][pos.left] = false;
		}

		bool IsMarked(BlueCarrot::utility::Position<int> pos)
		{
			return m_Footmarks[pos.top][pos.left];
		}

		void Draw()
		{
			BlueCarrot::utility::Rect<float> rect(*this);
			BlueCarrot::graphics::Renderer * renderer = BlueCarrot::GetGlobalInstance()->GetRenderer();

			for ( int y = 0 ; y < (int)m_Footmarks.size() ; y ++ )
			{
				for ( int x = 0 ; x < (int)m_Footmarks[y].size() ; x ++ )
				{
					if ( m_Footmarks[y][x] )
						renderer->DrawRect(rect + BlueCarrot::utility::Rect<float>((float)x * rect.width, (float)y * rect.height, 0.f, 0.f),
							GetUV(), GetColor(), GetTexture(), IsEnableAlphatest(), IsEnableAlphablending());
				}
			}
		}

	private:
		std::vector<std::vector<bool> > m_Footmarks;
	};
}
