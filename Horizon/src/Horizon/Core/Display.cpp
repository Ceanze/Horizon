#include "hrzpch.h"
#include "Display.h"

Horizon::Display* Horizon::Display::disp = nullptr;

Horizon::Display* Horizon::Display::get()
{
	return disp;
}
