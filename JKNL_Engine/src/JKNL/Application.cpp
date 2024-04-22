#include "jknlpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace JKNL {
	Application::Application()
	{
		m_Window = std::unique_ptr<WindowBase>(WindowBase::Create());
	}

	Application::~Application()
	{
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

		while(true){ }
	}
}