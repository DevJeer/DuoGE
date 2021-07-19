#pragma once

#ifdef DUO_PLATFORM_WINDOWS
	#ifdef DUO_BUILD_DLL
		#define DUO_API __declspec(dllexport)
	#else
		#define DUO_API __declspec(dllexport)
	#endif // DUO_BUILD_DLL
#else
	#error DUO only support windows!
#endif