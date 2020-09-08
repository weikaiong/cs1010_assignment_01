/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Taxi
 *
 * Read in four positive integer corresponding to the day of the week,
 * the hour and minute of boarding, and the distance travelled.  Print
 * to the standard output, the fare of the taxi.
 *
 * @file: taxi.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdbool.h>

bool is_weekday(long day){
    if(day <= 0 || day > 7){
        cs1010_println_string("Not A Valid Day"); 
        return false; 
    }
    if(day >= 1 && day <= 5){
        return true;
    }
    else{
        return false; 
    }
}

bool is_morning_peak(long hour, long min){
    long time = (hour*100)+min; 
    if(time < 0000 || time > 2359){
        cs1010_println_string("Not A Valid Time"); 
        return false; 
    }
    if(time >= 600 && time <= 929){
        return true;
    }
    else{
        return false; 
    }
}

bool is_evening_peak(long hour, long min){
    long time = (hour*100)+min; 
    if(time < 0000 || time > 2359){
        cs1010_println_string("Not A Valid Time"); 
        return false; 
    }
    if(time >= 1800 && time <= 2359){
        return true;
    }
    else{
        return false; 
    }
}

bool is_midnight_peak(long hour, long min){
    long time = (hour*100)+min; 
    if(time < 0000 || time > 2359){
        printf("Not A Valid Time"); 
        return false; 
    }
    if(time >= 0000 && time <= 559){
        return true;
    }
    else{
        return false; 
    }
}

double basic_fare(long distance){ //distance in metre 
    double sum = 3.2000;  
    long distance_10k_more = distance - 10000; 
    if(distance<=1000){
        return 3.2000;
    }
    else if(distance<=10000){
        return 0.22 + basic_fare(distance-400);
    }
    else if(distance-350<10000){
        return 0.22 + basic_fare(10000);
    }
    else{
        return 0.22 + basic_fare(distance-350);
    }
}

double surcharge(bool weekday, bool morning_peak, bool evening_peak, bool midnight_peak){
    double surcharge_amount; 
    if((weekday == true && morning_peak == true) || (evening_peak == true)){
        surcharge_amount = 1.25; 
    }
    else if(midnight_peak == true){
        surcharge_amount = 1.5; 
    }
    else{
        surcharge_amount = 1; 
    }
    return surcharge_amount; 
}


int main(){
    long day = cs1010_read_long(); 
    long hour = cs1010_read_long();
    long min = cs1010_read_long(); 
    long distance = cs1010_read_long(); 
    bool bool_weekday = is_weekday(day);
    bool bool_morning = is_morning_peak(hour, min); 
    bool bool_evening = is_evening_peak(hour, min); 
    bool bool_midnight = is_midnight_peak(hour, min); 
    double surcharge_percent = surcharge(bool_weekday, bool_morning, bool_evening, bool_midnight);
    double b_fare = basic_fare(distance); 
    double total_fare = surcharge_percent * b_fare; 
    cs1010_print_double(total_fare);
    return 0;
}
