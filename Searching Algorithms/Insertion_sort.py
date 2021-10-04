def insertionAscending(array):
    l=len(array)
    for i in range(1,l):
        a=array[i]
        j=i-1
        while j>=0 and array[j]>a:
            array[j+1]=array[j]
            j-=1
        array[j+1]=a
    return array

def insertionDescending(array):
    l=len(array)
    for i in range(1,l):
        a=array[i]
        j=i-1
        while j>=0 and array[j]<a:
            array[j+1]=array[j]
            j-=1
        array[j+1]=a
    return array

def display(array):
    for i in array:
        print(i,end=" ")
    print()

if __name__=="__main__":
    array=list(map(int,input("Array: ").split()))
    display(insertionAscending(array))
    display(insertionDescending(array))