#include "jknlpch.h"
#include "Window.h"

namespace JKNL {

	static bool s_GLFWInitialized = false;

	WindowBase* WindowBase::Create(const WindowProps& props) {
		return new Window(props);
	}

	Window::Window(const WindowProps& props) {
		Init(props);
	}

	Window::~Window() {
		Shutdown();
	}

	void Window::Init(const WindowProps& props) {
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;
		m_Data.Title = props.Title;

		JKNL_CORE_INFO("Create window {0} ({1},{2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			//GLFW init ß∞‹‘Ú÷–∂œ
			JKNL_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void Window::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void Window::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool Window::IsVSync() const {
		return m_Data.VSync;
	}
}