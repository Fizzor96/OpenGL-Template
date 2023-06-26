#include <core/application.hpp>
#ifdef SUBSYS_WIN
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow)
{
    Application app("Application", 1280, 1024);
    app.run();
    return 0;
}
#else
int main()
{
    Application app("Devel", 1280, 1024);
    app.run();
    return 0;
}
#endif