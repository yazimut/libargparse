#include <iostream>
#include <argparse/argparse.hpp>
#include <argparse/version.hpp>

using namespace std;
using namespace argparse;

int main(int argc, const char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: \"%s\"\n", i, argv[i]);
    }

    return 0x00;
}
