#include <Duo.h>

class SandboxApp : public Duo::Application {
public:
	SandboxApp() 
	{
	}

	virtual ~SandboxApp()
	{
	}
};

Duo::Application* Duo::CreateApplication() {
	SandboxApp* sandbox = new SandboxApp();
	return sandbox;
}