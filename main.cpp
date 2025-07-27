/*
Author: Zeerak Asim
Purpose: A memory allocator simulator that was made to mimic and display the behaviour of allocating and de-allocating blocks of memory (malloc(), free())
*/

#include "allocate.h"
#include "chrono"
using namespace std::chrono;

int main(){
    initMem();
    printMem();

    const int num = 10000; //number of allocations for simulation
    void* arrPtrs[num]; //Array of pointers

    auto startA = high_resolution_clock::now();
    for (int i = 0; i < num; i++)
        arrPtrs[i] = simMalloc(64); //approx. 64 bytes allocation
    auto endA = high_resolution_clock::now();
    printMem();
    auto allocD = duration_cast<nanoseconds> (endA - startA); //tracks the time it took to allocate in nanoseconds
    cout << "----" << endl;
    cout << "Total Allocation Time for " << num << " blocks " << ": " << allocD.count() << "ns" << endl;
    cout << "----" << endl;

    auto startF = high_resolution_clock::now();
    for (int i = 0; i < num; i++)
        simFree(arrPtrs[i]); //approx. 64 bytes allocation
    auto endF = high_resolution_clock::now();
    printMem();
    auto freeDur = duration_cast<nanoseconds> (endF - startF); //tracks the time it took to allocate in nanoseconds
    cout << "----" << endl;
    cout << "Total Free Time for " << num << " blocks " << ": " << freeDur.count() << "ns" << endl;
    cout << "----" << endl;

    return 0;
}
