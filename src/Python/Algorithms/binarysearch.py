def binarysearch(llist,key):#this algorithm is efficient than linear search as its complexity is O(logn)
    low=0
    high=len(llist)-1
    while(low<=high):
        mid=(low+high)//2
        if llist[mid]==key: #if the element is found at mid
            return mid+1 #return its position
        elif llist[mid]<key:
            low=mid+1
        else:
            high=mid-1
    return -1 #it returns -1 if the key is not found
llist=[int(x) for x in input().split()]
key=int(input())
position=binarysearch(llist,key)
if position==-1:
    print("Not Found!")
else:
    print("Found")
