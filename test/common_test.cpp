#include "../include/hlog.h"

class A {
public:
    A() {
        HLOGI << "Constructed";
    }

    ~A() {
        HLOGI << "Destructed";
    }
};

int main(int argc, char ** argv) {

    hlog::init();
    hlog::addFile("output.txt");
    hlog::addFile("output.csv");

    HLOGI << "Hello world!";
    HLOGD << "Hello world!";
    HLOGE << "Hello world!";

    A a;

    return 0;
}
