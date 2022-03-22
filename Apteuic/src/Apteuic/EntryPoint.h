#pragma once

#ifdef APTU_PLATFORM_WINDOWS

extern Apteuic::Application* Apteuic::CreateApplication();

int main(int argc, char** argv)
{

	Apteuic::Log::Init();
	APTU_CORE_INFO("Initialized Core Logger");
	APTU_INFO("Initialized Client Logger");

	auto app = Apteuic::CreateApplication();
	app->Run();
	delete app;
}

#endif


