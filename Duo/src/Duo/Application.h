#pragma once
#include "Core.h"

namespace Duo {

	class DUO_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	// To be Define in Client
	Application* CreateApplication();
}