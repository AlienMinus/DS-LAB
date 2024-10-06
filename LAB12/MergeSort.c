/*
LAB 12: Program 1.
Date: 18 September 2024
Purpose: WAP in C to Perform Merge Sort to sort an array of size 5
Author: Manas R. Das
*/
#include <stdio.h>  

// Defining the merge function that is merging two subarrays
void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    // Calculating the size of the first subarray
    int n1 = mid - beg + 1;    
    // Calculating the size of the second subarray
    int n2 = end - mid;    
      
    // Declaring two temporary arrays for left and right halves
    int LeftArray[n1], RightArray[n2];  
      
    // Copying the left half of the original array into LeftArray
    for (int i = 0; i < n1; i++)    
        LeftArray[i] = a[beg + i];    
    // Copying the right half of the original array into RightArray
    for (int j = 0; j < n2; j++)    
        RightArray[j] = a[mid + 1 + j];    
      
    // Initializing indices for subarrays and the merged array
    i = 0;  
    j = 0;  
    k = beg;  
      
    // Merging both subarrays into the original array in sorted order
    while (i < n1 && j < n2)    
    {    
        // Checking if the current element in LeftArray is less than or equal to RightArray
        if (LeftArray[i] <= RightArray[j])    
        {    
            // Assigning the smaller element from LeftArray to the original array
            a[k] = LeftArray[i];    
            // Moving to the next element in LeftArray
            i++;    
        }    
        else    
        {    
            // Assigning the smaller element from RightArray to the original array
            a[k] = RightArray[j];    
            // Moving to the next element in RightArray
            j++;    
        }    
        // Incrementing the index of the merged array
        k++;    
    }    
    // Copying any remaining elements in LeftArray
    while (i < n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    // Copying any remaining elements in RightArray
    while (j < n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
// Defining the mergeSort function that is sorting the array recursively
void mergeSort(int a[], int beg, int end)  
{  
    // Checking if the beginning index is less than the end index
    if (beg < end)   
    {  
        // Finding the middle index of the array
        int mid = (beg + end) / 2;  
        // Recursively sorting the left half of the array
        mergeSort(a, beg, mid);  
        // Recursively sorting the right half of the array
        mergeSort(a, mid + 1, end);  
        // Merging the sorted subarrays
        merge(a, beg, mid, end);  
    }  
}  
  
// Defining the function that is printing the array elements
void printArray(int a[], int n)  
{  
    // Looping through the array elements
    for (int i = 0; i < n; i++)  
        // Printing each element followed by a space
        printf("%d ", a[i]);  
    // Moving to the next line after printing all elements
    printf("\n");  
}  
  
int main()  
{  
    int n;
    
    // Asking the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    // Reading the user input for the size of the array
    scanf("%d", &n);

    // Declaring the array with the size provided by the user
    int a[n];

    // Asking the user to input the elements of the array
    printf("Enter %d elements: \n", n);
    // Reading the elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Printing the array before sorting
    printf("Before sorting, array elements are - \n");  
    printArray(a, n);  
    
    // Calling the mergeSort function to sort the array
    mergeSort(a, 0, n - 1);  
    
    // Printing the array after sorting
    printf("After sorting, array elements are - \n");  
    printArray(a, n);  
    
    return 0;  
}
/*
OUTPUT:
Enter the number of elements in the array: 8
Enter 8 elements: 
12
31
25
8
32
17
40
42
Before sorting, array elements are - 
12 31 25 8 32 17 40 42 
After sorting, array elements are - 
8 12 17 25 31 32 40 42  
*/