#include <Horizon.h>

class Sandbox : public Horizon::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Horizon::Application* Horizon::createApplication()
{
	return new Sandbox();
}