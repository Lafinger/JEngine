#include "Runtime/Core/Base/Header.h"
// #include "Runtime/JEngine.h"
#include "Runtime/Application/Framework/Application.h"
#include "Editor/EditorLayer.h"
// #include "Editor/Test/RawLayer.h"
int main() 
{
    std::cout << "start" << std::endl;

    JEngine::Application::GetInstance().Init("JEngine Editor");
    // JEngine::Application::GetInstance().PushLayer(new JEngine::RawLayer());
    JEngine::Application::GetInstance().PushLayer(new JEngine::EditorLayer());
    JEngine::Application::GetInstance().Run();
    JEngine::Application::GetInstance().Clean();

    return 0;
}