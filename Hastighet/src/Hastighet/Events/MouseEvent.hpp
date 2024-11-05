#ifndef HE_MOUSE_EVENT_HPP
#define HE_MOUSE_EVENT_HPP

#include "Event.hpp"

namespace Hastighet{

    class HASTIGHET_API MouseButtonEvent : public Event{
    public:
        inline int GetMouseButton() const {return m_Button;}

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : m_Button(button){}

        int m_Button;
    };

    class HASTIGHET_API MouseButtonPressedEvent : public MouseButtonEvent{
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button){}

        std::string ToString() const override{
            std::stringstream stream;
            stream << "Button " << m_Button << " was pressed.";
            return stream.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class HASTIGHET_API MouseButtonReleasedEvent : public MouseButtonEvent{
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button){}

        std::string ToString() const override{
            std::stringstream stream;
            stream << "Button " << m_Button << " was released.";
            return stream.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

    class HASTIGHET_API MouseMovedEvent : public Event{
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y){}

        inline float GetX() const {return m_MouseX;}
        inline float GetY() const {return m_MouseY;}

        std::string ToString() const override{
            std::stringstream stream;
            stream << "Mouse position: (" << m_MouseX << ";" << m_MouseY << ")";
            return stream.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;

    };

    class HASTIGHET_API MouseScrolledEvent : public Event{
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset){}

        inline float GetXOffset() const {return m_XOffset;}
        inline float GetYOffset() const {return m_YOffset;}

        std::string ToString() const override{
            std::stringstream stream;
            stream << "Mouse scrolled by: (" << m_XOffset << ";" << m_YOffset << ")";
            return stream.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_XOffset, m_YOffset;
    };

}

#endif