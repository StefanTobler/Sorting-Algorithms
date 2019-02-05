//
//  mergeSort.c
//  Merge Sort
//
//  Created by Stefan Tobler on 12/11/18.
//
// Incomplete
//
// Complexity - O(nlog(n))
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long merge(int *array, int p, int q, int r){
  int high[q-p];
  int low[r-q];
  long count = 0;
  int i, j;
  int k = p;
  printf("Array: ");
  for(int z = 0; z < 50; z++){
    printf("%d ", array[z]);
  }
  printf("\n");

  for(i = 0; k < q; i++, k++){
    low[i] = array[k];
    printf("%d \n", array[k]);
  }

  for(j = 0; k <= r; i++, k++){
    high[j] = array[k];
    printf("%d \n", array[k]);
  }

  i = 0;
  j = 0;

  k = p;

  while (i < (q - p + 1) & j < (r - q - 1)){
    count++;
    if(low[i] < high[j]){
      array[k] = low[i];
      i++;
    }
    else{
      array[k] = high[j];
      j++;
    }
    k++;
  }

  while(i < q - p + 1){
    array[k] = low[i];
    k++;
    i++;
  }

  while(j < r - q - 1){
    array[k] = high[j];
    k++;
    j++;
  }
  return count;
}

long mergeSort(int *array, int p, int r){
  int q = (r + p) / 2;
  long count = 0;

  if (p < r){
    count += mergeSort(array, p, q);
    count += mergeSort(array,  q+1, r);
    count += merge(array, p, q, r);
  }

  return count;
}

int main(int argc, const char * argv[]) {

    clock_t start, end;
    double timeUsed;
    int arr[] = {787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644};
    size_t length = sizeof(arr)/sizeof(int);

    start = clock();

    long count = mergeSort(arr, 0, length-1);

    end = clock();

    for(int i = 0; i < length; i++){
      printf("%d ", arr[i]);
    }


    printf("\nIt took %ld comparisons to sort the array.\n", count);

    timeUsed = ((double) end - start) / CLOCKS_PER_SEC;

    printf("Merge Sort took %f seconds to execute \n", timeUsed);
    return 0;
}
