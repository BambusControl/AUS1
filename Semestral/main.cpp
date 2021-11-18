#pragma once

#include "menu.h"
#include "common/heap_monitor.h"

int main(int argc, char* argv[]) 
{
    initHeapMonitor();
    srand(time(0));

    cout << "Tester udajovych struktur" << endl << endl;
    
    Menu().run();

    return 0;
}