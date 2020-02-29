#ifndef __F_FLOAT_H__
#define  __F_FLOAT_H__

/*
    MICROFLOAT: A simple Fixed Point Maths Library 
*/

typedef int qfloat;

/* PROTOTYPES */

qfloat qAdd(qfloat a, qfloat b);
qfloat Qsub(qfloat a, qfloat b);
qfloat Qmul(qfloat a, qfloat b);

/* FUNCTIONS */
/*
    Add two qfloat together

    Parameters: a -> the first number
                a -> the second number

    return: qfloat
*/

qfloat qAdd(qfloat a, qfloat b) {
    return a + b;
}

/*
    Substract two qfloat together

    Parameters: a -> the first number
                a -> the second number

    return: qfloat
*/
qfloat Qsub(qfloat a, qfloat b)
{
    return a - b;
}

/*
    Multiply two qfloat together

    Parameters: a -> the first number
                a -> the second number

    return: qfloat
*/
qfloat Qmul(qfloat a, qfloat b)
{
    return ((a * b) + (1 << (Q - 1))) >> Q;
}

#endif