#pragma once

#include "Horizon/Core/Display.h"

namespace Horizon
{
	class WindowsDisplay : Display
	{
	public:
		~WindowsDisplay() override;

		unsigned getWidth() const override;
		unsigned getHeight() const override;
		bool isFullscreen() const override;

		// Swap buffers
		virtual void update() override;
		virtual void* getNativeDisplay() const override;

	private:
		
	};
}