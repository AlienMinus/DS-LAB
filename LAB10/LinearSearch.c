/*
LAB 10: Program 2.
Date: 28 August 2024
Purpose: WAP in C to perform Linear Search
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[10],search,i,n,c;
    do{
        printf("\nEnter number of elements: ");
        scanf("%d",&n);
        printf("\nEnter %d numbers: \n",n);
        for (int i = 0; i < n; i++)
        scanf("%d",&array[i]);
        printf("\nEnter the number to search: ");
        scanf("%d",&search);
        for (int i = 0; i < n; i++){
            if (array[i]==search){
                printf("\n%d is present at location %d.\n",search,i+1);
                break;
            }
        }
        if(i==n)
        printf("\n%d is not present in the array.\n",search);
        printf("\nEnter 0 to Perform the Operation Again: ");
        scanf("%d",&c);
    }while(c==0);
    return 0;
}
/*
OUTPUT:
Enter number of elements: 5

Enter 5 numbers: 
5
4
9
2
7

Enter the number to search: 2

2 is present at location 4.

Enter 0 to Perform the Operation Again: 0

Enter number of elements: 5

Enter 5 numbers: 
77
43
62
81
34

Enter the number to search: 43

43 is present at location 2.

Enter 0 to Perform the Operation Again: 

*/