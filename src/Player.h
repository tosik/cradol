
#pragma once

#include "utility/Type.h"
#include "Direction.h"
#include "Map.h"

namespace cradol
{
	class Player
	{
	public:
		Player(BlueCarrot::utility::Position<int> position, Direction direction, BlueCarrot::utility::Size<int> map_size)
			: m_Position(position)
			, m_Direction(direction)
			, m_Map(map_size)
		{
		}

		virtual ~Player()
		{
		}

		Direction GetDirection()
		{
			return m_Direction;
		}

		BlueCarrot::utility::Position<int> GetPosition()
		{
			return m_Position;
		}

		void SetPosition(BlueCarrot::utility::Position<int> position)
		{
			m_Position = position;
			m_Map.Mark(m_Position);
		}

		void TurnLeft()
		{
			m_Direction = cradol::TurnLeft(m_Direction);
		}

		void TurnRight()
		{
			m_Direction = cradol::TurnRight(m_Direction);
		}

		Map * GetMap()
		{
			return & m_Map;
		}

	private:
		Direction m_Direction;
		BlueCarrot::utility::Position<int> m_Position;
		Map m_Map;
	};
}
