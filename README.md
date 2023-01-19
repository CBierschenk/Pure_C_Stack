# Pure_C_Stack
Generic stack class implementation in C using struct. 

The implementation of c stack could be done in different ways. As a reusable possibility, a structure with associated functions was created. This structure can hold any data type by using a void pointer and the size of the desired data type. In addition to this information, the structure contains the allocated size (number of elements) and the current stack size (number of elements stored). Due to the use of the void pointer, the element returned by the pop() API function is a void pointer that must be cast back to the desired data type. The developer must be aware of this drawback, as they must choose the correct cast type. In addition, dynamic memory allocation has been used.

## Different Implementation Strategies
* 1) Dynamic Stack (Dynamic Memory):
Using dynamic memory allocation (initialize memory, reallocate memory if necessary, free memory if done) in the implementation can reduce memory consumption. Because the size of the stack is dynamically adapted. If more space is necessary, memory will reallocate, otherwise the size stays at the initial defined size or is reduced by freeing memory. The problem with this design decision is, that the allocation functions can differ between different HW and the real-time ability is impaired by the dynamic memory allocation (malloc is a non-deterministic function and could unpredictable fail).

Benefits: Dynamic Stack Size Adaption (Might Reduce Memory Consumption)
Drawbacks: Not Applicable/Recommended For Real-Time Applications

* 2) Static Stack (Static Memory):
Using static memory allocation (initialize stack data with a fixed size) is an applicable implementation for real-time (due to the above described facts). Here, the size of the data (element) array isn't dynamically allocated, but already defined by a fixed value during compilation. In this implementation scenario, it isn't possible to create more space for new elements if the maximum number of elements is reached. The size can't adapt during runtime, and the deallocation of memory is also not applicable.

Benefits: Real-Time Applicable
Drawbacks: Static Memory (Size Fix After Compilation)

## Stack Functions
* void initStack(c_stack* stack, size_t objSize): Initialize the stack to the defined initial size of three elements
* void freeStack(c_stack* stack): Free memory used for stack
* void extendMem(c_stack* stack): Extend memory if more space is necessary
* int isEmpty(const c_stack* stack): Checks if stack is empty
* int isFull(const c_stack* stack): Checks if stack is full (allocate memory reached)
* void push(c_stack* stack, void* addrElem): Push element on top of the stack
* void* pop(c_stack* stack): Pop top element from the stack

# Repo

'''Shell
.
├── cmplxStr.h - Header including complex structure for tests
├── c_stack.c - Generic stack implementation c-file
├── c_stack.h - Generic stack implementation h-file
├── README.md - Readme
├── test_stack - Bin-file which tests int, float and complex structure
└── test_stack.c - Test file with entry point (main) to test the implementation. Very basic tests.
'''



