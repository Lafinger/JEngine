#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include <filesystem>

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"
#include "Runtime/Application/Mesh/Mesh.h"


namespace JEngine
{
    class MeshComponent : public ComponentBase
    {
    public:
		MeshComponent() { mMesh = CreateRef<Mesh>(); };
		MeshComponent(const MeshComponent&) = default;
		MeshComponent(const std::string & path)
			: Path(path), mMesh(CreateRef<Mesh>(path))
		{
		}
		//MeshComponent(const std::filesystem::path& path)
		//	: Path(path)
		//{
		//}

		std::string Path = "None";
		Ref<Mesh> mMesh;
    };
}

#endif //!MESHCOMPONENT_H