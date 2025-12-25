#include <iostream>
#include <argparse/version.hpp>

using namespace std;
using namespace argparse;



int main() {
    cout << "Hello, World! :)" << endl;
    cout << getVersionNumeric() << endl;
    cout << getVersionString() << endl;
    return 0x00;
}
