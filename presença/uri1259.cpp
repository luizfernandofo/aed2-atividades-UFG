#include<iostream>

#define MAX 100000

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);

		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main(void){

    int nums[MAX], aux[MAX];

    int i, j, k, cases; //counters

    std::cin >> cases;

    for( i = 0; i < cases; i++) std::cin >> nums[i];
    
    quickSort(nums, 0, cases-1);
            
    k=0;
    for( i = 0; i < cases; i++)
        if(nums[i]%2 == 0)
            std::cout << nums[i] << std::endl;
            else{
                aux[k] = i;
                k++;
            }
            
    for( i = k - 1; i >= 0; i--)
            std::cout << nums[aux[i]] << std::endl;
           
            
    return 0;
}