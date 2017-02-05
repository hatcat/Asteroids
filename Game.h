#pragma once

#include "Ships.h"
#include "Asteroid.h"

namespace asteroids
{
	using font_resource = std::experimental::io2d::font_resource;

	class game
	{
	public:
		game();
		void	update(display_surface& ds);

	private:
		void	generate_level();

		int						m_score;
		int						m_lives;
		int						m_level;
		ship					m_ship;
		big_saucer				m_big_saucer;
		small_saucer			m_small_saucer;
		std::vector<asteroid>	m_asteroids;
		std::vector<missile>	m_missiles;
		font_resource			m_fr;
	};

}