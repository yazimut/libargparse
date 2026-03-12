#include <iostream>
#include <argparse/argparse.hpp>
#include <argparse/version.hpp>
#include <argparse/parsers/WindowsArgParser.hpp>

using namespace std;
using namespace argparse;

int main(int argc, const char *argv[]) {
    // for (int i = 0; i < argc; ++i) {
    //     printf("argv[%d]: \"%s\"\n", i, argv[i]);
    // }

    WindowsArgParser Parser;
    Parser.parse(--argc, ++argv);

    return 0x00;
}
