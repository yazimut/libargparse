#include <iostream>
#include <argparse/version.hpp>

using namespace std;
using namespace argparse;



int main(int argc, const char *argv[], const char *env[]) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    cout << getVersionNumeric() << endl;
    cout << getVersionString() << endl;

    return 0x00;
}
