#include <iostream>
#include "render/menuWindow.h"

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "usage: ./race00 [width] [height]\n";
        exit(1);
    } else {
        renderMenuWindow(std::stoi(argv[1]), std::stoi(argv[2]));
    }
    return 0;
}
