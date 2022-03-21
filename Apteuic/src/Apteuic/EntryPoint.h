#pragma once

#ifdef APTU_PLATFORM_WINDOWS

extern Apteuic::Application* Apteuic::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Apteuic::CreateApplication();
	app->Run();
	delete app;
}

#endif