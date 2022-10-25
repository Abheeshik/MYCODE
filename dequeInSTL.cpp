#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_front(1);
    d.push_front(2);
    d.push_back(3);

    cout << "value at first index is " << d.at(0) << endl;

    

    //for(int i:d)
    //{
        //cout << i << " ";
    //}cout << endl;

    //d.pop_front();
    //cout << endl;
    //for( int i:d)
    //{
        //cout << i << " ";
    //}//cout << endl;
}