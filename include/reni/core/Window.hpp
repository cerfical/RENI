#pragma once

#include "../util/types.hpp"

#include "Key.hpp"
#include "MouseButton.hpp"

#include <string>
#include <memory>

namespace reni {

	class Window : private NonCopyable {
	public:

		Window();
		
		virtual ~Window();


		Window(Window&&) noexcept;
		Window& operator=(Window&&) noexcept;


		void setTitle(const std::string& newTitle);

		const std::string& title() const;


		void setSize(Size2 newSize);
		
		Size2 size() const;


		Point2 mousePos() const;

		bool keyState(Key k) const;

		bool buttonState(MouseButton b) const;

		void* nativeHandle() const;


		void show();


	private:
		virtual void onResize();
		
		virtual void onShow();
		virtual void onUpdate();
		virtual void onHide();

		virtual void onKeyDown(Key k);
		virtual void onKeyUp(Key k);

		virtual void onButtonDown(MouseButton b);
		virtual void onButtonUp(MouseButton b);
		virtual void onMouseMove();

		struct Impl;
		std::unique_ptr<Impl> m_impl;
	};

}