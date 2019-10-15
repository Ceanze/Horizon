#include "hrzpch.h"
#include "GLDisplay.h"

#include <GLFW/glfw3.h>

Horizon::Display* Horizon::Display::create(const DisplayProps& props)
{
	// Set the static display to GLDisplay
	disp = new GLDisplay(props);
	return disp;
}

static void GLFWErrorCallback(int error, const char* description)
{
	HRZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
}

Horizon::GLDisplay::GLDisplay(const DisplayProps& props)
{
	init(props);
}

Horizon::GLDisplay::~GLDisplay()
{
	glfwDestroyWindow(window);
}

unsigned Horizon::GLDisplay::getWidth() const
{
	return this->props.width;
}

unsigned Horizon::GLDisplay::getHeight() const
{
	return this->props.height;
}

bool Horizon::GLDisplay::isFullscreen() const
{
	return this->props.fullscreen;
}

void Horizon::GLDisplay::update()
{
	glfwSwapBuffers(this->window);
}

void* Horizon::GLDisplay::getNativeDisplay() const
{
	return this->window;
}

void Horizon::GLDisplay::init(const DisplayProps& props)
{
	this->props.fullscreen = props.fullscreen;
	this->props.height = props.height;
	this->props.width = props.width;
	this->props.title = props.title;

	int success = glfwInit();
	if (!success)
	{
		HRZ_CORE_FATAL("Failed to init GLFW!");
		glfwTerminate();
		return;
	}

	HRZ_CORE_INFO("Initilizaed GLFW successfully!");

	glfwSetErrorCallback(GLFWErrorCallback);

	glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
}
