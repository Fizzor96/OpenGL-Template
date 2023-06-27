#include <gui/appgui.hpp>

AppGui::AppGui(GLFWwindow *window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    mystr = "Click the button!!!";
}

AppGui::~AppGui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void AppGui::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void AppGui::Setup()
{
    // Main DockSpace
    static bool open = true;
    static bool show_demo_window = true;
    static bool show_another_window = false;

    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", &open, window_flags);
    ImGui::PopStyleVar(3);

    ImGuiIO &io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                // File menu items
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("View"))
            {
                // View menu items
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::Begin("Hello, Docking!");
        ImGui::Text("This is some content.");
        ImGui::End();

        if (show_demo_window)
        {
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);
            ImGui::Text("Hello from another window!");
            ImGui::End();
        }

        ImGui::End();
    }

    // DO NOT DELETE RENDER FROM HERE!!!!
    ImGui::Render();
}

void AppGui::Render()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void AppGui::ProcessEvent(const GLFWwindow *window, const int key, const int scancode, const int action, const int mods)
{
    ImGui_ImplGlfw_KeyCallback(const_cast<GLFWwindow *>(window), key, scancode, action, mods);
    ImGui_ImplGlfw_CharCallback(const_cast<GLFWwindow *>(window), static_cast<unsigned int>(key));
}

void AppGui::SetupImGuiStyle()
{
    // ImGuiStyle &style = ImGui::GetStyle();
    // style.WindowRounding = 0.0f;
    // style.WindowBorderSize = 0.0f;
    // style.WindowPadding = ImVec2(0.0f, 0.0f);
    // style.FramePadding = ImVec2(4.0f, 2.0f);
    // style.ItemSpacing = ImVec2(8.0f, 4.0f);
    // style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    // style.IndentSpacing = 21.0f;
    // style.ScrollbarSize = 10.0f;
    // style.ScrollbarRounding = 0.0f;
    // style.GrabMinSize = 7.0f;

    // style.WindowTitleAlign = ImVec2(0.5f, 0.5f);

    // style.Colors[ImGuiCol_WindowBg] = ImVec4(0.2f, 0.2f, 0.2f, 0.7f);
    // style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    // style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
    // style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1f, 0.1f, 0.1f, 0.75f);
}