#ifndef WINDOWSPLATFORMUTILS_H
#define WINDOWSPLATFORMUTILS_H

#include <string>

namespace JEngine
{
    class FileDialogs
    {
    public:
        // These return empty strings if cancelled
        static std::string OpenFile(const char* filter);
        static std::string SaveFile(const char* filter);
    };
}

#endif //!WINDOWSPLATFORMUTILS_H