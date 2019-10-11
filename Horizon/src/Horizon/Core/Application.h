#pragma once

#include "Core.h"
#include "Horizon/Events/EventBus.h"

namespace Horizon {

	class HORIZON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in the client
	Application* createApplication();
	
}