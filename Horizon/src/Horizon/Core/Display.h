#pragma once

#include "hrzpch.h"

namespace Horizon
{

	class Display
	{
	public:
		static Display* create(unsigned width = 720, unsigned height = 1024, std::string title = "Default Display", bool fullscreen = false);
		static Display* get();
		virtual ~Display() = default;

		virtual unsigned getWidth() const = 0;
		virtual unsigned getHeight() const = 0;
		virtual bool isFullscreen() const = 0;

		// Swap buffers
		virtual void update() = 0;
		virtual void* getNativeDisplay() const = 0;

	private:
		static Display* disp;
	};

}