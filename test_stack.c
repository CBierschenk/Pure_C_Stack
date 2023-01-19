/*
* Test file to test the stack implementation. The tests are very basic! The test if Int, Float and complex structure work as excepted. Therefore, the three different stacks are instantiated and filled. During the filling, the implemented functions are checked.
*
* VERY BASIC TESTS TO TEST AND DEBUG THE IMPLEMENTATION!
*/

#include <stdlib.h>
#include <stdio.h>
#include "c_stack.h"
#include "cmplxStr.h"

int main(int argc, char** argv)
{   
    //create stacks
    c_stack intStack;
    c_stack floatStack;
    c_stack cmplxStack;


    //initialize stacks
    initStack(&intStack, sizeof(int));
    initStack(&floatStack, sizeof(float));
    initStack(&cmplxStack, sizeof(cmplx));


    // Test1: Int stack
    printf("Test1: Int Stack");
    int i = 1;
    int j = 0;
    
    //Check is empty and full functions
    printf("Is empty: %i \n", isEmpty(&intStack));
    printf("Is full: %i\n", isFull(&intStack));

    //push values bigger then size -> reallocation of memory
    for(i;i<6;i++)
    {
        push(&intStack, (void*) &i);
    }

    //check is empty and full functions again
    printf("Is empty: %i \n", isEmpty(&intStack));
    printf("Is full: %i\n", isFull(&intStack));

    //readout values via push
    while(j == 0 || j != 3){
        j = *(int*) pop(&intStack);
        printf("%i\n", j);
    }

    //add some more values
    i = 20;
    for(i;i<23;i++)
    {
        push(&intStack, (void*) &i);
    }

    //readout all left values
    while(j == 0 || j != 1){
        j = *(int*) pop(&intStack);
        printf("%i\n", j);
    }

    freeStack(&intStack);
    printf("Test1: Done\n\n\n");

    // Test2: Float stack
    printf("Test2: Float Stack");
    float k = 1.;
    float l = 0.;
    
    //check is empty and full functions
    printf("Is empty: %i \n", isEmpty(&floatStack));
    printf("Is full: %i\n", isFull(&floatStack));

    //push values bigger then size -> reallocation of memory
    for(k;k<6.;k++)
    {
        push(&floatStack, (void*) &k);
    }

    //check is empty and full functions again
    printf("Is empty: %i \n", isEmpty(&floatStack));
    printf("Is full: %i\n", isFull(&floatStack));

    //readout values via push
    while(l == 0 || l != 3.){
        l = *(float*) pop(&floatStack);
        printf("%f\n", l);
    }

    //add some more values
    k = 20.;
    for(k;k<23.;k++)
    {
        push(&floatStack, (void*) &k);
    }

    //readout all left values
    while(k == 0. || k != 1.){
        k = *(float*) pop(&floatStack);
        printf("%f\n", k);
    }

    freeStack(&floatStack);

    printf("Test2: Done\n\n\n");

    // Test2: Float stack
    printf("Test3: Complex Stack");
    
    //check is empty and full functions
    printf("Is empty: %i \n", isEmpty(&cmplxStack));
    printf("Is full: %i\n", isFull(&cmplxStack));

    //define tree test values
    cmplx one=malloc(sizeof(cmplx));
    cmplx two=malloc(sizeof(cmplx));;
    cmplx three=malloc(sizeof(cmplx));;

    (*one).two.nbr = 1;
    (*two).two.nbr = 2;
    (*three).two.nbr = 3;
    //push values
    push(&cmplxStack, (void*) &one);
    push(&cmplxStack, (void*) &two);
    push(&cmplxStack, (void*) &three);

    //check is empty and full functions again
    printf("Is empty: %i \n", isEmpty(&cmplxStack));
    printf("Is full: %i\n", isFull(&cmplxStack));

    cmplx retVal = malloc(sizeof(cmplx));;
    (*retVal).two.nbr = 100;
    //readout values via push
    while((*retVal).two.nbr != 1){
        retVal = *(cmplx*) pop(&cmplxStack);
        printf("%d\n", (*retVal).two.nbr);
    }

    freeStack(&cmplxStack);

    printf("Test3: Done\n\n\n");

}