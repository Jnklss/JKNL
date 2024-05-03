
#include "JKNL.h"

class ExampleLayer : public JKNL::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		JKNL_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(JKNL::Event& event)
	{
		JKNL_CLIENT_TRACE("{0}", event);
	}
};

class SandBox : public JKNL::Application 
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverLayer(new JKNL::ImGuiLayer());
	}

	~SandBox()
	{

	}



private:
	bool m_Running = true;
	std::unique_ptr<JKNL::WindowBase> m_Window;
};

JKNL::Application* JKNL::CreateApplication()
{
	return new SandBox();
}