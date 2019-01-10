//
//  selectionsort.c
//  Selection Sort
//
//  Created by Stefan Tobler on 12/11/18.
//
// Complexity - O(n^2)
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Swaps two items in an array
void swap(int *array, int i, int j){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void selectionSort(int *array, size_t length){
    long count = 0;
    for(int i = 0; i < length; i++){
      int low = array[i];
      int index = i;
      // Checks each item in the array in front of the last item that was sorted.
        for(int j = i + 1; j < length; j ++){
          // If the item item is lower than the current lowest item then the index is saved so that it can be swapped.
            if(array[j] < low){
              low = array[j];
              index = j;
            }
            count++;
        }
        count++;
        // This might be unnessary if i and index are the same.
        swap(array, i, index);
    }

    for(int i = 0; i < length; i++){
      printf("%d ", array[i]);
    }


    printf("\nIt took %ld comparisons to sort the array.\n", count);

}

int main(int argc, const char * argv[]) {

    clock_t start, end;
    double timeUsed;
    int arr[] = {787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644};
    size_t length = sizeof(arr)/sizeof(int);

    start = clock();

    selectionSort(arr, length);

    end = clock();

    timeUsed = ((double) end - start) / CLOCKS_PER_SEC;

    printf("Selection Sort took %f seconds to execute \n", timeUsed);
    return 0;
}
