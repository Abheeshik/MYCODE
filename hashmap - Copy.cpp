#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    map<string,int> m;

    pair<string,int> p1 = make_pair("abhi1",1);
    m.insert(p1);

    pair<string,int> p2("abhi2",3);
    m.insert(p2);

    m["abhi3"]=4;

    m["abhi4"]=5;

    //cout << m["abcd"] << endl;

    //cout << m["as"] << endl;
    //cout << m.at("as") << endl;

    //cout << "size - " << m.size() << endl;

    //cout << m.count("abcd") << endl;
    //cout << m.count("wqww") << endl;

   // m.erase("asde");

    cout << "size - " << m.size() << endl;

    /*for(auto i:m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;
    */

   map<string,int> :: iterator it = m.begin();

   while(it != m.end())
   {
    cout << it->first << " " << it->second << endl;
    it++;
   }

}

