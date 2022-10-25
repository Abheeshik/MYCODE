#include<iostream>
using namespace std;

void print(int arr[] , int size)
{
    cout << "size of array is " << size <<  endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
} 
bool LinearSearch(int arr[], int size,int key)
{
    print(arr,size);


    if (size == 0)
    {
        return false;
    }
    if ( arr[0] == key)
    {
        return true;
    }
    
    else
    {
         
        return LinearSearch( arr + 1 , size -1,key);
    }
    

}

int main()
{
    int arr[] = {2,4,1,6,7,5};

    int size = 6;

    int key = 1;

    bool ans = LinearSearch(arr,size,key);

    

    if (ans)
    {
       cout << "element found" << endl;
    }
    else{
        cout << "element not found" << endl;
        
    }
}