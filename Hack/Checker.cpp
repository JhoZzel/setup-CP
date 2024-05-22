#include "testlib.h"

int main(int argc, char * argv[]) {
    setName("compares two signed integers");
    registerTestlibCmd(argc, argv);
    long long ja = ans.readLong();
    long long pa = ouf.readLong();
    if (ja != pa)
        quitf(_wa, "Wrong Answer. Expected %lld, found %lld", ja, pa);
    quitf(_ok, "Accepted");
    return 0;
}

