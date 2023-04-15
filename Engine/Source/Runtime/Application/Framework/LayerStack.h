#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Runtime/Core/Base/Base.h"
#include "Runtime/Application/Framework/Layer.hpp"

#include <vector>

namespace JEngine 
{

	class JENGINE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return mLayers.begin(); }
		std::vector<Layer*>::iterator end() { return mLayers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return mLayers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return mLayers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return mLayers.begin(); }
		std::vector<Layer*>::const_iterator end() const { return mLayers.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return mLayers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return mLayers.rend(); }
	private:
		std::vector<Layer*> mLayers;
		unsigned int mLayerInsertIndex = 0;
	};

}

#endif //!LAYERSTACK_H
