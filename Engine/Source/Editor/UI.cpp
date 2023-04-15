// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include <imgui/imgui_internal.h>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <stdio.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#include <vector>
#include <string>

// window handle
static bool bShowViewport = true;
static bool bShowContentBrowser = true;
static bool bShowSceneHierachy = true;
static bool bShowProperties = true;
static bool bShowStats = false;
static bool bShowEngineSettings = true;
static bool bShowSceneSettings = true;
static bool bShowSRT = true;

// help Window handle
static bool bShowTutorial = false;
static bool bShowAboutMe = false;
static bool bShowDemoImGui = false;

void engineEditor();

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
	// Setup window
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

	// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
	// GL ES 2.0 + GLSL 100
	const char* glsl_version = "#version 100";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
	// GL 3.2 + GLSL 150
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
	// GL 3.0 + GLSL 450
	const char* glsl_version = "#version 450";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1920, 1280, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
	if (window == NULL)
		return 1;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	//io.ConfigViewportsNoAutoMerge = true;
	//io.ConfigViewportsNoTaskBarIcon = true;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
	// - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
	// - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
	// - Read 'docs/FONTS.md' for more instructions and details.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//IM_ASSERT(font != NULL);

	// Our state
 /*   bool show_demo_window = true;
	bool show_another_window = false;*/
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		engineEditor();

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Update and Render additional Platform Windows
		// (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
		//  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void engineEditor()
{
	static bool bChangeDim = false;

	// ----DockSpace Begin----
	static bool dockspaceOpen = true;
	static bool opt_fullscreen = true;
	static bool opt_padding = false;
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

	// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
	// because it would be confusing to have two docking targets within each others.
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	if (opt_fullscreen)
	{
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	}
	else
	{
		dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
	}

	// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
	// and handle the pass-thru hole, so we ask Begin() to not render a background.
	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;

	// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
	// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
	// all active windows docked into it will lose their parent and become undocked.
	// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
	// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
	if (!opt_padding)
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
	if (!opt_padding)
		ImGui::PopStyleVar();

	if (opt_fullscreen)
		ImGui::PopStyleVar(2);

	// Submit the DockSpace
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	float minWinSizeX = style.WindowMinSize.x;
	style.WindowMinSize.x = 110.0f;
	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	{
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	}

	style.WindowMinSize.x = minWinSizeX;

	// ----MenuBar Begin----
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New", "Ctrl+N")) {}

			if (ImGui::MenuItem("Open...", "Ctrl+O")) {}

			if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S")) {}

			if (ImGui::MenuItem("Exit", NULL, false))


				ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Window"))
		{
			ImGui::MenuItem("Viewport", NULL, &bShowViewport);
			ImGui::MenuItem("Content Browser", NULL, &bShowContentBrowser);
			ImGui::MenuItem("Level Hierachy", NULL, &bShowSceneHierachy);
			ImGui::MenuItem("Properties", NULL, &bShowProperties);
			ImGui::MenuItem("Stats", NULL, &bShowStats);
			ImGui::MenuItem("Engine Settings", NULL, &bShowEngineSettings);
			ImGui::MenuItem("Environment Settings", NULL, &bShowSceneSettings);

			if (ImGui::MenuItem("Load Default Layout")) {}

			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Help"))
		{
			ImGui::MenuItem("Tutorial", NULL, &bShowTutorial);
			ImGui::MenuItem("About Me", NULL, &bShowAboutMe);
			ImGui::MenuItem("Demo ImGui", NULL, &bShowDemoImGui);

			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}
	// ----MenuBar End----

	// ----Windows Begin----
	if (bShowContentBrowser)
	{
		//mContentBrowserPanel.OnImGuiRender(&bShowContentBrowser);

		// from imgui_demo.cpp: ShowAboutWindow function, should we add flag ImGuiWindowFlags_AlwaysAutoResize?
		if (!ImGui::Begin("Content Browser", &bShowContentBrowser))
		{
			ImGui::End();
			return;
		}

		ImGui::Columns(2);

		static bool init = true;
		if (init)
		{
			ImGui::SetColumnWidth(0, 240.0f);
			init = false;
		}

		if (ImGui::BeginChild("CONTENT_BROWSER_TREE"))
		{
			//DrawTree();

			ImGui::SameLine();
			ImGui::Text("test");
			ImGui::SameLine();
			ImGui::Text("test");
		}
		ImGui::EndChild();

		ImGui::NextColumn();

		if (ImGui::BeginChild("CONTENT_BROWSER_CONTENT"))
		{
			ImGui::SameLine();
			ImGui::Text("test");
			ImGui::SameLine();
			ImGui::Text("test");
		}
		ImGui::EndChild();

		ImGui::Columns(1);

		ImGui::End();
	}

	if (bShowSceneHierachy || bShowProperties)
	{
		//mSceneHierarchyPanel.OnImGuiRender(&bShowSceneHierachy, &bShowProperties);

		if (bShowSceneHierachy)
		{
			ImGui::Begin("Scene Hierarchy", &bShowSceneHierachy);

			if (mContext)
			{
				mContext->mRegistry.each([&](auto entityID)
					{
						Entity entity = { entityID, mContext.get() };
						DrawEntityNode(entity);
					});

				if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
					mSelectionContext = {};

				// Right-click on blank space
				if (ImGui::BeginPopupContextWindow(0, 1, false))
				{
					if (ImGui::MenuItem("Create Empty Entity"))
						mContext->CreateEntity("Empty Entity");

					if (ImGui::MenuItem("Create Point Light"))
					{
						auto entity = mContext->CreateEntity("Point Light");
						entity.AddComponent<PointLightComponent>();
						SetSelectedEntity(entity);
					}

					if (ImGui::MenuItem("Create Directional Light"))
					{
						auto entity = mContext->CreateEntity("Directional Light");
						entity.AddComponent<DirectionalLightComponent>();
						SetSelectedEntity(entity);
					}

					if (ImGui::MenuItem("Create Audio"))
					{
						auto entity = mContext->CreateEntity("Audio");
						entity.AddComponent<SoundComponent>();
						SetSelectedEntity(entity);
					}

					ImGui::EndPopup();
				}
			}

			ImGui::End();
		}
		if (bShowProperties)
		{
			ImGui::Begin("Properties", &pOpenProperties);
			if (mSelectionContext)
			{
				DrawComponents(mSelectionContext);
			}
			ImGui::End();
		}
	}

	if (bShowStats)
	{
		ImGui::Begin("Stats", &bShowStats);

		std::string name = "None";
		ImGui::Text("Hovered Entity: %s", name.c_str());

		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("Draw Calls: %d", 12);
		ImGui::Text("Quads: %d", 12);
		ImGui::Text("Vertices: %d", 12);
		ImGui::Text("Indices: %d", 12);

		ImGui::End();
	}
	if (bShowEngineSettings)
	{
		ImGui::Begin("Engine Settings", &bShowEngineSettings);

		ImGui::Columns(2, nullptr, false);
		ImGui::SetColumnWidth(0, 100.0f);
		ImGui::Text("Mode");
		ImGui::EndColumns();

		ImGui::Columns(2, nullptr, false);
		ImGui::SetColumnWidth(0, 100.0f);
		ImGui::Text("Camera Speed");
		ImGui::NextColumn();
		float mCameraSpeed = 0.0f;
		ImGui::SliderFloat("##Camera Speed", &mCameraSpeed, 0.1f, 10.0f);
		ImGui::EndColumns();

		ImGui::End();
	}

	if (bShowSceneSettings)
	{
		//mSceneSettingsPanel.OnImGuiRender(&bShowSceneSettings);
	}

	if (bShowViewport)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::Begin("Viewport");

		ImGui::End();
		ImGui::PopStyleVar();
	}
	// ----Windows End----

	// ----Help Begin----
	// TODO
	ImGuiWindowFlags helpMenuFlags = ImGuiWindowFlags_NoDocking;
	if (bShowTutorial)
	{
		ImGui::Begin("Tutorial", &bShowTutorial, helpMenuFlags);
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::Text("Hello!");
		ImGui::End();
	}
	if (bShowAboutMe)
	{
		ImGui::Begin("About Me", &bShowAboutMe, helpMenuFlags);
		ImGui::Text("My name is hbh!");
		ImGui::End();
	}
	if (bShowDemoImGui)
	{
		ImGui::ShowDemoWindow(&bShowDemoImGui);
	}
	// ----Help End----

	//UI_Toolbar();

	ImGui::End();
	// ----DockSpace End----
}