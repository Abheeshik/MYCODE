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

void bubbleSort(int arr[],int n)
{   
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
    
    
}


int main()
{
    int arr[5] = {6,2,8,7,10};
    cout << "given array is ";
    printArray(arr,5);
    cout << endl;

    cout << "sorted array is " << endl;
     bubbleSort(arr,5);
    printArray(arr,5);
    
}