/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Suffix
 *
 * Read in a number and prints out the number with the appropriate suffix.
 *
 * @file: suffix.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <math.h>

void print_with_suffix(long number){
    long last_digit = number%10; 
    long second_last_digit = number%100; 
    if(last_digit == 1 && second_last_digit != 11){
        cs1010_print_long(number); 
        cs1010_print_string("st"); 
    } 
    else if(last_digit == 2 && second_last_digit != 12){
        cs1010_print_long(number); 
        cs1010_print_string("nd"); 
    } 
    else if(last_digit == 3 && second_last_digit != 13){
        cs1010_print_long(number); 
        cs1010_print_string("rd"); 
    } 
    else {
        cs1010_print_long(number); 
        cs1010_print_string("th"); 
    }
}

int main(){
    long number = cs1010_read_long();
    print_with_suffix(number);
}
