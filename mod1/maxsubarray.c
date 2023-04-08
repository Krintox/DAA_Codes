#include <stdio.h>

// function for kadane's algorithm
static void kadane(int Array[], int n) {
  int max_sum = 0;
  int current_sum = 0;

  int max_start = 0;
  int max_end = 0;
  int current_start = 0;
  int current_end = 0;

  for(int i=0; i<n; i++) {
    current_sum = current_sum + Array[i];
    current_end = i;
    
    if (current_sum < 0) {
      current_sum = 0;
      //Start a new sequence from next element
      current_start = current_end + 1;
    }

    if(max_sum < current_sum)
    {
      max_sum = current_sum;
      max_start = current_start;
      max_end = current_end;
    }
  }
  
  printf("Maximum SubArray is: %i\n", max_sum);
  printf("Start index of max_Sum: %i\n", max_start);
  printf("End index of max_Sum: %i\n", max_end);
}

int main() {
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int MyArray[n];
  printf("Enter the array elements: ");
  for(int i=0; i<n; i++) {
    scanf("%d", &MyArray[i]);
  }
  
  kadane(MyArray, n);
  return 0;
}
