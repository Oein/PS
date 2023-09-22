#include <iostream>

using namespace std;

int main()
{
    int N, T ,T2;
    int five   =0;
    int three  =0;
    cin>>N;
    
    five = N/5;     // 5KG 봉지의 개수.
    T = N%5;        // 5KG 봉지에 담고 남은 설탕.
    
    if(T==0)
    {
        
    }
    else if(T==1)
    {
        if(five>0)
        {
            five--;
            three=2;
        }
        else
        {
            cout<<"-1";
            return 0;
        }
    }
    else if(T==2)
    {
        if(five>1)
        {
            five-=2;
            three=4;
        }
        else
        {
            cout<<"-1";
            return 0;
        }
    }
    else if(T==3)
    {
        three=1;
    }
    else if(T==4)
    {
        if(five>0)
        {
            five--;
            three=3;
        }
        else
        {
            cout<<"-1";
            return 0;
        }
    }
    cout << five+three;
    
    
    return 0;
    
}
