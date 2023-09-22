/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int score = 0;
    cin >> score;
    if(score<=100&&score>=90)
    {
        cout << "A";
        return 0;
    }
    else if(score<=89&&score>=80)
    {
        cout << "B";
        return 0;
    }
    else if(score<=79&&score>=70)
    {
        cout << "C";
        return 0;
    }
    else if(score<=69&&score>=60)
    {
        cout << "D";
        return 0;
    }
    else
    {
        cout << "F";
        return 0;
    }
}
