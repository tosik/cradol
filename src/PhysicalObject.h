
#pragma once

#include "utility/Type.h"

using namespace BlueCarrot::utility;

namespace cradol
{
	// 物理演算用オブジェクト
	// cradol で用いる簡易的な物理処理を担う
	// 剛体シミュレーションを行うわけではない
	class PhysicalObject
		: public BlueCarrot::utility::Rect<float>
	{
	private:
		Position<float> m_Velocity;
		Position<float> m_MaxVelocity;

	public:
		PhysicalObject()
			: m_Velocity(0.f, 0.f)
			, m_MaxVelocity(10.f, 10.f)
		{
		}

		void Update(unsigned int elapsed_time)
		{
			// 自由落下
			m_Velocity.top += (float)elapsed_time / 100.f;

			if ( m_Velocity.left > m_MaxVelocity.left )
				m_Velocity.left = m_MaxVelocity.left;
			if ( m_Velocity.top > m_MaxVelocity.top )
				m_Velocity.top = m_MaxVelocity.top;
			if ( m_Velocity.left < - m_MaxVelocity.left )
				m_Velocity.left = - m_MaxVelocity.left;
			if ( m_Velocity.top < - m_MaxVelocity.top )
				m_Velocity.top = - m_MaxVelocity.top;

			Move(m_Velocity);
		}

		void AddAccelaration(Position<float> accel)
		{
			m_Velocity += accel;
		}
	};
}
