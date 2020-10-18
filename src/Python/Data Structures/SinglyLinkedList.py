"""
    Creating a linked list.
    Adding elements to it.
    Deleting element from it.
    Searching position of an element if present.
    Viewing it.
"""

class Node:    
    def __init__(self, data): 
        self.data = data  
        self.next = None 

class LinkedList: 
    def __init__(self):  
        self.head = None
        
    def append_start(self, value):
        newNode = Node(value)
        newNode.next = self.head
        self.head = newNode
        
    def append_in_between(self, value, position):
        newNode = Node(value)
        temp = self.head
        for i in range(position-2):
            temp = temp.next
        newNode.next = temp.next
        temp.next = newNode        
    
    def append_end(self, value):
        newNode = Node(value)
        if(self.head == None):
            self.head = newNode
        else:
            temp =  self.head
            while(temp.next != None):
                temp = temp.next
            temp.next = newNode
    
    def delete_start(self):
        if self.head == None:
            print("Linkedlist is empty")        
        else:
            self.head = self.head.next
    
    def delete_in_between(self, position):
        temp = self.head
        for i in range(position-2):
            temp = temp.next
        temp.next = temp.next.next
        
    def delete_end(self):
        temp = self.head
        while temp.next.next != None:
            temp = temp.next
        temp.next = None
        
    def view(self):
        if self.head == None:
            print("List is empty")
        else:
            temp = self.head
            while temp != None:
                print(temp.data, end=' ')
                temp = temp.next
                
    def search(self, value):
        temp = self.head
        position = 1
        c = 0
        if temp.data == value:
            print(position)
            
        while temp.next != None:
            temp = temp.next
            position = position+1
            if temp.data == value:
                c = c+1
                print("The searched value is present at position(s): ")
                print(position)
                
        if c == 0:        
            print("The value isn't present.")

mylist = LinkedList()

while(1):
    print("\nChoose 1.To append at start")
    print("2.To append in between") 
    print("3.To append at end.")
    print("4.To delete from start")
    print("5.To delete from between")
    print("6.To delete from end.")
    print("7.To View Linkedlist")
    print("8.Search a value's position")
    print("9.To view and exit.")
    
    K = int(input("Choose an option between 1 to 9: "))

    if K==1:
        A = int(input("Enter the value to append: "))
        mylist.append_start(A)
    
    elif K==2:
        B = int(input("Enter the value to append: "))
        C = int(input("Enter the position for the value: "))
        mylist.append_in_between(B, C)
        
    elif K==3:
        D = int(input("Enter the value to append: "))
        mylist.append_end(D)
        
    elif K==4:
        mylist.delete_start()
        
    elif K==5:
        E = int(input("Enter the position you want to delete: "))
        mylist.delete_in_between(E)
        
    elif K==6:
        mylist.delete_end()
    
    elif K==7:
        mylist.view()
        print()
    
    elif K==8:
        F = int(input("Enter value you want to search: "))
        mylist.search(F)
    
    elif K==9:
        mylist.view()
        break
    
    else:
        print("Not a valid input! Choose a number between 1 to 9.\n")
