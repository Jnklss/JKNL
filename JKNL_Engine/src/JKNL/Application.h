#pragma once

#include "core.h"

namespace JKNL {
	class JKNL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//�ɿͻ��˶���
	Application* CreateApplication();

}
