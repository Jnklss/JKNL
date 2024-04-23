#include "jknlpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace JKNL {

	//绑定事件的回调函数
#define BIND_EVENT_FUN(x) std::bind(&x , this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<WindowBase>(WindowBase::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FUN(Application::OnWindowClose));

		JKNL_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run() 
	{
		WindowsResizeEvent e(m_Window->GetWidth(), m_Window->GetHeight());
		if (e.ISInCategory(EventCategoryApplication)) {
			JKNL_CORE_TRACE(e);
			while (m_Running)
			{
				glClearColor(1, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				m_Window->OnUpdate();
			}
		}

		if (e.ISInCategory(EventCategoryInput)) {
			JKNL_CORE_TRACE(e);
		}

		
	}
}