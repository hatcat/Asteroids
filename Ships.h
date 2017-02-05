#pragma once

#include "Physics.h"

namespace asteroids
{
	using display_surface = std::experimental::io2d::display_surface;

	class missile
	{
	public:
		missile();
		void update(display_surface& ds);

	private:
		physics		m_physics;
		bool		m_friend;
	};

	class ship
	{
	public:
		ship(const controllable_physics&);
		void					update(display_surface& ds, int lives);
		void					thrust(const vector_2d&);
		void					spin_left();
		void					spin_right();

	private:
		controllable_physics	m_physics;
	};

	class big_saucer
	{
	public:
		big_saucer(const physics&);
		void		update(display_surface& ds);

	private:
		physics		m_physics;
		bool		m_active;
	};

	class small_saucer
	{
	public:
		small_saucer(const physics&);
		void		update(display_surface& ds);

	private:
		physics		m_physics;
		bool		m_active;
	};

	extern const path_buffer ship_shape;
	extern const path_buffer saucer[3];
}