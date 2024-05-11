#include <iostream>

using namespace std;

int main()
{
    int A, B, C, N;
    cin >> A >> B >> C >> N;

    for (int a = 0; a <= 100; a++)
    {
        for (int b = 0; b <= 100; b++)
        {

            for (int c = 0; c <= 100; c++)
            {
                if (((a * A) + (b * B) + (c * C)) == N)
                {
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}