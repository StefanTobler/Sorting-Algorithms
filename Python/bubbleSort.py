import time

def swap(array, index1, index2):
    temp = array[index1]
    array[index1] = array[index2]
    array[index2] = temp

def bubbleSort(array):
    flag = True

    while(flag):
        flag = False
        for index in range(1, len(array)):
            if(array[index] < array[index - 1]):
                swap(array, index, index-1)
                flag = True
    return array




a = [787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644]
t = time.clock()
print(bubbleSort(a))
print("Insertion sort took {} seconds to execute".format(time.clock() - t))
