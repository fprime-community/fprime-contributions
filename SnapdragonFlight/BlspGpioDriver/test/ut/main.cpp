// ----------------------------------------------------------------------
// Main.cpp
// ----------------------------------------------------------------------

#include "Tester.hpp"
#include <stdlib.h>
#include <SnapdragonFlight/DspRpcAllocator/DspRpcAllocator.hpp>

//TEST(Test, NominalTlm) {
//  Svc::Tester tester;
//  tester.nominalTlm();
//}

void usage(char* prog) {
    printf("Usage: %s <gpio> <mode, 0=input, 1=output, 2=interrupt>\n",prog);
}

int main(int argc, char **argv) {

    if (argc != 3) {
        usage(argv[0]);
        return -1;
    }

    int gpio = atoi(argv[1]);
    int output = atoi(argv[2]);

    SnapdragonFlight::Tester tester;

    if (0 == output) {
        printf("Testing GPIO %d input\n",gpio);
        tester.testInput(gpio,10);
    }
    else if (1 == output){
        printf("Testing GPIO %d output\n",gpio);
        tester.testOutput(gpio,10);
    } else if (2 == output) {
        printf("Testing GPIO %d interrupts\n",gpio);
        tester.testInterrrupt(gpio,10);
    } else {
        usage(argv[0]);
    }

}