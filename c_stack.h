/*
* Pure c stack header file. Defines the stack struct, the api functions (initStack, freeStack, extendMem, isEmpty, isFull, push, pop) and the initial stack size of 3 via preprocessor define. 
*/

#ifndef __STACK_H__
#define __STACK_H__
#define INITSTACKSIZE 3


/*
* Stack struct to create a stack in c.
* Data:
*   objs - void pointer: objects/elements stored in stack.
*   objSize - size_t: size of stored data type (used to allocate, realocate and copy memory adresses)
*   stackSize - int: var to hold the current stack size (elements on stack)
*   allocSize - int: var to remember the last number of allocated memory blocks of a given size
*/
typedef struct
{
    /* data */
    void* objs;
    size_t objSize;
    int stackSize;
    int allocSize;
} c_stack;


/*
* Name: initStack
* Description: API function to initialize the stack and allocate initial memory (3 time data type byte size)
* @Return: void (nothing)
* @Param: c_stack pointer - pointer to the stack obj
* @Param: size_t - size of the stack objs/elemts datatype 
*/
void initStack(c_stack* stack, size_t objSize);


/*
* Name: freeStack
* Description: Frees allocated memory space after stack usage
* @Return: void (nothing)
* @Param: c_stack pointer - pointer to the stack obj
*/
void freeStack(c_stack* stack);


/*
* Name: extendMem
* Description: Extend the allocated memory by one if necessary
* @Return: void (nothing)
* @Param: c_stack pointer - pointer to the stack obj
*/
void extendMem(c_stack* stack);


/*
* Name:
* Description: Checks if stack is empty. 0 := False, 1 := True
* @Return: int
* @Param: c_stack pointer - pointer to the stack obj
*/
int isEmpty(const c_stack* stack);


/*
* Name: isFull
* Description: Checks if stack is full. 0 := False, 1 := True
* @Return: int
* @Param: c_stack pointer - pointer to the stack obj
*/
int isFull(const c_stack* stack);


/*
* Name: push
* Description: pushs element onto the stack
* @Return: void (nothing)
* @Param: c_stack pointer - pointer to the stack obj
* @Param: void pointer - address of obj/elem which is pushed onto the stack
*/
void push(c_stack* stack, void* addrElem);


/*
* Name: pop
* Description: pops the top (last) element from the stack
* @Return: void pointer - object/element's memory address (must be casted to the right type to access value) 
* @Param: c_stack pointer - pointer to the stack obj
*/
void* pop(c_stack* stack);

#endif