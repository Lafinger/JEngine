#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>

#include "Runtime/Core/Base/PublicSingleton.h"

namespace JEngine
{
    template <template <typename> typename Derived, typename LibType>
    class LibraryBase : public PublicSingleton<Derived<LibType>>
    {
    public:
        void Add(const std::string& name, const Ref<LibType>& mem)
        {
            JENGINE_CORE_ASSERT(mLibrary.find(name) == mLibrary.end() && "Already have this member in Library!");
            mLibrary[name] = mem;
        }
        void Set(const std::string& name, const Ref<LibType>& mem)
        {
            JENGINE_CORE_ASSERT(mLibrary.find(name) != mLibrary.end() && "Can't find this member in Library!");
            mLibrary[name] = mem;
        }
        [[nodiscard]] Ref<LibType> Get(const std::string& name)
        {
            JENGINE_CORE_ASSERT(mLibrary.find(name) != mLibrary.end() && "Can't find this member in Library!");
            return mLibrary[name];
        }

    protected:
        std::unordered_map<std::string, Ref<LibType>> mLibrary;
    };

    template <typename LibType>
    class Library : public LibraryBase<Library, LibType>
    {
    public:
        Library();
    };
}

#endif //!LIBRARY_H