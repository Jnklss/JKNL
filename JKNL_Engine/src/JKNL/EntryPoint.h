#pragma once

#ifdef JKNL_PLATFORM_WINDOWS

extern JKNL::Application* JKNL::CreateApplication();

int main(int argc, char** argv)
{
	auto app = JKNL::CreateApplication();
	app->Run();
	delete app;
}
#endif // JKNL_PLATFORM_WINDOWS
