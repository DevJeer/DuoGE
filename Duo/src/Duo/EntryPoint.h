#pragma once

#ifdef DUO_PLATFORM_WINDOWS

extern Duo::Application* Duo::CreateApplication();

int main() {
	Duo::Log::Init();

	// log test
	DUO_CORE_INFO("Core Logger inited...");
	DUO_CORE_INFO("Hello Duo Core---{0}", 1);

	DUO_CLIENT_WARN("Client Logger inited...");
	DUO_CLIENT_WARN("Hello Duo Client---{0}", 2);


	auto app = Duo::CreateApplication();
	app->Run();
	delete app;
}

#endif