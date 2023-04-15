#ifndef UNIFORMBUFFER_H
#define UNIFORMBUFFER_H

#include "Runtime/Core/Base/Base.h"

namespace JEngine 
{
	class UniformBuffer
	{
	public:
		virtual ~UniformBuffer() {}
		virtual void SetData(const void* data, uint32_t size, uint32_t offset = 0) = 0;

		static Ref<UniformBuffer> Create(uint32_t size, uint32_t binding);
	};
}

#endif //!UNIFORMBUFFER_H
