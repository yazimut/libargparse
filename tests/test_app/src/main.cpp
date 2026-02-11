#include <iostream>
#include <argparse/argparse.hpp>
#include <argparse/version.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::styles;

void test(OptionStyle *s, const string &Arg) {
    printf("\nTesting \"%s\":\n", Arg.c_str());
    try {
        string Opt = "";
        string Val = "";
        printf("  Is optional: %s\n", s->isArgOptional(Arg) ? "true" : "false");

        s->splitArg(Arg, Opt, Val);
        printf("  Option: \"%s\"\n", Opt.c_str());
        printf("  Value:  \"%s\"\n", Val.c_str());
    } catch (const exception &e) {
        printf("  %s\n", e.what());
    }
}

int main(int argc, const char *argv[]) {
    // for (int i = 0; i < argc; ++i) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    WindowsStyle Style;

    // Not an option
    test(&Style, "f");
    test(&Style, "flag");
    test(&Style, "flag:Val");
    test(&Style, "f/f:Val");

    // Options
    test(&Style, "/f");         // Valid
    test(&Style, "/f:");        // Valid
    test(&Style, "/f:Val");     // Valid
    test(&Style, "/flag");      // Valid
    test(&Style, "/flag:");     // Valid
    test(&Style, "/flag:Val");  // Valid
    test(&Style, "/");          // Invalid
    test(&Style, "/:");         // Invalid
    test(&Style, "/:Val");      // Invalid

    return 0x00;
}
