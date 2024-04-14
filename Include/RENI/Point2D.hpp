#ifndef RENI_POINT_2D_HEADER
#define RENI_POINT_2D_HEADER

#include <compare>
#include <ostream>

namespace reni {

	/**
	 * @brief Point in 2D space as a pair of two integer coordinates.
	*/
	struct Point2D {
		
		friend constexpr auto operator<=>(Point2D lhs, Point2D rhs) = default;

		int x = {};
		int y = {};

	};

}

#endif