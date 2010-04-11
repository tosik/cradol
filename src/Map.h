
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
			m_Footmarks.resize(size.height);
			for ( int i = 0 ; i < size.height ; i ++ )
				m_Footmarks[i].resize(size.width);

			for ( int y = 0 ; y < size.height ; y ++ )
				for ( int x = 0 ; x < size.width ; x ++ )
					m_Footmarks[y][x] = false;

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

		void SetDirection(Direction direction)
		{
			m_Direction = direction;
		}

		void Draw()
		{
			BlueCarrot::utility::Rect<float> rect(*this);
			BlueCarrot::graphics::Renderer * renderer = BlueCarrot::GetGlobalInstance()->GetRenderer();

			int max_y = (int)m_Footmarks.size();
			for ( int y = 0 ; y < max_y ; y ++ )
			{
				int max_x = (int)m_Footmarks[y].size();
				for ( int x = 0 ; x < max_x ; x ++ )
				{
					if ( m_Footmarks[y][x] )
					{
						int dx, dy;
						switch ( m_Direction )
						{
						case Top:
							dx = x;
							dy = y;
							break;
						case Left:
							dx = max_y - y;
							dy = x;
							break;
						case Bottom:
							dx = max_x - x;
							dy = max_y - y;
							break;
						case Right:
							dx = y;
							dy = max_x - x;
							break;
						}
						renderer->DrawRect(rect + BlueCarrot::utility::Rect<float>((float)dx * rect.width, (float)dy * rect.height, 0.f, 0.f),
							GetUV(), GetColor(), GetTexture(), IsEnableAlphatest(), IsEnableAlphablending());
					}
				}
			}
		}

	private:
		std::vector<std::vector<bool> > m_Footmarks;
		Direction m_Direction;
	};
}
