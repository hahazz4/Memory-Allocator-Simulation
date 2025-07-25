#include <allocate.h>

Block* memList = nullptr; //setting pointer to the start of the heap

void initMem(){
    memList = (Block*)memPool;
    memList -> size = heap_size - sizeof(Block);
    memList -> status = true; //free for init..
    memList -> next = nullptr;
}

void *simMalloc(size_t size){
    Block* curr = memList;
    while (curr != nullptr){
        
    }
}
