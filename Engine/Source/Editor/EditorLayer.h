#ifndef EDITORLAYER_H
#define EDITORLAYER_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Runtime/Application/EcsFramework/Level/Level.h"

#include "Runtime/JEngine.h"
#include "Runtime/Application/Framework/Layer.hpp"
#include "Runtime/Application/Renderer/Framebuffer.h"
#include "Runtime/Application/Camera/EditorCamera.h"
#include "Runtime/Application/Renderer/RenderPass.h"
#include "Runtime/Application/Renderer/Shader.h"

#include "Editor/Panels/SceneHierarchyPanel.h"
#include "Editor/Panels/ContentBrowserPanel.h"
#include "Editor/Panels/SceneSettingsPanel.h"

namespace JEngine
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        virtual ~EditorLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void OnUpdate(Timestep ts) override;
        virtual void OnImGuiRender() override;
        void OnEvent(Event& e) override;
    private:
        bool OnKeyPressed(KeyPressedEvent& e);
        bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

        void NewScene();
        void OpenScene();
        void OpenScene(const std::filesystem::path& path);
        void SaveScene();
        void SaveSceneAs();

		// void SerializeScene(Ref<Level> scene, const std::filesystem::path& path);

		void OnScenePlay(); 
		void OnSceneStop();

		void OnDuplicateEntity();

		// UI Panels
		void UI_Toolbar();

		void LoadDefaultEditorConfig();
    private:
        // Temp
        Ref<VertexArray> mSquareVA;
        Ref<Shader> mFlatColorShader;
        Ref<Framebuffer> mFramebuffer;

        Ref<RenderPass> mRenderPass;

        Ref<Level> mActiveScene;
        // Ref<Level> mEditorScene;
        
		std::filesystem::path mEditorScenePath;

        // Entity mSquareEntity;
        // Entity mCameraEntity;
        // Entity mSecondCamera;

		Entity mHoveredEntity;

        bool mPrimaryCamera = true;

		EditorCamera mEditorCamera;

        bool mViewportFocused = false, mViewportHovered = false;

		glm::vec2 mViewportBounds[2];

        glm::vec4 mSquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		int mGizmoType = -1;

        // viewprot
        bool mViewprotCollapsed = false;

        // Panels
        SceneHierarchyPanel mSceneHierarchyPanel;
		ContentBrowserPanel mContentBrowserPanel;
        SceneSettingsPanel mSceneSettingsPanel;
    };
}

#endif //!EDITORLAYER_H