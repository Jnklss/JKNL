#include "jknlpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

#include <glad/glad.h>

namespace JKNL {

	//绑定事件的回调函数
#define BIND_EVENT_FUN(x) std::bind(&x , this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		JKNL_CORE_ASSERT(!s_Instance,"Application already exists!")
		s_Instance = this;

		m_Window = std::unique_ptr<WindowBase>(WindowBase::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLayer(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FUN(Application::OnWindowClose));

		//JKNL_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}

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

				for (Layer* layer : m_LayerStack)
					layer->OnUpdate();

				m_Window->OnUpdate();
			}
		}

		if (e.ISInCategory(EventCategoryInput)) {
			JKNL_CORE_TRACE(e);
		}
	}
}