#pragma once

#include "core.h"
#include "JKNL/Events/ApplicationEvent.h"
#include "Window/WindowBase.h"

namespace JKNL {
	class JKNL_API Application
	{
	public:
		Application();
		virtual ~Application();
		 
		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr<WindowBase> m_Window;
		bool m_Running = true;
	};

	//由客户端定义
	Application* CreateApplication();

}
