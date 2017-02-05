#include "Asteroid.h"

namespace
{
	const asteroids::vector_2d a1_vb[] = { { -2, -4 },{ 2, 2 },{ 2, -2 },{ 2, 2 },{ -1, 2 },{ 1, 2 },{ -3, 2 },{ -3, 0 },{ -2, -2 },{ 0, -4 },{ 2, -2 } };
	const asteroids::vector_2d a2_vb[] = { { -2, -4 },{ 2, 1 },{ 2, -1 },{ 2, 2 },{ -2, 1 },{ 2, 2 },{ -2, 3 },{ -3, -1 },{ -1, 1 },{ -2, -2 },{ 1, -2 },{ -1, -2 },{ 2, -2 } };
	const asteroids::vector_2d a3_vb[] = { { -2, -4 },{ 3, 0 },{ 3, 2 },{ 0, 1 },{ -3, 1 },{ 3, 2 },{ -2, 2 },{ -4, 0 },{ -2, -3 },{ 0, -3 },{ 3, 0 },{ -1, -2 } };
	const asteroids::vector_2d a4_vb[] = { { -1, -4 },{ 3, 0 },{ 2, 3 },{ 0, 2 },{ -2, 3 },{ -2, 0 },{ 0, -3 },{ -2, 3 },{ -2, -3 },{ 2, -1 },{ -2, -1 },{ 3, -3 } };
}

const float asteroids::asteroid::initial_speed = 0.1f;

const asteroids::path_buffer asteroids::a1 = { 11, a1_vb };
const asteroids::path_buffer asteroids::a2 = { 13, a2_vb };
const asteroids::path_buffer asteroids::a3 = { 12, a3_vb };
const asteroids::path_buffer asteroids::a4 = { 12, a4_vb };

asteroids::asteroid::asteroid(physics&& phys, const path_buffer* path, float s)
	: m_physics(std::move(phys))
	, m_shape(path)
	, m_size(s)
{}

void asteroids::asteroid::update(std::experimental::io2d::display_surface& ds)
{
	m_physics.update({ 0,0 });
	auto af = std::experimental::io2d::path_factory{};
	af.move_to(m_physics.position());

	auto count = m_shape->m_count;
	auto vertex = m_shape->m_vertex;
	auto first = *vertex++ * m_size;
	auto point = first;
	af.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++ * m_size;
		af.rel_line_to(next);
	}

	ds.path(std::experimental::io2d::path{ af });
	ds.stroke(std::experimental::io2d::rgba_color::white());
}
