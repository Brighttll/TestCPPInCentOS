#include "TestStl.h"

void TestStl::MainFun()
{
    cout << "Enter STL Main Function" <<endl;
    TestVector();
}

void TestStl::TestVector()
{
    vector<int> ints {4,16,7,8,2,3,5,734,234};
    for(auto ite = ints.begin(); ite != ints.end(); ite++)
    {
   	cout << *ite << "\t";
    }

    //std::sort(ints.begin(), ints.end(), less<int>());
    std::sort(ints.begin(), ints.end(), bigger<int>());
    cout << endl;
    for(auto ite = ints.begin(); ite != ints.end(); ite++)
    {
   	cout << *ite << "\t";
    }
    cout << endl;
}
