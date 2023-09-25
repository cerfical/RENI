#ifndef RENI_D3D_RENDER_HEADER
#define RENI_D3D_RENDER_HEADER

#include "D3DUtils.hpp"

namespace RENI {
	class Window;
	/**
	 * @brief Direct3D renderer.
	 */
	class D3DRender {
	public:
		/** @{ */
		explicit D3DRender(Window& window);
		/** @} */

		/** @{ */
		D3DRender(const D3DRender&) = delete;
		D3DRender& operator=(const D3DRender&) = delete;
		/** @} */

		/** @{ */
		void startRender();
		void endRender();
		/** @} */

		/** @{ */
		void setDrawColor(Color c);
		void clear(Color c);
		/** @} */

		/** @{ */
		void drawLine(const Line2D& l);

		void drawRect(const Rect2D& r);
		void fillRect(const Rect2D& r);
		/** @} */

	private:
		/** @{ */
		void createDrawRt();
		void resizeBuffers(const Size2D& s);
		/** @} */

		ComPtr<IDXGISwapChain> m_swapChain;
		ComPtr<ID3D11Device> m_device;
		ComPtr<ID3D11DeviceContext> m_context;

		ComPtr<ID2D1Factory> m_d2dFactory;
		ComPtr<ID2D1SolidColorBrush> m_drawBrush;
		ComPtr<ID2D1RenderTarget> m_drawRt;

		Window* m_window = nullptr;
		Size2D m_bufferSize;
	};
}

#endif