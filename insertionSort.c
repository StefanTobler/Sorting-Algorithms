//
//  mergeSort.c
//  Insertion Sort
//
//  Created by Stefan Tobler on 12/11/18.
//
// Complexity - O(n^2)
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// This method is called if the item before the index is greater than it.
// The item will be sorted and all the values will be slid to the right until an
// item is less than the compared value, then the stored value will be placed infront of it.
int slide(int *array, int index){
  int store = array[index];
  int count = 0;
  // Slides items to the left of the index, right
  for(int j = index - 1; j >= 0; j--){
    count++;
    array[j + 1] = array[j];
    if (array[j] < store){
      array[j + 1] = store;
      return count;
    }
    else if (j == 0){
      array[j] = store;
    }
  }
  return count;
}

void insertionSort(int *array, size_t length){
  long count = 0;
  // Compares each item to the item in front of it, if the item in front of it is
  // less than the item at the current index, then the array will slide to the left
  // until an item is less than the item at the observed index.
  for(int i = 1; i < length; i++){
    if (array[i] < array[i-1]){
      count += slide(array, i);
    }
  }

  for(int i = 0; i < length; i++){
    printf("%d ", array[i]);
  }


  printf("\nIt took %ld comparisons to sort the array.\n", count);

}


int main(int argc, const char * argv[]) {

    clock_t start, end;
    double timeUsed;
    int arr[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    //int arr[] = {787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644};
    size_t length = sizeof(arr)/sizeof(int);

    start = clock();

    insertionSort(arr, length);

    end = clock();

    timeUsed = ((double) end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort took %f seconds to execute \n", timeUsed);
    return 0;
}
