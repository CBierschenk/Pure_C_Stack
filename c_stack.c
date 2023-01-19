#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "c_stack.h"

void initStack(c_stack* stack, size_t objSize)
{   
    //Try to allocate memory
    stack->objs = malloc(INITSTACKSIZE * objSize);
    
    //Check if no memory allocated
    if(stack->objs == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation failed!");
        exit(1);
    }
    //Store stack informations
    stack->objSize = objSize;
    stack->allocSize = INITSTACKSIZE;
}

void freeStack(c_stack* stack)
{
    //Free stack's allocated memory
    free(stack->objs);
    stack->allocSize = 0;
}

void extendMem(c_stack* stack)
{
    //Extend allocated memory via realloc
    stack->objs = (void*) realloc(stack->objs, ++stack->allocSize);
    stack->allocSize++;
}

int isEmpty(const c_stack* stack)
{
    return stack->stackSize == 0;
}

int isFull(const c_stack* stack)
{
    return stack->stackSize == stack->allocSize;
}

void push(c_stack* stack, void* addrElem)
{
    //Extend stack memory if stack is already full
    if(isFull(stack)){
        extendMem(stack);
    }

    //Copy object/element to the accossiated memory location. Typecast to char to use a common memory block size
    memcpy((char*) stack->objs + stack->objSize * stack->stackSize, addrElem, stack->objSize);
    stack->stackSize++;
}

void* pop(c_stack* stack)
{
    //Throw error is stack is empty (nothing to pop)
    if(isEmpty(stack)){
        fprintf(stderr, "ERROR: Stack is empty nothing to pop!\n");
        exit(1);
    }
    //Set index
    stack->stackSize--;
    //Prepate return object (allocate memory)
    void* retObj = malloc(sizeof(stack->objSize));
    //Copy values of bytes in the stack memory space to return object
    memcpy(retObj, stack->objs + stack->stackSize * stack ->objSize, sizeof(stack->objSize));
}
