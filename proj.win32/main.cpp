#include "main.h"
#include "GameDelegate.h"
#include "cocos2d.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

int WINAPI _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    GameDelegate app;
    return Application::getInstance()->run();
}
