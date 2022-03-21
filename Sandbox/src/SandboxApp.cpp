#include "Apteuic.h"

class Sandbox : public Apteuic::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Apteuic::Application* Apteuic::CreateApplication()
{
	return new Sandbox();
}