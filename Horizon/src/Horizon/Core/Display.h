#pragma once

#include "hrzpch.h"

namespace Horizon
{
	struct DisplayProps
	{
		std::string title;
		unsigned width;
		unsigned height;
		bool fullscreen;

		DisplayProps(const std::string& title = "Hazel Engine",
			unsigned int width = 1280,
			unsigned int height = 720,
			bool fullscreen = false)
			: title(title), width(width), height(height), fullscreen(fullscreen)
		{
		}
	};

	class Display
	{
	public:
		static Display* create(const DisplayProps& props = DisplayProps());
		static Display* get();
		virtual ~Display() = default;

		virtual unsigned getWidth() const = 0;
		virtual unsigned getHeight() const = 0;
		virtual bool isFullscreen() const = 0;
		virtual bool isOpen() const = 0;

		// Swap buffers
		virtual void update() = 0;
		virtual void* getNativeDisplay() const = 0;

	private:
		static Display* disp;
	};

}