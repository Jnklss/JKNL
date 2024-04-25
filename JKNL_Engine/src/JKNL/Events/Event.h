#pragma once

#include "JKNL/core.h"

namespace JKNL {

	//�¼�ϵͳ�������ģ����¼�����ʱ�������̱�����ʹ���

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus , WindowMoved,				//�����¼�
		AppTick, AppUpdate, AppRender,										//Ӧ���¼�
		KeyPressed , KeyReleased,											//�����¼�
		MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased	//����¼�
	};

	enum EventCategory { //���ò�ͬ�¼������λ��
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
		
	};

//ʹ�ú�������ɶ�Ӧ�ĺ���
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
						       virtual const char* GetName() const override { return #type; }	

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	//Event����
	class JKNL_API Event {
		
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool ISInCategory(EventCategory category) { //ȷ����������˲�ͬ�¼�
			return GetCategoryFlags() & category; 
		}
			
		bool Handled = false;	
	};

	//�¼�������
	class JKNL_API EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>; //ע��ص�����
	
	public:
		EventDispatcher(Event& event) : m_Event(event) {

		}

		template<typename T>
		bool Dispatch(EventFn<T> func) {	//�����¼����͵��ȴ�����
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.Handled |= func(static_cast<T&>(m_Event)); //����func�����ص�m_Handled
				return true;
			}
			return false;
		}
	
	private:
		Event& m_Event;

	};

	//����Event��<<�����������
	inline std::ostream& operator<<(std::ostream& os, const Event& event) {
		return os << event.ToString();
	}

}
