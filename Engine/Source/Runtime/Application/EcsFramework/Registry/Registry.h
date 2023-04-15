#ifndef REGISTRY_H
#define REGISTRY_H

#include <entt.hpp>

namespace JEngine
{
    // TODO
    // A wrapper of entt::registry

    class Registry final
    {
    public:
        Registry() = default;
        ~Registry() = default;
    public:

    private:
        entt::registry mRegistry;
    };
}

#endif //!REGISTRY_H