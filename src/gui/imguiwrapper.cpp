#include <gui/imguiwrapper.hpp>

ImGuiWrapper::ImGuiWrapper(GLFWwindow *window)
{
    // Set up ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO();
    (void)io;

    // Set up GLFW binding
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    // Set up OpenGL3 binding
    ImGui_ImplOpenGL3_Init("#version 330 core");
}

ImGuiWrapper::~ImGuiWrapper()
{
    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiWrapper::NewFrame()
{
    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiWrapper::Update()
{
    ImGui::Begin("Button Example");

    if (ImGui::Button("Click Me"))
    {
        // Button clicked
        // Implement your logic here
    }

    ImGui::End();
}

void ImGuiWrapper::Render()
{
    // Render ImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}