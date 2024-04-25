#pragma once

#include "core.h"
#include "JKNL/Events/Event.h"
#include "JKNL/Events/ApplicationEvent.h"
#include "Window/WindowBase.h"
#include "JKNL/Layer/LayerStack.h"

namespace JKNL {
	class JKNL_API Application
	{
	public:
		Application();
		virtual ~Application();
		 
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* overlay);

	private:
		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr<WindowBase> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	//由客户端定义
	Application* CreateApplication();

}
