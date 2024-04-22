#pragma once

#include "Event.h"

namespace JKNL {
	class JKNL_API WindowsResizeEvent :public Event {
	public:
		WindowsResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) { }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class JKNL_API WindowClosedEvent :public Event {
	public:
		WindowClosedEvent() { }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)

	private:

	};

	class JKNL_API WindowFocusEvent :public Event {
	public:
		WindowFocusEvent() { }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowFocus)

	private:

	};

	class JKNL_API WindowMovedEvent : public Event {
	public:
		WindowMovedEvent() { }

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:

	};

	class JKNL_API AppTickEvent :public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:

	};

	class JKNL_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:

	};

	class JKNL_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:

	};
}