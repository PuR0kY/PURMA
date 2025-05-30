#include <PURMA.h>

class Sandbox : public PURMA::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

PURMA::Application* PURMA::CreateApplication()
{
	return new Sandbox();
}