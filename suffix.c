/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Suffix
 *
 * Read in a number and prints out the number with the appropriate suffix.
 *
 * @file: suffix.c
 * @author: XXX (Group YYY)
 */
#include<stdio.h>
#include <math.h>

void print_with_suffix(long number){
    long last_digit = number%10; 
    long second_last_digit = number%100; 
    if(last_digit == 1 && second_last_digit != 11){
        printf("%dst", number); 
    } 
    else if(last_digit == 2 && second_last_digit != 12){
        printf("%dnd", number); 
    } 
    else if(last_digit == 3 && second_last_digit != 13){
        printf("%drd", number); 
    } 
    else {
        printf("%dth", number);
    }
}

int main(){
    long number = 122;
    print_with_suffix(number);
}
