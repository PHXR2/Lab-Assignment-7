#include <stdio.h>

//Palmer H.
// A function to swap two elements in an array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A function to implement bubble sort on an array
// It returns the total number of swaps performed
int bubble_sort(int arr[], int n) {
  int i, j, swaps = 0;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swaps++;
      }
    }
  }
  return swaps;
}

// A function to implement selection sort on an array
// It returns the total number of swaps performed
int selection_sort(int arr[], int n) {
  int i, j, min_idx, swaps = 0;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      swap(&arr[i], &arr[min_idx]);
      swaps++;
    }
  }
  return swaps;
}

// A function to print an array and the number of swaps for each element
void print_array(int arr[], int n, int swaps[]) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swaps[i]);
  }
  printf("total swaps: %d\n", swaps[n]);
}

// A function to count the number of swaps for each element in an array
// It uses a copy of the original array and sorts it using bubble or selection sort
// It compares the positions of the elements before and after sorting
// It stores the results in an array of swaps
void count_swaps(int arr[], int n, int swaps[], int sort_type) {
  int i, j, k, copy[n];
  for (i = 0; i < n; i++) {
    copy[i] = arr[i];
    swaps[i] = 0;
  }
  if (sort_type == 0) {
    swaps[n] = bubble_sort(copy, n);
  } else {
    swaps[n] = selection_sort(copy, n);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (arr[i] == copy[j]) {
        k = i - j;
        if (k < 0) {
          k = -k;
        }
        swaps[i] = k;
        break;
      }
    }
  }
}

// The main function to test the program
int main() {
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n1 = sizeof(array1) / sizeof(array1[0]);
  int n2 = sizeof(array2) / sizeof(array2[0]);
  int swaps1[n1 + 1], swaps2[n2 + 1];

  // Count the swaps for array1 using bubble sort
  count_swaps(array1, n1, swaps1, 0);
  printf("array1:\n");
  print_array(array1, n1, swaps1);

  // Count the swaps for array2 using selection sort
  count_swaps(array2, n2, swaps2, 1);
  printf("array2:\n");
  print_array(array2, n2, swaps2);

  printf("The reason why the total number of swaps is not equal to the sum of the swaps of each value is that some values may be swapped more than once in the sorting process. For example, in array1, 97 is swapped 8 times, but it is not counted 8 times in the total number of swaps. The total number of swaps only counts the number of times two similar elements are exchanged in bubble sort, or the number of times the minimum element is moved to the front in selection sort.");

  return 0;
}
