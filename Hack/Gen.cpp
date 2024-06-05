#include "testlib.h"
using namespace std;

const int N = 1e5;
const int MAX = 1e7;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(time(0)); 
    int n = rnd.next(1,N);
    println(n);
}
