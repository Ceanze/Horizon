#pragma once

#ifdef HRZ_PLATFORM_WINDOWS
	#ifdef HRZ_BUILD_DLL
		#define HORIZON_API __declspec(dllexport)
	#else
		#define HORIZON_API __declspec(dllimport)
	#endif
#else
	#error Nah cant do that
#endif