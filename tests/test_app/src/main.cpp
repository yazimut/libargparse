#include <iostream>
#include <argparse/argparse.hpp>
#include <argparse/version.hpp>

using namespace std;
using namespace argparse;

int main(int argc, const char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    cout << getVersionNumeric() << endl;
    cout << getVersionString() << endl;
    cout << endl;

    ArgumentParser parser;
    parser.parse(argc, argv);

    return 0x00;
}
