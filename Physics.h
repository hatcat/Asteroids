#pragma once

#include "io2d.h"

namespace asteroids
{
	using vector_2d = std::experimental::io2d::vector_2d;
	using matrix_2d = std::experimental::io2d::matrix_2d;

	struct path_buffer
	{
		const int			m_count;
		const vector_2d*	m_vertex;
	};

	class physics
	{
	public:
		physics(const vector_2d& pos, const vector_2d& vel);
		void				update(const vector_2d&);
		const vector_2d&	position();
		const vector_2d&	velocity();

	private:
		vector_2d	m_position;
		vector_2d	m_velocity;
	};

	class controllable_physics
	{
	public:
		controllable_physics(const physics& phy, const vector_2d& acc, const vector_2d& ori);
		void				thrust(const vector_2d&);
		void				spin_left();
		void				spin_right();
		void				update();
		const vector_2d&	position();
		const vector_2d&	velocity();
		const vector_2d&	acceleration();
		const vector_2d&	orientation();

	private:
		physics				m_physics;
		vector_2d			m_acceleration;
		vector_2d			m_orientation;
	};

	vector_2d polar_to_cartesian(float, float);
	void constrain(vector_2d&);

	const float width = 640.0f;
	const float height = 480.0f;
	const float two_pi = 6.283185307179586476925286766559f;
}