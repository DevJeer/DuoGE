#pragma once

#ifdef DUO_PLATFORM_WINDOWS

extern Duo::Application* Duo::CreateApplication();

int main() {
	printf("welcome to duo game engine...");
	auto app = Duo::CreateApplication();
	app->Run();
	delete app;
}

#endif