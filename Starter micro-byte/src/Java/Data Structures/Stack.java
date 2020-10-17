import java.util.*;
class Stack
{
    int size=10;
    int stack[]=new int[size];
    int top;
    
    Stack()
    {
        top=0;
    }
    
    public void push(int num)
    {
        if(top>size-1)
            System.out.println("Stack Overflow Error");
        else
        {
            stack[top++]=num;
            System.out.println(num+" is pushed into the stack");
        }
    }
    
    public int pop()
    {
        if(top<=0)
        {
            System.out.println("Stack Underflow Error");
            return 0;
        }
        else
            return stack[--top];
    }
      
    public int top_element()
    {
        if(top<=0)
        {
            System.out.println("Stack Underflow Error");
            return 0;
        }
        else
            return stack[--top];
    }
        
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        Stack obj=new Stack();
        for(int i=0;i<100;++i)
        {
            System.out.println("Enter 1 to push, 2 to pop, 3 to know the top element of stack and 4 to exit");
            int choice=sc.nextInt();
            switch(choice)
            {
                case 1: System.out.println("Enter a number to be pushed:");
                        int n=sc.nextInt();
                        obj.push(n);
                        break;
                case 2: int pop=obj.pop();
                        if(pop!=0)
                        {
                            System.out.println("The popped number is:"+pop);
                            break;
                        }
                case 3: int top_element=obj.top_element();
                        if(top_element!=0)
                        {
                            System.out.println("The top element of the stack is:"+top_element);
                            break;
                        }
                case 4: System.out.println("Thanks for implementing");
                        System.exit(0);
                default: System.out.println("Wrong Choice! Please try again!");
                         break;
            }
        }
    }
}