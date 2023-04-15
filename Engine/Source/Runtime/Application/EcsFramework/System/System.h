#ifndef SYSTEM_H
#define SYSTEM_H

#include "Runtime/Core/Utils/Timestep.hpp"
#include "Runtime/Application/EcsFramework/Level/Level.h"
#include "Runtime/Application/Camera/EditorCamera.h"

namespace JEngine
{
    class System
    {
    public:
        System() = delete;
        System(Level* level) : mLevel(level) {}
        virtual ~System() = default;
    public:
        virtual void OnUpdateEditor(Timestep ts, EditorCamera& camera) {};
        virtual void OnUpdateRuntime(Timestep ts) {}
        virtual void OnRuntiemStart() {}
        virtual void OnRuntimeStop() {}
    protected:
        Level* mLevel = nullptr;
    };
}

#endif //!SYSTEM_H