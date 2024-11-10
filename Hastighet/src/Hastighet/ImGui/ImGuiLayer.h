#ifndef HE_IM_GUI_H
#define HE_IM_GUI_H

#include "Hastighet/Core/Layer.h"

#include "Hastighet/Events/Event.hpp"

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

	};

}

#endif