#pragma once

#include "Event.h"

namespace JKNL{
	class JKNL_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		//�����¼��ͼ����¼��ϲ�Ϊһ��
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		//���µļ�
		int m_KeyCode;

		KeyEvent(int keyCode) : m_KeyCode(keyCode) { }
	};

	class JKNL_API KeyPressedEvent : public KeyEvent {
	public:
		inline int GetRepeatCount() const { return m_RepeatCount; }

		KeyPressedEvent(int keyCode,int repeatedCount) 
			: KeyEvent(keyCode) , m_RepeatCount(m_RepeatCount)
		{ }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		//�ظ�����
		int m_RepeatCount;
	};

	class JKNL_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) { }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	private:

	};
}