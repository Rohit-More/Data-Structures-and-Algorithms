#insertion sort
#time complexity O(n**2)

def insertion(arr):
    #arranging a card with two hands , one hand woth sorted cards and another with unsorted one
    for i in range(1,len(arr)):
        j=i-1
        key=arr[i]
        while j>=0 and arr[j]>key:     
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
    return (arr)

#main
ar='3 4 2 12 34 21'
arr=list(map(int,ar.split()))
print(insertion(arr))
