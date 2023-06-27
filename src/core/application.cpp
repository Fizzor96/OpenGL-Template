#include <core/application.hpp>

Application *Application::currentApplication = nullptr;

Application *Application::Create(const char *windowTitle, const int &windowWidth, const int &windowHeight)
{
    if (currentApplication == nullptr)
    {
        currentApplication = new Application(windowTitle, windowWidth, windowHeight);
        return currentApplication;
    }
    else
    {
        spdlog::error("Error! Only one application is allowed!");
        return nullptr;
    }
}

void Application::Terminate()
{
    if (currentApplication != nullptr)
    {
        currentApplication->~Application();
    }
}

Application::Application(const char *windowTitle, const int &windowWidth, const int &windowHeight)
    : window(nullptr), windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle)
{
    spdlog::info("good sh1t");
}

Application::~Application()
{
    cleanup();
}

void Application::initCustomObjects()
{
    triangle = new Triangle();
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

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            spdlog::warn("FPS: {}", fps);
        }

        if (deltaTime >= targetFrameTime)
        {
            fps = (int)(1.f / deltaTime);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            update();
            draw();

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
    initCustomObjects();
    initializeInput();
    initspdlogpattern();
    initFpsRelatedVars();
}

void Application::initFpsRelatedVars()
{
    targetfps = 60;
    fps = 0;
    previousTime = std::chrono::high_resolution_clock::now();
    deltaTime = 0.0;
    targetFrameTime = (1.0 / targetfps) * 0.99;
}

void Application::initspdlogpattern()
{
    spdlog::set_pattern("[%H:%M] %^%v%$");
}

void Application::createWindow()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        spdlog::error("Failed to create window");
        std::exit(1);
    }

    // glfwSwapInterval(0);
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
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

void Application::cleanup()
{
    if (window)
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}