#include <core/App.hpp>
#ifdef NODEBUG
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow)
{
    App app{"OpenGL", 1280, 1024};
    while (!glfwWindowShouldClose(app.GetWindow()))
    {

        app.Begin();
        if (app.GetControlled())
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            app.Update();
            glfwSwapBuffers(app.GetWindow());
        }
        app.End();
    }
    return 0;
}
#else
int main()
{
    App app{"OpenGL", 1280, 1024};
    while (!glfwWindowShouldClose(app.GetWindow()))
    {

        app.Begin();
        if (app.GetControlled())
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            app.Update();

            glfwSwapBuffers(app.GetWindow());
        }
        app.End();
    }
    return 0;
}
#endif