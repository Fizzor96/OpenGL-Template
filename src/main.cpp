#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <core/application.hpp>
#include <spdlog/spdlog.h>

#ifdef RELEASE_MSVC
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow)
{
    spdlog::info("MSVC defined");
    Application *app = new Application("Hello World!", 1280, 1024);
    app->run();
    delete app;
    return 0;
}
#else
int main()
{
    Application *app = new Application("Hello World!", 1280, 1024);
    app->run();
    delete app;
    return 0;
}
#endif
