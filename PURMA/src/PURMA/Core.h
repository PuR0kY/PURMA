#pragma once

#ifdef PUR_PLATFORM_WINDOWS
	#ifdef PUR_BUILD_DLL
		#define PUR_API __declspec (dllexport)
	#else
		#define PUR_API __declspec (dllimport)
	#endif
#else
	#error PURMA only supports Windows!
#endif