#pragma once

#include "Core.h"
#include "Horizon/Events/EventBus.h"

namespace Horizon {

	class Display;

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		Display* display = nullptr;
		bool running = true;
	};

	// To be defined in the client
	Application* createApplication();
	
}