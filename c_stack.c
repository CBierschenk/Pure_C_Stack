#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "c_stack.h"

void initStack(c_stack* stack, size_t objSize)
{
    stack->objs = malloc(INITSTACKSIZE * objSize);
    if(stack->objs == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation failed!");
        exit(1);
    }
    stack->objSize = objSize;
    stack->allocSize = INITSTACKSIZE;
}

void freeStack(c_stack* stack)
{
    free(stack->objs);
    stack->allocSize = 0;
}

void extendMem(c_stack* stack)
{
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
    if(isFull(stack)){
        extendMem(stack);
    }

    memcpy((char*) stack->objs + stack->objSize * stack->stackSize, addrElem, stack->objSize);
    stack->stackSize++;
}

void* pop(c_stack* stack)
{
    if(isEmpty(stack)){
        fprintf(stderr, "ERROR: Stack is empty nothing to pop!\n");
        exit(1);
    }
    stack->stackSize--;
    void* retObj = malloc(sizeof(stack->objSize));

    memcpy(retObj, stack->objs + stack->stackSize * stack ->objSize, sizeof(stack->objSize));
}
