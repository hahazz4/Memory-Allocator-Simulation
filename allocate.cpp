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
            //current block size decreases to the size needed
            if (curr -> size > size + sizeof(Block)){
                //Need to move to the data portion of the block
                char* dataBeg = (char*)(curr + 1);
                char* newBlockAddr = dataBeg + size; //Go forward to the new block by the amount of bytes requested
                Block* newBlock = (Block*) newBlockAddr; //Cast it into a new Block

                newBlock -> size = curr -> size - size - sizeof(Block); //curr->size is the size of the current Block before seperation, size is the requested amount of data, and sizeof(Block) is the new block's header size
                newBlock -> status = true; //Updating the new block to free (ready to be allocated)
                newBlock -> next = curr -> next; //Updating the new block to point towards the next block of the memory pool

                curr -> size = size; //Shrinks original block size to what was requested since new block is now what remains of the unused portion
                curr -> next = newBlock; //Pointing the original block's next pointer to link towards the new block
            }

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

    mergeBlocks();
}

//Merges free blocks to others
void mergeBlocks(){
    Block* curr = memList;
    //check current block and its neighbour exists
    while (curr != nullptr && curr -> next != nullptr){
        if (curr -> status == true && curr -> next -> status == true){
            curr -> size = curr -> size + curr -> next -> size + sizeof(Block);
            curr -> next = curr -> next -> next;
        }

        //If there is no chain of free blocks (a free block after a free block..) move to next block
        else
            curr = curr -> next;
    }

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
