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
		//JKNL::Log::GetCoreLogger()->warn("Init Log");
		JKNL_CORE_WARN("Init Log");
		JKNL_CORE_TRACE("Trace");
		//JKNL::Log::GetClientLogger()->info("Client Log");
		int a = 55;
		JKNL_CLIENT_INFO("Client Log var = {0}",a);
		JKNL_CLIENT_ERROR("Error");
		JKNL_CLIENT_CRITICAL("CRITICAL");

		while (true)
		{

		}
	}
};

JKNL::Application* JKNL::CreateApplication()
{
	return new SandBox();
}