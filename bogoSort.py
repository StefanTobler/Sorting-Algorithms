import random
import time

def is_sorted(array):
    for index in range(len(array) - 1):
        if array[index] > array[i + 1]:
            return False
    return True

def bogosort(array):
    count = 0
    while not is_sorted(array):
        random.shuffle(array)
        count += 1;
    print(count)
    return array

a = [787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644]
t = time.clock()
print(bogosort(a))
print("BogoSort took {} seconds to execute".format(time.clock() - t))
