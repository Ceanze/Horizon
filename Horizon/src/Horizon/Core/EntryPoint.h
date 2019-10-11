#pragma once


#ifdef HRZ_PLATFORM_WINDOWS

extern Horizon::Application* Horizon::createApplication();

int main(int argc, char** argv)
{
	Horizon::Logger::init();
	HRZ_ERROR("Testing");
	HRZ_CORE_INFO("Also testing");

	Horizon::Application* app = Horizon::createApplication();
	app->run();
	delete app;
}

#endif