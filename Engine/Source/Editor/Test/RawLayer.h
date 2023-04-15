#ifndef RAWLAYER_H
#define RAWLAYER_H

#include "Runtime/JEngine.h"

namespace JEngine
{
    class RawLayer : public Layer
    {
    public:
        void OnUpdate(Timestep ts) override;
    };
}

#endif //!RAWLAYER_H