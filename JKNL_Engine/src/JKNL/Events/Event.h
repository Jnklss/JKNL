#pragma once

#include "JKNL/core.h"

namespace JKNL {

	//事件系统是阻塞的，当事件发生时必须立刻被分配和处理

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus , WindowMoved,				//窗口事件
		AppTick, AppUpdate, AppRender,										//应用事件
		KeyPressed , KeyReleased,											//键盘事件
		MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased	//鼠标事件
	};

	enum EventCategory { //设置不同事件的类别位数
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
		
	};

//使用宏快速生成对应的函数
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
						       virtual const char* GetName() const override { return #type; }	

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	//Event基类
	class JKNL_API Event {
		
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool ISInCategory(EventCategory category) { //确定类别来过滤不同事件
			return GetCategoryFlags() & category; 
		}
			
		bool Handled = false;	
	};

	//事件调度器
	class JKNL_API EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>; //注册回调函数
	
	public:
		EventDispatcher(Event& event) : m_Event(event) {

		}

		template<typename T>
		bool Dispatch(EventFn<T> func) {	//根据事件类型调度处理函数
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.Handled |= func(static_cast<T&>(m_Event)); //调用func并返回到m_Handled
				return true;
			}
			return false;
		}
	
	private:
		Event& m_Event;

	};

	//重载Event的<<输出流操作符
	inline std::ostream& operator<<(std::ostream& os, const Event& event) {
		return os << event.ToString();
	}

}
