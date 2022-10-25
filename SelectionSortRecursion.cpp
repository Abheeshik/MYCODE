#include<iostream>
using namespace std;


void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

void selectionSort(int arr[],int n)
{
    if (n == 0 || n == 1)
    {
        return ;
    }

    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        
            if (arr[i+1] < arr[minIndex])
            {
                minIndex = i+1;
            }
           swap(arr[minIndex],arr[i]);
        
    }

    selectionSort(arr , n-1);
}

int main()
{
    int arr[11] = {62,221343,7,8,9,1,2,3,865,4,3};
    cout << "given array is ";
    printArray(arr,11);
    

    cout << "sorted array is " <<endl; 
    selectionSort(arr,11);
    printArray(arr,11);
    
}