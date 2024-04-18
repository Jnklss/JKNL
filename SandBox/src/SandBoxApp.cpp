#include "JKNL.h"

class SandBox : public JKNL::Application 
{
public:
	SandBox()
	{
		m_Window = std::unique_ptr<JKNL::WindowBase>(JKNL::WindowBase::Create());
	}

	~SandBox()
	{

	}

	//void Run() override
	
		//JKNL::Log::Init();
		////JKNL::Log::GetCoreLogger()->warn("Init Log");
		//JKNL_CORE_WARN("Init Log");
		//JKNL_CORE_TRACE("Trace");
		////JKNL::Log::GetClientLogger()->info("Client Log");
		//int a = 55;
		//JKNL_CLIENT_INFO("Client Log var = {0}",a);
		//JKNL_CLIENT_ERROR("Error");
		//JKNL_CLIENT_CRITICAL("CRITICAL");

		/*JKNL::WindowsResizeEvent wre(1200, 800);
		if (wre.ISInCategory(JKNL::EventCategoryWindows)) {
			JKNL_CLIENT_TRACE(wre);
		}

		if (wre.ISInCategory(JKNL::EventCategoryInput)){
			JKNL_CLIENT_TRACE(wre);
		}

		while (m_Running)
		{
			m_Window->OnUpdate();

		}*/

private:
	bool m_Running = true;
	std::unique_ptr<JKNL::WindowBase> m_Window;
};

JKNL::Application* JKNL::CreateApplication()
{
	return new SandBox();
}