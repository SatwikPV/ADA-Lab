#include<stdio.h>
#include<time.h>
#include<stdlib.h> /* To recognise exit function when compiling with gcc*/
// Quick sort in C

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

void quick(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quick(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quick(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void main()
{
   int a[15000],n, i,j,ch, temp;
   clock_t start,end;

   while(1)
   {
 printf("\n1:For manual entry of N value and array elements");
 printf("\n2:To display time taken for sorting number of elements N in the range 500 to 14500");
 printf("\n3:To exit");
     printf("\nEnter your choice:");
     scanf("%d", &ch);
     switch(ch)
     {
       case 1:  printf("\nEnter the number of elements: ");
		scanf("%d",&n);
		printf("\nEnter array elements: ");
		for(i=0;i<n;i++)
		 {
		  scanf("%d",&a[i]);
		 }
		start=clock();
		quick(a,0,n-1);
		end=clock();
		printf("\nSorted array is: ");
		for(i=0;i<n;i++)
		printf("%d\t",a[i]);
printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
		break;
     case 2:
	       n=500;
	       while(n<=14500) {
	       for(i=0;i<n;i++)
		  {
		    //a[i]=random(1000);
		    a[i]=n-i;
            	  }
	       start=clock();
	       quick(a,0,n-1);
           //Dummy loop to create delay
	   for(j=0;j<500000;j++){ temp=38/600;}
	       end=clock();
printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
	             n=n+1000;
		  }
	      break;
   case 3: exit(0);
   }
   getchar();
    }
}