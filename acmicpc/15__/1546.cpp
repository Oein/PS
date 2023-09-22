#include <iostream>

using namespace std;

int main()
{
    int N=0; 
    int M=0;
    int score[1000];
    double score2[1000];
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> score[i];
    }
    
    
    // 최댓값을 구한다.
    M = score[0];
    for(int i=0; i<N;i++)
    {
        if(M<score[i])
        {
            M = score[i];
        }
    }
    
    
    //점수를 조작한다
    for(int i=0;i<N;i++)
    {
        score2[i]=(double)score[i]/(double)M*100.0;
        
    }
    
    
    
    //평균을 구한다
    double average = 0.0;
    for(int i=0;i<N;i++)
    {
        average += score2[i];
    }
    average /= (double)N;
    
    
    // 정답을 출력한다 
    cout << average;
}









