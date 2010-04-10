
#pragma once

#include "utility/Type.h"
#include "Direction.h"
#include <vector>

namespace cradol
{
	class Map
	{
	public:
		Map(BlueCarrot::utility::Size<int> size)
		{
			m_Footmarks.resize(size.width);
			for ( int i = 0 ; i < size.width ; i ++ )
				m_Footmarks[i].resize(size.height);

			for ( int y = 0 ; y < size.height ; y ++ )
				for ( int x = 0 ; x < size.width ; x ++ )
					m_Footmarks[x][y] = false;
		}

		virtual ~Map()
		{
		}

		void Mark(BlueCarrot::utility::Position<int> pos)
		{
			m_Footmarks[pos.left][pos.top] = true;
		}

		void Unmark(BlueCarrot::utility::Position<int> pos)
		{
			m_Footmarks[pos.left][pos.top] = false;
		}

		bool IsMarked(BlueCarrot::utility::Position<int> pos)
		{
			return m_Footmarks[pos.left][pos.top];
		}

	private:
		std::vector<std::vector<bool> > m_Footmarks;
	};
}
