#pragma once

#ifdef APTU_PLATFORM_WINDOWS
	#ifdef APTU_BUILD_DLL
		#define APTU_API __declspec(dllexport)
	#else
		#define APTU_API __declspec(dllimport)
	#endif
#else
	#error Apteuic only supports Windows!
#endif