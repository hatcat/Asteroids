#pragma once

#include "Physics.h"

namespace asteroids
{
	using display_surface = std::experimental::io2d::display_surface;

	class asteroid
	{
	public:
				asteroid(physics&&, const path_buffer*, float);
		void	update(display_surface& ds);

		static const float initial_speed;

	private:
		physics					m_physics;
		const path_buffer*	m_shape;
		float					m_size;
	};

	extern const path_buffer a1;
	extern const path_buffer a2;
	extern const path_buffer a3;
	extern const path_buffer a4;
}