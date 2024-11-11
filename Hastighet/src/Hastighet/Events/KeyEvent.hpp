#ifndef HE_KEY_EVENT_HPP
#define HE_KEY_EVENT_HPP

#include "Event.hpp"

namespace Hastighet{
    
    class HASTIGHET_API KeyEvent : public Event{

    public:
        inline int GetKeyCode() const {return m_KeyCode;}
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) {}
        int m_KeyCode;

    };

    class HASTIGHET_API KeyPressedEvent : public KeyEvent{
        
    public:
        KeyPressedEvent(int keycode, int counter) : KeyEvent(keycode), m_RepeatCounter(counter){}
        inline int GetRepeatCount() const {return m_RepeatCounter;}

        std::string ToString() const override{
            std::stringstream stream;
            stream << m_KeyCode << " pressed for " << m_RepeatCounter << " times.";
            return stream.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    protected:
        int m_RepeatCounter;
    };

    class HASTIGHET_API KeyReleasedEvent : public KeyEvent{
        
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode){}

        std::string ToString() const override{
            std::stringstream stream;
            stream << m_KeyCode << " was released.";
            return stream.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class HASTIGHET_API KeyTypedEvent : public KeyEvent {
    public:
        KeyTypedEvent(int keycode) : KeyEvent(keycode){}


        std::string ToString() const override {
            std::stringstream stream;
            stream << "'" << (char)m_KeyCode << "' was typed!";
            return stream.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };

}

#endif