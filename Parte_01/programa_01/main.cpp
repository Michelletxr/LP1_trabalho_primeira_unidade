#include <iostream>
#include<vector>
#include<string>

using namespace std;

void printVector( vector<int> vec)
{

    string os;

    cout << os << "vector: {";

    for(auto i{0}; i < vec.size(); i++)
    {
        cout << os << vec[i];
        i!=(vec.size()-1)? cout << ", " : cout << "} ";
    }

    cout<< os << endl;
}

int main(void)

{
    vector<int> vec(5);

    cout << "Indique os elementos do vector: ";
   
    for (size_t i = 0; i < vec.size(); i++){cin >> vec[i];}

    printVector(vec);

    return 0;
}