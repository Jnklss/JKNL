#pragma once

#ifdef JKNL_PLATFORM_WINDOWS

extern JKNL::Application* JKNL::CreateApplication();

int main(int argc, char** argv)
{
	JKNL::Log::Init();
	JKNL_CORE_INFO("Init Core Log");
	JKNL_CLIENT_INFO("Init App Log");

	auto app = JKNL::CreateApplication();
	app->Run();
	delete app;
}
#endif // JKNL_PLATFORM_WINDOWS
