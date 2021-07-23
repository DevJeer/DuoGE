#include "duopch.h"
#include "Application.h"
#include "Duo/Events/ApplicationEvent.h"
#include "Duo/Log.h"

namespace Duo {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(Duo::EventCategory::EventCategoryApplication))
		{
			DUO_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			DUO_TRACE(e.ToString());
		}
		while (true);
	}
}