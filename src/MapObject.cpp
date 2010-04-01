
#include "MapObject.h"

namespace cradol
{

	MapObject::MapObject(std::string filename)
		: SceneEntitySprite(filename)
	{
		SetSize(BlueCarrot::utility::Size<float>(32, 32));
		EnableAlphablending();
	}

	void MapObject::Update(unsigned int elapsed_time)
	{
		m_PhysicalObject.SetPosition(*this);
		m_PhysicalObject.Update(elapsed_time);
		SetPosition(BlueCarrot::utility::Position<float>(m_PhysicalObject.left, m_PhysicalObject.top));
	}

	void MapObject::Jump()
	{
		m_PhysicalObject.AddAccelaration(BlueCarrot::utility::Position<float>(0.f, -10.f));
	}

}
