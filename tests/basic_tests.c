/*
Sample configuration file for MicroFloat
*/
#include "../src/f_config_sample.h"

/*
Other includes
*/
#include "../src/f_float.h"
#include <stdio.h>
#include <math.h>


/*
    USED TO TEST THE LIBRARY ONLY
*/

float QtoFloat(qfloat input);
qfloat FloattoQ(float input);
void equalsQF(qfloat operation, float expected);
void equalsII(int operation, int expected);
void equalsQQ(qfloat operation, qfloat expected);

/* FUNCTIONS */

/* Convert a Q number to float */
float QtoFloat(qfloat input) {
    return ((float) input) * pow(2, -Q);
}

/* Convert a Float to a Q number */
qfloat FloattoQ(float input) {
    return (qfloat) (input * pow(2, Q));
}

void equalsQF(qfloat operation, float expected) {
    printf("Input : %i - Expected: %f (%i)", (int)operation, expected, 
            FloattoQ(expected));

    if (operation == FloattoQ(expected))
        printf("[SUCCESS]\n");
    else
        printf("[FAIL]\n");
}

void equalsII(int operation, int expected) {

    printf("Input : %i - Expected: %i ", operation, expected);

    if (operation == expected)
        printf("[SUCCESS]\n");
    else
        printf("[FAIL]\n");
}

void equalsQQ(qfloat operation, qfloat expected) {
    printf("Input : %i - Expected: %i ", operation, expected);

    if (operation == expected)
        printf("[SUCCESS]\n");
    else
        printf("[FAIL]\n");
}

int main(void) {

    printf("= CONVERSIONS\n");
    equalsII(FloattoQ(0.125), 0x20);

    printf("= OPERATIONS\n");
    printf("=== ADD\n");
    equalsQQ(FloattoQ(0.125 + 0.125), qAdd(FloattoQ(0.125), FloattoQ(0.125)));

    printf("=== SUB\n");
    equalsQQ(FloattoQ(0.125 - 0.125), Qsub(FloattoQ(0.125), FloattoQ(0.125)));

    printf("=== MULT\n");
    equalsQF(Qmul(FloattoQ(0.5), FloattoQ(0.5)), 0.25);
    equalsQF(Qmul(FloattoQ(0.125), FloattoQ(0.5)), 0.0625);
    equalsQF(Qmul(FloattoQ(0.75), FloattoQ(0.5)), 0.375);
    equalsQF(Qmul(FloattoQ(0.5), FloattoQ(0.25)), 0.125);
    equalsQF(Qmul(FloattoQ(32.5), FloattoQ(1.25)), 40.625);
    equalsQF(Qmul(FloattoQ(0), FloattoQ(1.25)), 0);
    equalsQF(Qmul(FloattoQ(0.22424255), FloattoQ(0.2452)), 0.054984);

    return 0;
}