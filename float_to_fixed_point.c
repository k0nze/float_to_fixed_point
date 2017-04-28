/**
 * TODO: Description
 * Author: Konstantin Lübeck
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libfixmath/fix16.h"

void syntax_msg() {
    printf("DESCRIPTION:\n");
    printf("\tThis program return for a given number the representation in\n");
    printf("\tfix16_t or float\n\n");
    printf("SYNTAX:\n");
    printf("\tfloat_to_fixed_point [0x]NUMBER\n\n");
    printf("OPTIONS:\n");
    printf("\t-h, --help: displays this text\n\n");
    printf("NUMBER:\n");
    printf("\tA number without a prefix and without a decimal point is \n"); 
    printf("\tinterpreted as decimal representation of a fix16_t number.\n");
    printf("\tA number with a 0x prefix is interpreted as a hex representation\n"); 
    printf("\tof a fix16_t number. A number with a decimal point interpreted as\n"); 
    printf("\ta float number.\n");
}

int main(int argc, char *argv[]) {
   
    // check if exactly one command line argument was provided
    if(argc < 2) {
        fprintf(stderr, "no number was given\n");
        return 1;
    }

    if(argc > 2) {
        fprintf(stderr, "too many command line arguments\n");
        return 1;
    }

    // check if help is wanted
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        syntax_msg();
        return 0;
    }

    char* input = argv[1];

    // check for 0x prefix
    if(input[0] == '0' && input[1] == 'x') {
        uint32_t temp = strtol(input, NULL, 16);
        float output = fix16_to_float(temp);
        printf("%f\n", output);
        return 0;
    }

    // check if input contains a decimal point
    if(strstr(input, ".") != NULL) {
        float temp = (float) atof(input);
        fix16_t output = fix16_from_float(temp);
        printf("0x%08X\n", output);
        return 0;
    }

    // check if input contains numbers only 
    int isnumber = 1;
    int i = 0;
    while(input[i] != '\0') {
        if(!isdigit(input[i])) {
            isnumber = 0;
            break;
        }
        i++;
    }

    if(isnumber == 1) {
        uint16_t temp = atoi(input);
        float output = fix16_to_float(temp);
        printf("%f\n", output);
        return 0;
    }

    else {
        fprintf(stderr, "can't interprete input");
        return 1;
    }

    return 0;
}
