/** 
 * Selection Sort
 * Time complexity = O(n^2)
 * @author Stefan Tobler
 */

public class SelectionSort{
    
    public static void swap(int[] array, int index1, int index2){
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
    } // swap 

    public static void selectionSort(int[] array){
	for(int i = 0; i < array.length; i++){
	    int index = i;
	    int low = array[i];
	    for(int j = i + 1; j < array.length; j++){
		if(low > array[j]){
		    low = array[j];
		    index = j;
		} // if
	    } // for
	    swap(array, i, index);
	} // for
    } // selectionSort

    public static void main(String[] args){
	int[] array = new int[] {787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644};
	long time = System.nanoTime();

	selectionSort(array);

	System.out.print("[");
	for(int i = 0; i < array.length-1; i++){
	    System.out.print(array[i] + ", ");
	} // for
	System.out.println(array[array.length-1] + "]");
	System.out.println("Selection sort in Java took " + ((double)(System.nanoTime() - time)/1000000000) + " seconds.");	
    } // main

} // SelectionSort