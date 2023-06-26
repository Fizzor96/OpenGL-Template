#include <core/application.hpp>

Application::Application(const char *windowTitle, const int &windowWidth, const int &windowHeight)
    : window(nullptr), windowWidth(windowWidth), windowHeight(windowHeight), windowTitle(windowTitle)
{
    spdlog::set_pattern("[%H:%M] %^%v%$");
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

void Application::run()
{
    initialize();
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window))
    {
        handleInput();
        update();
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        draw();
        glfwSwapBuffers(window);
    }
    cleanup();
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

void Application::initialize()
{
    initializeGLFW();
    createWindow();
    setupContext();
    initializeGLEW();
    setViewport();
    initCustomObjects();
    initializeInput();
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

void Application::initializeInput()
{
    glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);
    glfwSetKeyCallback(window, Keyboard::keyCallback);
}

void Application::setViewport()
{
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glViewport(0, 0, bufferWidth, bufferHeight);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void Application::handleInput()
{
    glfwPollEvents();
}

void Application::cleanup()
{
    if (window)
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}