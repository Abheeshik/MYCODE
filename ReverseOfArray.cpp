#include<iostream>
using namespace std;

void PrintArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void ReverseOfArray(int arr[] , int n )
{
    int start = 0;
    int end = n-1;

    while (start <= end)
    {
       swap(arr[start],arr[end]);

        start++;
        end--;


    }
    
}

int main(){

    int size;

    cout << "ENTER THE SIZE OF ARRAY " << endl;
    cin >> size;

    int num[10];

    for (int  i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout << "THE GIVEN ARRAY IS " << endl;
    PrintArray(num , size);
    cout << endl;

    cout << "THE REVERSE OF GIVEN ARRAY IS " << endl;
    ReverseOfArray(num , size);
    PrintArray(num ,size);
    
}