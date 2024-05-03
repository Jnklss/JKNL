#pragma once

#include "WindowBase.h"

#include "JKNL/Events/ApplicationEvent.h"
#include "JKNL/Events/KeyEvent.h"
#include "JKNL/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace JKNL {

	class Window : public WindowBase
	{
	public:
		Window(const WindowProps& props);
		virtual ~Window();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; };
		inline unsigned int GetHeight() const override { return m_Data.Height; };
		
		inline void SetEventCallback(const EventCallbackFun& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFun EventCallback;
		};

		WindowData m_Data;

		GLFWwindow* m_Window;

	};

}

