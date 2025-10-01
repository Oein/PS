/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    int N=0;
    int count[10001];
    for(int i=0;i<10001;i++)
    {
        count[i]=0;
    }
    
    cin >> N;
    
    int number=0;
    for(int i=0;i<N;i++)
    {
        cin >> number;
        count[number]++;
    }
    
    for(int a=0;a<10001;a++)
    {
        for(int i=0;i<count[a];i++)
        {
            cout << a << '\n';
        }
    }
}
