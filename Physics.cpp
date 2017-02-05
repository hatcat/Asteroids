#include "Physics.h"

asteroids::physics::physics(const vector_2d& pos, const vector_2d& vel)
	: m_position(pos)
	, m_velocity(vel)
{}

void asteroids::physics::update(const vector_2d& acceleration)
{
	m_velocity += acceleration;
	m_position += m_velocity;
	constrain(m_position);
}

const asteroids::vector_2d& asteroids::physics::position()
{
	return m_position;
}

const asteroids::vector_2d& asteroids::physics::velocity()
{
	return m_velocity;
}

asteroids::controllable_physics::controllable_physics(const physics& phy, const vector_2d& acc, const vector_2d& ori)
	: m_physics(phy)
	, m_acceleration(acc)
	, m_orientation(ori)
{}

void asteroids::controllable_physics::thrust(const vector_2d&)
{}

void asteroids::controllable_physics::spin_left()
{}

void asteroids::controllable_physics::spin_right()
{}

void asteroids::controllable_physics::update()
{
	m_physics.update(m_acceleration);
}

const asteroids::vector_2d& asteroids::controllable_physics::position()
{
	return m_physics.position();
}

const asteroids::vector_2d& asteroids::controllable_physics::velocity()
{
	return m_physics.velocity();
}

const asteroids::vector_2d& asteroids::controllable_physics::acceleration()
{
	return m_acceleration;
}

const asteroids::vector_2d& asteroids::controllable_physics::orientation()
{
	return m_orientation;
}

asteroids::vector_2d asteroids::polar_to_cartesian(float r, float theta)
{
	return vector_2d{ r * sin(theta), r * cos(theta) };
}

void asteroids::constrain(std::experimental::io2d::vector_2d& pos)
{
	while (pos.x() >= 640.0f) pos.x(pos.x() - 640.0f);
	while (pos.y() >= 480.0f) pos.y(pos.y() - 480.0f);
	while (pos.x() < 0.0f) pos.x(pos.x() + 640.0f);
	while (pos.y() < 0.0f) pos.y(pos.y() + 480.0f);
}
