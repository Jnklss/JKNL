#include "JKNL.h"

class SandBox : public JKNL::Application 
{
public:
	SandBox(){ }

	~SandBox()
	{

	}

	void Run() override
	{
		JKNL::Log::Init();
		JKNL::Log::GetCoreLogger()->warn("Init Log");
		JKNL::Log::GetClientLogger()->info("Client Log");
		while (true)
		{

		}
	}
};

JKNL::Application* JKNL::CreateApplication()
{
	return new SandBox();
}