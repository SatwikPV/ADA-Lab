#include <stdio.h>
#include <time.h>

void insSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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
		insSort(a,n);
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
	       insSort(a,n);
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