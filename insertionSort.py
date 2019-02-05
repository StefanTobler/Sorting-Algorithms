import time

def slide(array, index):
    value = array[index]
    running = True
    while(index > 0 and running):
        index -= 1
        temp = array[index]
        array[index] = value
        if value > array[index-1]:
            running = False
        elif index == 0:
            array[0] = value
        array[index + 1] = temp


def insertionsort(array):
    for index in range(1, len(array)):
        if(array[index] < array[index-1]):
            slide(array, index)
    return array

a = [787, -739, 458, 174, 267, -7, 774, -769, -613, -489, -677, 211, 984, -3, 751, -658, 687, -692, 909, -4, -211, -975, 903, 29, -754, -315, -476, -890, -248, 323, -358, 92, -720, -563, -423, 552, 746, 616, -435, -678, 632, -89, -97, -338, 320, 887, -873, 600, -897, 644]
t = time.clock()
print(insertionsort(a))
print("Insertion sort took {} seconds to execute".format(time.clock() - t))
