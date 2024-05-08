#include <iostream>
#include "display.h"
#include <glib-2.0/glib.h>

static GMainLoop* g_main_loop = nullptr;

int main() {
    Rect rect(2,3,4,5);
    std::cout << "Hello world" << std::endl;
    return 0;
}