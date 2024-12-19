#include "jngen.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv);
    parseArgs(argc, argv);

    int maxc = getOpt(0);

    int a = rnd.next(0, maxc);
    int b = rnd.next(0, maxc);
    
    cout << a << " " << b << endl;
}
