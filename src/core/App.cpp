#include "App.hpp"

using namespace std;

App::App(const char *windowTitle, const int &windowWidth, const int &windowHeight)
{
    this->windowTitle = windowTitle;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->targetfps = 144;
    this->lastUpdateTime = 0;
    this->lastFrameTime = 0;
    this->currentTime = 0;
    this->deltaTime = 0;
    spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");
    this->Init();
    this->gui = new Gui(this);
}

App::~App()
{
    if (gui)
    {
        delete gui;
    }

    if (window)
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}

GLFWwindow *App::GetWindow()
{
    return window;
}

void App::Init()
{
    // GLFW Init
    if (!glfwInit())
    {
        spdlog::error("Failed to initialize GLFW");
        getchar();
        std::exit(1);
    }

    // CREATE WINDOW
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); // Disable window frame and decorations

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        spdlog::error("Failed to create window");
        std::exit(1);
    }

    glfwSetWindowPos(window, 0, 30);

    // glfwSwapInterval(1);
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glfwSetFramebufferSizeCallback(
        window, [](GLFWwindow *window, int width, int height)
        { glViewport(0, 0, width, height); });

    // Setup Context
    glfwMakeContextCurrent(window);

    // GLEW Init
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        spdlog::error("Failed to initialize GLEW");
        glfwDestroyWindow(window);
        glfwTerminate();
        std::exit(1);
    }

    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glViewport(0, 0, bufferWidth, bufferHeight);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

bool App::GetControlled() const
{
    return (currentTime - lastFrameTime) >= (1.0 / targetfps);
}

void App::Begin()
{
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastUpdateTime;
    glfwPollEvents();
    gui->NewFrame();
    gui->Setup();
}

void App::End()
{
    lastUpdateTime = currentTime;
}

void App::Update()
{
    spdlog::warn("FPS: " + std::to_string((int)(1.f / (currentTime - lastFrameTime))));
    gui->Render();
    lastFrameTime = currentTime;
}