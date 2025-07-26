#include "allocate.h"

int main(){
    initMem();
    
    void* a = simMalloc(10);
    void* b = simMalloc(50);
    void* c = simMalloc(100);
    void* d = simMalloc(200);
    printMem();

    free(b);
    printMem();

    free(d);
    printMem();

    return 0;
}
