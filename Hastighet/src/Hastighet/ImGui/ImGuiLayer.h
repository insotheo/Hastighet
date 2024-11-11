#ifndef HE_IM_GUI_H
#define HE_IM_GUI_H

#include "Hastighet/Core/Layer.h"

#include "Hastighet/Events/Event.hpp"
#include "Hastighet/Events/ApplicationEvents.hpp"
#include "Hastighet/Events/MouseEvent.hpp"
#include "Hastighet/Events/KeyEvent.hpp"

namespace Hastighet {

	class HASTIGHET_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		float m_Time = 0.0f;

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnWindowResizedEvent(WindowResizeEvent& event);

	};

}

#endif