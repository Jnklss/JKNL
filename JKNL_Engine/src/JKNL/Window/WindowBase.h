#pragma once

#include "jknlpch.h"


#include "JKNL/Events/Event.h"

namespace JKNL {

	struct WindowProps {	//窗口数据结构
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "JKNL_Engine",
			unsigned int width = 1600 , unsigned int height = 800)
			:Title(title),Width(width),Height(height) 
		{ }

	};

	class JKNL_API WindowBase {	//窗口基类
	public:
		using EventCallbackFun = std::function<void(Event&)>;	//设置窗口的事件回调函数

		virtual ~WindowBase()
		{ }

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const  = 0;

		//窗口属性
		virtual void SetEventCallback(const EventCallbackFun& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		
		static WindowBase* Create(const WindowProps& props = WindowProps());
	};
}