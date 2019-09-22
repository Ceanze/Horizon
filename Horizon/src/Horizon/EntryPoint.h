#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern Horizon::Application* Horizon::createApplication();

int main(int argc, char** argv)
{
	Horizon::Logger::init();
	HZ_ERROR("Testing");
	HZ_CORE_INFO("Also testing");

	Horizon::Application* app = Horizon::createApplication();
	app->run();
	delete app;
}

#endif