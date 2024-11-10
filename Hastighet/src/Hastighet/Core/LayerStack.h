#ifndef HE_LAYER_STACK_H
#define HE_LAYER_STACK_H

#include "Core.h"
#include "Layer.h"

#include <vector>

namespace Hastighet {

	class HASTIGHET_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}

#endif // !HE_LAYER_STACK_H
