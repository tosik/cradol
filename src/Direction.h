
#pragma once


namespace cradol
{
	enum Direction
	{
		Top,
		Right,
		Bottom,
		Left,
	};

	inline Direction TurnLeft(Direction d)
	{
		switch ( d )
		{
		case Top:
			return Left;
		case Left:
			return Bottom;
		case Bottom:
			return Right;
		case Right:
			return Top;
		}

		return Top;
	}

	inline Direction TurnRight(Direction d)
	{
		switch ( d )
		{
		case Top:
			return Right;
		case Left:
			return Top;
		case Bottom:
			return Left;
		case Right:
			return Bottom;
		}

		return Top;
	}
}
