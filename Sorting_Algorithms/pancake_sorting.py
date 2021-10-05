# Pancake Soring Implementation in Python 

def print_array(array):
    j=0
    while j<len(array):
        print(array[j],end=" ")
        j+=1
    print()
    return


def swap(array,j,n):
    array[j],array[n-j]=array[n-j],array[j]
    return

   
def array_reverse(array,n):
    j=0
    while j<(n+1)//2:
        swap(array,j,n)
        j+=1
    return array

#Start by Assuming that Given array is Unsorted and Cuntinue till array become fully sorted
#    max_index is the variable used to store the index of maximum elemnt from 0 to Unsorted index of array
#    Reverse the given array from 0 to max_index so that local maximum element is at present at index 0
#    Secondly, reverse the array So that maximum element is at it's desired location in Sorted array.

def sorting_pancake(array):
    for Unsorted_index in range(len(array)-1,0,-1):
        max_index=array.index(max(array[:Unsorted_index+1])) 
        array=array_reverse(array,max_index)
        array=array_reverse(array,Unsorted_index)
    return
                      

if __name__=="__main__":
    array=[9,5,7,6,1,2]
    print("Unsorted array: ",end="")
    print_array(array)
    sorting_pancake(array)
    print("Sorted array:  ",end=" ")
    print_array(array)
