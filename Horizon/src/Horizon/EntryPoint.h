#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern Horizon::Application* Horizon::createApplication();

int main(int argc, char** argv)
{
	auto app = Horizon::createApplication();
	app->run();
	delete app;
}

#endif