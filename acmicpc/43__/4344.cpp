/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    cout.precision(3);
    cout.setf(ios::fixed);
    
    
    int C=0;    // 테스트 케이스의 수 
    int N=0;    // 학생의 수 
    int NUP=0;  // 평균을 넘는 학생의 수 
    double PER=0; // 평균을 넘는 학생의 비율
    double pengun=0;    // 평균 
    int score[1000];    // 학생의 점수.
    
    cin >> C;
    for(int x=0;x<C;x++)
    {
        // 학생의 점수를 받는다.
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> score[i];
        }
        
        
        // 평균을 구한다.
        pengun=0;
        for(int i=0;i<N;i++)
        {
            pengun += (double)score[i];
        }
        pengun /= (double)N;
        
        
        // 평균을 넘는 학생의 수를 구한다.
        NUP=0;
        for(int i=0;i<N;i++)
        {
            if((double)score[i]>pengun)
            {
                NUP+=1;
            }
        }
        
        
        // 평균을 넘는 학생의 비율을 구한다.
        PER = (double)NUP /(double)N * 100;
        cout << PER << "%" << endl;
    }
}









