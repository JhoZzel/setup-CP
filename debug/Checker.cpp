#include "testlib.h"
using namespace std;

int main(int argc, char * argv[]) {
    //setName("compares two signed integers");
    setName("compare files as sequence of lines");
    registerTestlibCmd(argc, argv);
    int t = 1;
    for (int i = 1; i <= t; i++) {
        string ja = ans.readString();
        string pa = ouf.readString();
        /*if (ja != pa) {
            quitf(_wa, "Wrong Answer. Expected %lld, found %lld, in test %d", ja, pa, i);
        }*/
        if (ja != pa) {
            quitf(_wa, "Wrong Answer. Expected '%s', found '%s', in test %d", ja.c_str(), pa.c_str(), i);
        }
    }
    quitf(_ok, "Accepted");
    return 0;
}
