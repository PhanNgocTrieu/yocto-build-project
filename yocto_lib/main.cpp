#include <iostream>
#include "Application.h"
#if 0
#include <glib-2.0/glib.h>
static GMainLoop* g_main_loop = nullptr;
#endif

int main(int argc, char* argv[]) {
    return Application::getInstance()->execute(argc, argv);
}