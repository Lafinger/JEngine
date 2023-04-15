#include <random>
#include <unordered_map>

#include "Runtime/Core/Base/Header.h"

#include "Runtime/Core/Utils/UUID.h"


namespace JEngine
{
	static std::random_device sRandomDevice;
	static std::mt19937_64 sEngine(sRandomDevice());
	static std::uniform_int_distribution<uint64_t> sUniformDistribution;

	UUID::UUID()
		: mUUID(sUniformDistribution(sEngine))
	{
	}

	UUID::UUID(uint64_t uuid)
		: mUUID(uuid)
	{
	}

	UUID::UUID(const UUID& other)
		: mUUID(other.mUUID)
	{
	}

}
