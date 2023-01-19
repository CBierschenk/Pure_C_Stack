#ifndef __STACK_H__
#define __STACK_H__
#define INITSTACKSIZE 3

typedef struct
{
    /* data */
    void* objs;
    size_t objSize;
    int stackSize;
    int allocSize;
} c_stack;

void initStack(c_stack* stack, size_t objSize);
void freeStack(c_stack* stack);
void extendMem(c_stack* stack);
int isEmpty(const c_stack* stack);
int isFull(const c_stack* stack);
void push(c_stack* stack, void* addrElem);
void* pop(c_stack* stack);

#endif