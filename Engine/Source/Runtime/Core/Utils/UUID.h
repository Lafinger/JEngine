#ifndef UUID_H
#define UUID_H

#include <xhash>

namespace JEngine
{
	class UUID
	{
	public:
		UUID();
		UUID(uint64_t uuid);
		UUID(const UUID& other); 

		operator uint64_t() { return mUUID; }
		operator const uint64_t() const { return mUUID; }
	private:
		uint64_t mUUID;
	};
}

namespace std
{
	template<>
	struct hash<JEngine::UUID>
	{
		std::size_t operator()(const JEngine::UUID& uuid) const
		{
			return hash<uint64_t>()((uint64_t)uuid);
		}
	};
}

#endif //!UUID_H