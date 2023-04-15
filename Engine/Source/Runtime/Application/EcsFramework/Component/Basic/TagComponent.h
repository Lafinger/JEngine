#ifndef TAGCOMPONENT_H
#define TAGCOMPONENT_H

#include <string>

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"

namespace JEngine
{
    class TagComponent : public ComponentBase
    {
    public:
        std::string Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag)
            : Tag(tag) {}
    };
}

#endif //!TAGCOMPONENT_H