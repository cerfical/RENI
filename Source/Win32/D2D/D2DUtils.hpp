#ifndef RENI_D2D_UTILS_HEADER
#define RENI_D2D_UTILS_HEADER

#include "Utils.hpp"
#include <d2d1.h>

namespace RENI::Win32::D2D {
	/** @brief Make a D2D1_COLOR_F from a Color. */
	inline auto MakeColorF(Color color) noexcept {
		return D2D1::ColorF(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
	}

	/** @brief Make a D2D1_RECT_F from a Rect. */
	inline auto MakeRectF(const Rect& rect) noexcept {
		return D2D1::RectF(
			rect.topLeft.x, rect.topLeft.y,
			rect.topLeft.x + rect.extent.width,
			rect.topLeft.y + rect.extent.height
		);
	}

	/** @brief Make a D2D1_SIZE_U from an Extent2D. */
	inline auto MakeSizeU(Extent2D size) noexcept {
		return D2D1::SizeU(size.width, size.height);
	}
}

#endif