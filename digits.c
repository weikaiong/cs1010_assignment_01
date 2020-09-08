/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Digits
 *
 * Read in a positive integer from the standard input and print
 * the sum of the square of each digit in the integer to the standard output.
 *
 * @file: digits.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"
#include <math.h>

long square(long x){
  return x * x;
}

long sum_of_digits_square(long number){
    if(number < 0){
        cs1010_println_string("Invalid Input"); 
        return 0;
    }
    long digit = number%10;
    if(digit == number){ 
        return square(number); 
    }
    else{
        return square(digit)+sum_of_digits_square(number/10);
    }
}

int main(){
    long number = cs1010_read_long();
    long sum = sum_of_digits_square(number);
    cs1010_print_long(sum);
}
