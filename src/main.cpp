#include <core/application.hpp>
#ifdef SUBSYS_WIN
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow)
{
    Application *app = Application::Create("Application", 1920, 1080);
    app->Run();
    app->Terminate();
    return 0;
}
#else
int main()
{
    Application *app = Application::Create("Devel", 1920, 1080);
    app->Run();
    app->Terminate();
    return 0;
}
#endif