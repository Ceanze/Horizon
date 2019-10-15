#include "hrzpch.h"
#include "Application.h"
#include "Display.h"

#include <GLFW/glfw3.h>

namespace Horizon {

	Application::Application()
	{
		Display::create();
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		while (true);
	}
}