#include "Game.h"

#include <random>
#include <string>

asteroids::game::game()
	: m_score(0)
	, m_lives(3)
	, m_level(1)
	, m_ship(controllable_physics{
				physics{ vector_2d{ 320, 240 }, { vector_2d{ 0, 0 }}},
				vector_2d{ 0, 0 },
				vector_2d{ 0, 0 }})
	, m_big_saucer(physics{ vector_2d{ 100, 50 },{ vector_2d{ 0, 0 } } })
	, m_small_saucer(physics{ vector_2d{ 150, 50 },{ vector_2d{ 0, 0 } } })
	, m_fr(std::experimental::io2d::font_resource_factory("courier new"))
{
	generate_level();
}

void asteroids::game::update(std::experimental::io2d::display_surface& ds)
{
	ds.paint(std::experimental::io2d::rgba_color::black());
	ds.line_width(1);
	for (auto& a : m_asteroids)
	{
		a.update(ds);
	}
	m_big_saucer.update(ds);
	m_small_saucer.update(ds);
	m_ship.update(ds, m_lives);
	ds.render_glyph_run(m_fr.make_glyph_run(std::to_string(m_score), vector_2d{ 50, 50 }));
}

void asteroids::game::generate_level()
{
	// Level 1 - 4
	// Level 2 - 6
	// Level 3 - 8
	auto count = m_level * 2 + 2;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> type(0, 3);
	std::uniform_int_distribution<> edge(1, 4);
	std::uniform_real_distribution<float> x(0.0f, width);
	std::uniform_real_distribution<float> y(0.0f, height);
	std::uniform_real_distribution<float> theta(0.0f, two_pi);

	static const path_buffer* asteroid_vbs[] = { &a1, &a2, &a3, &a4 };

	while (count-- != 0)
	{
		switch (edge(gen))
		{
		case 1:	m_asteroids.emplace_back(physics{ vector_2d{ 0, y(gen) },		polar_to_cartesian(asteroid::initial_speed, theta(gen)) }, asteroid_vbs[type(gen)], 5.0f); break;
		case 2:	m_asteroids.emplace_back(physics{ vector_2d{ width, y(gen) },	polar_to_cartesian(asteroid::initial_speed, theta(gen)) }, asteroid_vbs[type(gen)], 5.0f); break;
		case 3:	m_asteroids.emplace_back(physics{ vector_2d{ x(gen), 0 },		polar_to_cartesian(asteroid::initial_speed, theta(gen)) }, asteroid_vbs[type(gen)], 5.0f); break;
		case 4:	m_asteroids.emplace_back(physics{ vector_2d{ x(gen), height },	polar_to_cartesian(asteroid::initial_speed, theta(gen)) }, asteroid_vbs[type(gen)], 5.0f); break;
		}
	}
}

int main()
{
	auto ds = std::experimental::io2d::make_display_surface((int)asteroids::width, (int)asteroids::height, std::experimental::io2d::format::argb32);
	auto the_game = asteroids::game{};
	ds.draw_callback([&](auto& ds) { the_game.update(ds); });
	return ds.show();
}
