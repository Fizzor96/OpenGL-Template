#include <core/application.hpp>

Application *Application::currentApplication = nullptr;

void Application::framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Application *Application::Create(const char *windowTitle, const int &windowWidth, const int &windowHeight)
{
    spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");
    if (currentApplication == nullptr)
    {
        currentApplication = new Application(windowTitle, windowWidth, windowHeight);
        spdlog::info("Application created succefully!");
        return currentApplication;
    }
    else
    {
        spdlog::error("Error! Only one application is allowed! Please use the \"GetCurrentApplication()\" method to retrieve the application pointer!");
        return nullptr;
    }
}

void Application::Terminate()
{
    if (currentApplication != nullptr)
    {
        currentApplication->~Application();
        spdlog::info("Application terminated succesfully!");
    }
}

Application::Application(const char *windowTitle, const int &windowWidth, const int &windowHeight)
    : window(nullptr), windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle), appgui(nullptr)
{
}

Application::~Application()
{
    cleanup();
}

void Application::initCustomObjects()
{
    triangle = new Triangle();
    appgui = new AppGui(window);
}

void Application::draw()
{
    triangle->render();
}

void Application::update()
{
}

void Application::initializeInput()
{
    glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);
    glfwSetKeyCallback(window, Keyboard::traceKeys);
}

void Application::Run()
{
    initialize();
    while (!glfwWindowShouldClose(window))
    {
        currentTime = std::chrono::high_resolution_clock::now();
        deltaTime += std::chrono::duration<double>(currentTime - previousTime).count();
        previousTime = currentTime;

        glfwPollEvents();
        appgui->NewFrame();
        appgui->Setup();

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            spdlog::warn("FPS: {}", fps);
        }

        if (deltaTime >= targetFrameTime)
        {
            fps = (int)(1.f / deltaTime);
            if (showFpsInWindowTitle)
            {
                glfwSetWindowTitle(window, (std::string(windowTitle + " - FPS: " + std::to_string(fps) + " - FrameTime: " + std::to_string(deltaTime))).c_str());
            }

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            update();
            draw();
            appgui->Render();

            glfwSwapBuffers(window);
            deltaTime = 0.0;
        }
    }
    cleanup();
}

void Application::initialize()
{
    initializeGLFW();
    createWindow();
    setupContext();
    initializeGLEW();
    setViewport();
    initializeInput();
    initFpsRelatedVars();
    initCustomObjects();
}

void Application::initFpsRelatedVars()
{
    fpsToleranceLimitMultiplyer = 1.0;
    targetfps = 60;
    fps = 0;
    previousTime = std::chrono::high_resolution_clock::now();
    deltaTime = 0.0;
    targetFrameTime = (1.0 / targetfps) * fpsToleranceLimitMultiplyer;
    showFpsInWindowTitle = false;
}

void Application::createWindow()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); // Disable window frame and decorations

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        spdlog::error("Failed to create window");
        std::exit(1);
    }

    // glfwSwapInterval(0);
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glfwSetFramebufferSizeCallback(window, Application::framebufferSizeCallback);
    glfwMaximizeWindow(window);
}

void Application::setupContext()
{
    glfwMakeContextCurrent(window);
}

void Application::initializeGLEW()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        spdlog::error("Failed to initialize GLEW");
        glfwDestroyWindow(window);
        glfwTerminate();
        std::exit(1);
    }
}

void Application::initializeGLFW()
{
    if (!glfwInit())
    {
        spdlog::error("Failed to initialize GLFW");
        getchar();
        std::exit(1);
    }
}

void Application::setViewport()
{
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glViewport(0, 0, bufferWidth, bufferHeight);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

GLFWwindow *Application::getCurrentContext()
{
    return this->window;
}

int Application::getBufferWidht() const
{
    return this->bufferWidth;
}

int Application::getBufferHeight() const
{
    return this->bufferHeight;
}

void Application::SetFrameRate(unsigned int fps)
{
    targetfps = fps;
    targetFrameTime = (1.0 / targetfps) * fpsToleranceLimitMultiplyer;
    spdlog::info("TargetFramerate set to: {} FPS", targetfps);
}

void Application::Toggle_ShowFPSInTitle()
{
    showFpsInWindowTitle = !showFpsInWindowTitle;
    if (!showFpsInWindowTitle)
    {
        glfwSetWindowTitle(window, windowTitle.c_str());
    }
    spdlog::info("Toggle_ShowFPSInTitle: {}", showFpsInWindowTitle);
}

int Application::GetCurrentFPS() const
{
    return fps;
}

void Application::cleanup()
{
    if (window)
    {
        glfwDestroyWindow(window);
        glfwTerminate();
        if (appgui != nullptr)
            delete appgui;
    }
}