//Kyle Nguyen
#include "lab7.h"
void get_range_count(int number_list[],   /*input, array that holds data */
                     int real_filesize,  /*input, actual size of the data */
                     int *range_count){    /*output, number of values in range */

    *range_count = 0;

    int i;
    for(i = 0; i < real_filesize; i++){
        if(number_list[i] >= 90 && number_list[i] <= 99){
            (*range_count)++;    
        }    
    }
    return;
}
