#pragma once

#include "Core.h"

namespace Apteuic {

	class APTU_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}