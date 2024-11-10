#ifndef HE_LAYER_H
#define HE_LAYER_H

#include "Core.h"

#include "Hastighet/Events/Event.hpp"

namespace Hastighet {

	class HASTIGHET_API Layer {
	public:
		Layer(const std::string& name = "HE_Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DBGName; }
	protected:
		std::string m_DBGName;
	};

}

#endif // !HE_LAYER_H
