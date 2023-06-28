#include <core/appgui.hpp>

AppGui::AppGui(GLFWwindow *window)
{
    app = Application::GetCurrentApplication();
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    io.FontGlobalScale = 1.5f;

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
    static bool show_demo_window = false;
    static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    static float titleBarHeight = ImGui::GetStyle().FramePadding.y * 2 + ImGui::GetFontSize();
    static float mainMenuBarHeight = ImGui::GetWindowSize().y - ImGui::GetContentRegionAvail().y - titleBarHeight;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoBackground;
    ImGui::SetNextWindowSize(ImVec2((ImGui::GetIO().DisplaySize).x, (ImGui::GetIO().DisplaySize).y - titleBarHeight));
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f + titleBarHeight));
    ImGui::Begin("Fullscreen Window", nullptr, window_flags); // Create a transparent window with no title bar

    ImGui::Text("FPS: %i\nFrametime: %0.5f", app->GetCurrentFPS(), 1.f / app->GetCurrentFPS());

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Toggle Demo"))
            {
                show_demo_window = !show_demo_window;
            }
            if (ImGui::MenuItem("Toggle Fullscreen"))
            {
                app->ToggleFullScreen();
            }
            if (ImGui::MenuItem("Maximize"))
            {
                app->MaximizeWindow();
            }
            if (ImGui::MenuItem("Minimize"))
            {
                app->MinimizeWindow();
            }
            if (ImGui::MenuItem("Quit", "Alt+F4"))
            {
                app->Terminate();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    // Dock windows to the whole screen sides
    ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, titleBarHeight), ImGuiDockNodeFlags_PassthruCentralNode);
    ImGui::End();

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
}