/*
LAB 12: Program 2.
Date: 18 September 2024
Purpose: WAP in C to Perform Quick Sort to sort an array of size 5 (with user input)
Author: Manas R. Das
*/

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main() {
  int n;
    
  // Asking the user to enter the number of elements in the array
  printf("Enter the number of elements in the array: ");
  // Reading the user input for the size of the array
  scanf("%d", &n);

  // Declaring the array with the size provided by the user
  int data[n];
  
  // Asking the user to input the elements of the array
  printf("Enter %d elements: \n", n);
  // Reading the elements into the array
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }
  
  int p = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array:\n");
  printArray(data, p);
  
  // perform quicksort on data
  quickSort(data, 0, p - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, p);
  
  return 0;
}
/*
OUTPUT:
Enter the number of elements in the array: 7
Enter 7 elements: 
8
7
2
1
0
9
6
Unsorted Array:
8  7  2  1  0  9  6  
Sorted array in ascending order: 
0  1  2  6  7  8  9  
*/