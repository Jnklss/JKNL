#pragma once

#include "Event.h"

namespace JKNL {

	class JKNL_API MouseEvent :public Event {
	public:
		MouseEvent() { }
		MouseEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseEvent: X(" << m_MouseX << "), Y(" << m_MouseY << ")";
			return ss.str();
		}

	protected:
		float m_MouseX, m_MouseY;
	};

	//移动事件
	class JKNL_API MouseMovedEvent : public MouseEvent {
	public:
		MouseMovedEvent(float x, float y) : MouseEvent(x, y) { }
		
		EVENT_CLASS_TYPE(MouseMoved)

	};

	//滚动事件
	class JKNL_API MouseScrolledEvent : public MouseEvent {
	public:
		MouseScrolledEvent(float x, float y,float xOffset,float yOffset) 
			: MouseEvent(x,y)
			,m_XOffset(xOffset), m_YOffset(yOffset) { }

		MouseScrolledEvent(float xOffset, float yOffset) 
		: m_XOffset(xOffset), m_YOffset(yOffset) { }

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		float m_XOffset, m_YOffset;
	};
	
	class JKNL_API MouseButtonEvent : public Event {
	public :
		inline int GetButton() { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

	protected:
		int m_Button;

		MouseButtonEvent(int button) : m_Button(button) { }
	};

	//点击事件
	class JKNL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) 
			: MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed)

		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

	};

	//释放事件
	class JKNL_API MouseButtonRelaesed : public MouseButtonEvent {
	public:
		MouseButtonRelaesed(int button) :
			MouseButtonEvent(button) { }

		EVENT_CLASS_TYPE(MouseButtonReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
	};
}