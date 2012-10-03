#include <Simple/SimpleCore.h>

int main(int argc, char *argv[]) {
    Core *_simpleCore = new SimpleCore();
    _simpleCore->start();
    delete _simpleCore;
    return 1;
}
