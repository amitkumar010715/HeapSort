#include<stdio.h>
#define size 5
 void heap_sort(int arr[],int heap_size);
void  built_maxheap(int arr[],int heap_size);
    void   max_heapify( int arr[], int heap_size ,int i);





void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

 void heap_sort(int arr[],int heap_size){
    built_maxheap(arr,heap_size);
    for (int i = heap_size; i <=2; i--)
    {
      swap(&arr[1], &arr[i]);
	}
      heap_size=heap_size-1;
      max_heapify(arr,heap_size,1);
     
    
    
}
    void   max_heapify( int arr[], int heap_size ,int i){
	
	int largest = i;
	int left = 2 * i ;
	int right = 2 * i +1;

	if (left <= heap_size && arr[left] > arr[largest])
		largest = left;

	if (right <= heap_size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {

		swap(&arr[i], &arr[largest]);
		max_heapify(arr, heap_size, largest);
	}
    }
void  built_maxheap(int arr[],int heap_size){
    for (int i = heap_size/2; i >=1; i--)
    {
      	max_heapify(arr,heap_size,i);
    }
    
}
 

int main()
{
    int arr[size]={-1,3,7,5,4};
        int heap_size = size -1;
        heap_sort(arr,heap_size); 
		  for(int i=1;i<=heap_size;i++){
         printf("%d ",arr[i]);
     }
    return 0;
}
