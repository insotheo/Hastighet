#ifndef HE_APPLICATION_EVENTS_HPP
#define HE_APPLICATION_EVENTS_HPP

#include "Event.hpp"

namespace Hastighet{

    class HASTIGHET_API WindowResizeEvent : public Event{
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height){}

        inline unsigned int GetWidth() const {return m_Width;}
        inline unsigned int GetHeight() const {return m_Height;}

        std::string ToString() const override{
            std::stringstream stream;
            stream << "Window size: (" << m_Width << ";" << m_Height << ")";
            return stream.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    protected:
        unsigned int m_Width, m_Height;
    };

    class HASTIGHET_API WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(unsigned int xPosition, unsigned int yPosition) : m_XPosition(xPosition), m_YPosition(yPosition){}

        inline unsigned int GetXPosition() const{ return m_XPosition; }
        inline unsigned int GetYPosition() const{ return m_YPosition; }

        std::string ToString() const override {
            std::stringstream stream;
            stream << "Window position: (" << m_XPosition << ";" << m_YPosition << ")";
            return stream.str();
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    protected:
        unsigned int m_XPosition, m_YPosition;
    };

    class HASTIGHET_API WindowCloseEvent : public Event{
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };


    class HASTIGHET_API WindowGotFocusEvent : public Event {
    public:
        WindowGotFocusEvent() {}

        EVENT_CLASS_TYPE(WindowGotFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HASTIGHET_API WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent(){}

        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HASTIGHET_API AppTickEvent : public Event{
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HASTIGHET_API AppUpdateEvent : public Event{
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HASTIGHET_API AppRenderEvent : public Event{
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}

#endif