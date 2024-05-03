#include "jknlpch.h"
#include "Window.h"


#include <glad/glad.h>


namespace JKNL {

	static bool s_GLFWInitialized = false;

	//GLFW错误回调函数
	static void GLFWErrorCallback(int error, const char* description)
	{
		JKNL_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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

		JKNL_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			//GLFW init失败则中断
			JKNL_CORE_ASSERT(success, "Could not intialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JKNL_CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//设置GLFW回调函数
		glfwSetWindowSizeCallback(m_Window, 
			[](GLFWwindow* window, int width, int height)
			{
				//通过GLFWuser指针获得窗口对象
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowsResizeEvent wevent(width, height);
				data.EventCallback(wevent);
			});

		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowClosedEvent wevent;
				data.EventCallback(wevent);
			});

		glfwSetKeyCallback(m_Window,
			[](GLFWwindow* window, int key, int scancode, int action,int mods )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent kevent(key, 0);
						data.EventCallback(kevent);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent kevent(key);
						data.EventCallback(kevent);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent kevent(key,1);
						data.EventCallback(kevent);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window, int button, int action, int mods) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent mevent(button);
						data.EventCallback(mevent);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonRelaesedEvent mevent(button);
						data.EventCallback(mevent);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window,
			[](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent mevent((float)xOffset, (float)yOffset);
				data.EventCallback(mevent);
			});

		glfwSetCursorPosCallback(m_Window,
			[](GLFWwindow* window, double xpos, double ypos) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent mevent((float)xpos, (float)ypos);
				data.EventCallback(mevent);
			});
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