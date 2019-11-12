#pragma once

#include "Horizon/Core/Display.h"

struct GLFWwindow;

namespace Horizon
{
	class GLDisplay : public Display
	{
	public:
		GLDisplay(const DisplayProps& props = DisplayProps());
		~GLDisplay();

		unsigned getWidth() const override;
		unsigned getHeight() const override;
		bool isFullscreen() const override;
		bool isOpen() const override;

		// Swap buffers
		void update() override;
		void* getNativeDisplay() const override;

	private:
		void init(const DisplayProps& props = DisplayProps());

		GLFWwindow* window;
		DisplayProps props;
	};
}