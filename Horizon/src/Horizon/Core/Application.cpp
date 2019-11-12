#include "hrzpch.h"
#include "Application.h"
#include "Display.h"

#include <GLFW/glfw3.h>

namespace Horizon {

	Application::Application()
	{
		this->display = Display::create();
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		while (this->running && this->display->isOpen())
		{
			this->display->update();
		}
	}
}