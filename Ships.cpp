#include "Ships.h"

namespace
{
	// Ship 16 pixels high
	// Big saucer 16 pixels high
	// Small saucer 10 pixels high

	const asteroids::vector_2d ship_vb[] = { { 0, -8 },{ 5, 15 },{ -2, -3 },{ -5, 0 },{ -3, 3 },{ 5, -15 } };
	const asteroids::vector_2d saucer_vb1[] = { { 10, 0 },{ 5, 0 },{ 2, 5 },{ 9, 5 },{ -9, 5 },{ -9, 0 },{ -9, -5 },{ 9, -5 },{ 2, -5 } };
	const asteroids::vector_2d saucer_vb2[] = { { 8, 5 },{ 9, 0 } };
	const asteroids::vector_2d saucer_vb3[] = { { 0, 10 },{ 26, 0 } };
}

const asteroids::path_buffer asteroids::ship_shape = { 6, ship_vb };
const asteroids::path_buffer asteroids::saucer[3] = { { 9, saucer_vb1 },{ 2, saucer_vb2 },{ 2, saucer_vb3 } };


asteroids::ship::ship(const controllable_physics& cp)
	: m_physics(cp)
{}

void asteroids::ship::update(display_surface& ds, int lives)
{
	m_physics.update();

	auto pf = std::experimental::io2d::path_factory{};

	pf.move_to(m_physics.position());
	auto count = ship_shape.m_count;
	auto vertex = ship_shape.m_vertex;
	auto first = *vertex++;
	auto point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		pf.rel_line_to(*vertex++);
	}

	while (lives--)
	{
		pf.move_to({ 50.0f - (10.0f * lives), 35.0f });
		count = ship_shape.m_count;
		vertex = ship_shape.m_vertex;
		first = *vertex++;
		point = first;
		pf.rel_move_to(point);
		while (--count)
		{
			pf.rel_line_to(*vertex++);
		}
	}

	ds.path(std::experimental::io2d::path{ pf });
	ds.stroke(std::experimental::io2d::rgba_color::white());
}

asteroids::big_saucer::big_saucer(const physics& p)
	: m_physics(p)
	, m_active(false)
{}

void asteroids::big_saucer::update(std::experimental::io2d::display_surface& ds)
{
	if (!m_active) return;
	m_physics.update({ 0, 0 });

	auto pf = std::experimental::io2d::path_factory{};

	pf.move_to(m_physics.position());
	auto count = saucer[0].m_count;
	auto vertex = saucer[0].m_vertex;
	auto first = *vertex++;
	auto point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++;
		pf.rel_line_to(next);
	}

	pf.move_to(m_physics.position());
	count = saucer[1].m_count;
	vertex = saucer[1].m_vertex;
	first = *vertex++;
	point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++;
		pf.rel_line_to(next);
	}

	pf.move_to(m_physics.position());
	count = saucer[2].m_count;
	vertex = saucer[2].m_vertex;
	first = *vertex++;
	point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++;
		pf.rel_line_to(next);
	}

	ds.path(std::experimental::io2d::path{ pf });
	ds.stroke(std::experimental::io2d::rgba_color::white());
}

asteroids::small_saucer::small_saucer(const physics& p)
	: m_physics(p)
	, m_active(false)
{}

void asteroids::small_saucer::update(std::experimental::io2d::display_surface& ds)
{
	if (!m_active) return;
	m_physics.update({ 0, 0 });

	auto pf = std::experimental::io2d::path_factory{};

	pf.move_to(m_physics.position());
	auto count = saucer[0].m_count;
	auto vertex = saucer[0].m_vertex;
	auto first = *vertex++ * 0.6f;
	auto point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++ * 0.6f;
		pf.rel_line_to(next);
	}

	pf.move_to(m_physics.position());
	count = saucer[1].m_count;
	vertex = saucer[1].m_vertex;
	first = *vertex++ * 0.6f;
	point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++ * 0.6f;
		pf.rel_line_to(next);
	}

	pf.move_to(m_physics.position());
	count = saucer[2].m_count;
	vertex = saucer[2].m_vertex;
	first = *vertex++ * 0.6f;
	point = first;
	pf.rel_move_to(point);
	while (--count)
	{
		auto next = *vertex++ * 0.6f;
		pf.rel_line_to(next);
	}

	ds.path(std::experimental::io2d::path{ pf });
	ds.stroke(std::experimental::io2d::rgba_color::white());
}


/*void asteroids::asteroid::update(std::experimental::io2d::display_surface& ds)
{
	m_physics.m_position += m_physics.m_velocity;
	constrain(m_physics.m_position);
	auto af = std::experimental::io2d::path_factory{};
	af.move_to(m_physics.m_position);

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
}*/