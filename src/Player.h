
#pragma once

#include "utility/Type.h"
#include "Direction.h"

namespace cradol
{
	class Player
	{
	public:
		Player(BlueCarrot::utility::Position<int> position, Direction direction)
			: m_Position(position)
			, m_Direction(direction)
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
		}

		void TurnLeft()
		{
			m_Direction = cradol::TurnLeft(m_Direction);
		}

		void TurnRight()
		{
			m_Direction = cradol::TurnRight(m_Direction);
		}

	private:
		Direction m_Direction;
		BlueCarrot::utility::Position<int> m_Position;
	};
}
