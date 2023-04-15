#ifndef COMPONENTCONCEPT_H
#define COMPONENTCONCEPT_H

#include <concepts>
#include <type_traits>

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"

namespace JEngine
{
    template<class T>
    concept Component = std::is_base_of_v<ComponentBase, T>;
}

#endif //!COMPONENTCONCEPT_H