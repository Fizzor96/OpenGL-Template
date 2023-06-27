#include <gui/appgui.hpp>

AppGui::AppGui(GLFWwindow *window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
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
    ImGui::ShowDemoWindow();

    ImGui::Begin("Button Example");
    ImGui::Text("Hello, world!");
    if (ImGui::Button("Print Hello World"))
    {
        spdlog::info("Hello World from ImGUI!");
    }
    ImGui::End();
}

void AppGui::Render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void AppGui::ProcessEvent(const GLFWwindow *window, const int key, const int scancode, const int action, const int mods)
{
    ImGui_ImplGlfw_KeyCallback(const_cast<GLFWwindow *>(window), key, scancode, action, mods);
    ImGui_ImplGlfw_CharCallback(const_cast<GLFWwindow *>(window), static_cast<unsigned int>(key));
}

void AppGui::SetupImGuiStyle()
{
    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowPadding = ImVec2(0.0f, 0.0f);
    style.FramePadding = ImVec2(4.0f, 2.0f);
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.IndentSpacing = 21.0f;
    style.ScrollbarSize = 10.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabMinSize = 7.0f;

    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);

    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.2f, 0.2f, 0.2f, 0.7f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1f, 0.1f, 0.1f, 0.75f);
}