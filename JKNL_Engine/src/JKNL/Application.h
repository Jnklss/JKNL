#pragma once

#include "core.h"

namespace JKNL {
	class JKNL_API Application
	{
	public:
		Application();
		virtual ~Application();
		 
		virtual void Run() = 0;
	};

	//�ɿͻ��˶���
	Application* CreateApplication();

}
