/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Box
 *
 * Read in three positive integer corresponding to the width,
 * height, and length of a box from the standard input, and
 * print the total surface area and the length of the diagonal
 * to the standard output.
 *
 * @file: box.c
 * @author: XXX (Group YYY)
 */
#include <stdio.h>
#include <math.h>

long area_of_rectangle(long width, long height){ 
        return width*height; 
}

long surface_area(long width, long length, long height){
    long side_1, side_2, side_3; 
    if(length  <= 0 || width <= 0 || height <= 0){
        printf("invalid input \n");
        return 0; 
    }
    side_1 = area_of_rectangle(width, height);
    side_2 = area_of_rectangle(length, height);
    side_3 = area_of_rectangle(width, length); 
    return 2*(side_1+side_2+side_3);
}

long square(long x){
  return x * x;
}

double hypotenuse_of(double width, double height, double length){
    if(length  <= 0 || width <= 0 || height <= 0){
        printf("invalid input \n");
        return 0; 
    }
    return sqrt(square(width) + square(height) + square(length));
}

int main() {
    long width = 10;
    long height = 20;
    long length = 30; 
    long a;
    double b; 
    a = surface_area(width , height, length);
    b = hypotenuse_of(width , height, length);
    printf("Surface Area: %d\n", a);
    printf("hypotenuse Of: %.4f\n", b);
    return 0;
}
