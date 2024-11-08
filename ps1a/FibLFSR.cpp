// Copyright 2024 <Braden Maillet>
#include "FibLFSR.hpp"
#include <iostream>

using std::cout;
using std::endl;

int run(void);

int run(void) {
        PhotoMagic::FibLFSR fib("1011011000110110");
        int holder = fib.getbi();
        cout << holder << endl;

        cout << fib.getseed() << " " << fib.getbi() << endl;

        cout << fib.getbi() << " " << fib.getbitostring() << endl;

        LOG_DEBUG("\n-----1-----\n");
        fib.generate(5);
        LOG_DEBUG("\n-----2------\n");
        fib.generate(5);
        LOG_DEBUG("\n-----3------\n");
        fib.generate(5);
        LOG_DEBUG("\n-----4------\n");
        fib.generate(5);
        LOG_DEBUG("\n-----5------\n");
        fib.generate(5);
        LOG_DEBUG("\n-----6------\n");
        fib.generate(5);
        LOG_DEBUG("\n-----7------\n");
        fib.generate(5);
        cout << fib << endl;
        return 0;
}
