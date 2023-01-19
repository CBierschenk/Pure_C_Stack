#ifndef __CMPLXSTR_H__
#define __CMPLXSTR_H__

typedef struct cmplx* cmplx;

struct cmplx{
    struct {
        int nbr;
        float fraction;
    }two;
    char ch;
};


#endif