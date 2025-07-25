#include "iostream"
using namespace std;

//Allocated chunks of memory that have metadata like size, whether its free or not
struct Block{
    size_t size;
    bool status;
    Block* next; //To track where we are when we traverse through the heap for the memory pool
};

//Initializing a heap with a size of 1MB for the memory pool
const int heap_size = 1024 * 1024;
char memPool[heap_size];

//function headers
void initMem(){}
void *simMalloc(size_t size){}
void simFree(void* ptr){}
void printMem(){}
