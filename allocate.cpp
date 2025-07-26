#include "allocate.h"

char memPool[heap_size];
Block* memList = nullptr; //setting pointer to the start of the heap

//Init. the memory
void initMem(){
    memList = (Block*)memPool;
    memList -> size = heap_size - sizeof(Block);
    memList -> status = true; //Block is now free
    memList -> next = nullptr;
}

//Malloc
void *simMalloc(size_t size){
    Block* curr = memList;
    while (curr != nullptr){
        //Check if the block is free for allocation, and if the current size of the block is big enough
        if (curr -> size >= size && curr -> status == true){
            if 
            
            curr -> status = false;
            return (void*)(curr + 1); //returning the pointer of an unknown data type back to user, and moving to the next memory after Block header
        }
        curr = curr -> next;
    }
    //Once the exit condition of the while loop is met that means no Block found, return a null pointer
    return nullptr;
}

//Free
void simFree(void* ptr){
    if (ptr == nullptr)
        return;
    
    Block* header = ((Block*) ptr) - 1; //changing the cast (void*) back to (Block*) and moves back Block to metadata
    header -> status = true; //it is now free
}

//Printing the data on console
void printMem(){
    Block* curr = memList;
    int i = 0;
    while (curr != nullptr){
        cout << "Block " << i++ << " || " << "Size: " << curr -> size << " | " << "Status: " << (curr -> status ? "Free" : "Allocated") << " ||\n";
        curr = curr -> next;
    }
}
