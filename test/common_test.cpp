#include "../include/hlog.h"

int main(int argc, char ** argv) {
    init();
    addFile("output.txt");

    HLOGI << "Hello world!";
    HLOGD << "Hello world!";
    HLOGE << "Hello world!";

    return 0;
}
