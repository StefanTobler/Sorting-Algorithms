//
//  bogoSort.c
//  BogoSort
//
//  Created by Stefan Tobler on 12/11/18.
//
// This sorting algorithm is useless. It pseudo-randomly generates an array of the numbers in
// given array and then compares it to see if the generated array is sorted.
//
// Complexity - O((n+1)!)
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Checks to see if each item in the array is less than the item infront of it.
int isSorted(int *array, size_t length){
    for(int i = 0; i < length - 1; i++){
        if(array[i] > array[i + 1]){
            return 0;
        }
    }

    return 1;

}

// Shuffles the given array
void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}


void bogoSort(int *array, size_t length){
    long count = 0;
    while(isSorted(array, length) != 1){
        shuffle(array, length);
        
        count++;
    }
    printf("It took %ld comparisons to sort the array.\n", count);

    for(int i = 0; i < length; i++){
        printf("%d", array[i]);
    }
    printf("\n");

}

int main(int argc, const char * argv[]) {

    clock_t start, end;
    double timeUsed;

    int arr[] = {787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644};
    size_t length = sizeof(arr)/sizeof(int);

    start = clock();

    bogoSort(arr, length);

    end = clock();

    timeUsed = ((double) end - start) / CLOCKS_PER_SEC;

    printf("Bogo Sort took %f seconds to execute \n", timeUsed);
    return 0;
}
