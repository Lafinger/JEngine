#ifndef TIMESTEP_HPP
#define TIMESTEP_HPP

namespace JEngine
{
    class Timestep
    {
    public:
        Timestep(float time = 0.0f)
            : mTime(time)
        {
        }

        operator float() const { return mTime; }

        [[nodiscard]] float GetSeconds() const { return mTime; }
        [[nodiscard]] float GetMilliseconds() const { return mTime * 1000.0f; }
    private:
        float mTime;
    };
}

#endif //!TIMESTEP_HPP