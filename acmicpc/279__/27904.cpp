#include <iostream>
#include <string>
using namespace std;

void rmain()
{
    string b[6];
    for (int i = 1; i <= 4; i++)
    {
        cin >> b[i];
        b[i] = " " + b[i];
    }
    int r = -1;
    if (b[4][1] == 'X')
    {
        if (b[1][1] == 'X')
        {
            if (b[2][3] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][2] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][2] == 'X')
                {
                    if (b[3][1] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][2] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][4] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][1] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][2] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][1] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[4][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][3] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][2] == 'X')
                {
                    if (b[1][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][2] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[4][4] == 'X')
                {
                    if (b[1][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][2] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[4][3] == 'O')
                {
                    r = 0;
                }
                else if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][2] == 'X')
            {
                if (b[1][4] == 'X')
                {
                    if (b[4][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][2] == 'O')
                {
                    if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[1][2] == 'X')
                    {
                        if (b[4][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][3] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[3][4] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][4] == 'X')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[2][1] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][2] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    if (b[1][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[4][4] == 'X')
                        {
                            r = 0;
                        }
                        else if (b[4][3] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][2] == 'X')
                {
                    if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][4] == 'O')
            {
                if (b[3][4] == 'O')
                {
                    if (b[4][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][2] == 'X')
                    {
                        if (b[2][1] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[2][2] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    if (b[2][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][3] == 'X')
                {
                    if (b[2][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][2] == 'X')
                    {
                        if (b[2][1] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[2][2] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][2] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[4][2] == 'X')
                {
                    if (b[4][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][2] == 'O')
            {
                if (b[2][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[1][2] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[2][1] == 'X')
                {
                    if (b[3][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[1][2] == 'X')
                {
                    if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'O')
            {
                if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][2] == 'O')
            {
                if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'O')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[3][4] == 'X')
            {
                if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][3] == 'O')
        {
            if (b[3][1] == 'O')
            {
                if (b[1][4] == 'O')
                {
                    if (b[4][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][2] == 'O')
                {
                    if (b[4][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][2] == 'X')
                {
                    if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][2] == 'X')
                    {
                        if (b[2][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][3] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[3][4] == 'O')
                {
                    if (b[3][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[4][4] == 'X')
                        {
                            r = 0;
                        }
                        else if (b[4][3] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][3] == 'X')
                {
                    if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[2][1] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][2] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][2] == 'X')
                {
                    if (b[2][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][2] == 'X')
            {
                if (b[1][4] == 'X')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        if (b[4][2] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][1] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][2] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[4][2] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][2] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[1][2] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[2][1] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[4][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][2] == 'X')
                {
                    if (b[2][2] == 'X')
                    {
                        if (b[1][2] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[2][1] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][3] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[1][3] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[2][1] == 'X')
                    {
                        if (b[1][2] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][4] == 'X')
                        {
                            if (b[3][3] == 'O')
                            {
                                r = 1;
                            }
                            else if (b[3][4] == 'X')
                            {
                                r = 0;
                            }
                            else
                            {
                                r = 1;
                            }
                        }
                        else if (b[4][3] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[2][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[3][4] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'X')
                    {
                        if (b[2][4] == 'X')
                        {
                            r = 1;
                        }
                        else if (b[4][3] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][2] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'O')
                    {
                        if (b[2][4] == 'O')
                        {
                            r = 0;
                        }
                        else if (b[4][3] == 'X')
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    else if (b[3][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][4] == 'O')
            {
                if (b[4][2] == 'X')
                {
                    if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][2] == 'X')
            {
                if (b[2][2] == 'X')
                {
                    if (b[3][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[2][4] == 'X')
                    {
                        if (b[3][3] == 'X')
                        {
                            r = 0;
                        }
                        else if (b[1][3] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[3][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][2] == 'O')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][4] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][2] == 'O')
            {
                if (b[3][4] == 'X')
                {
                    if (b[2][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    if (b[3][3] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[4][3] == 'O')
                {
                    r = 0;
                }
                else if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][2] == 'O')
            {
                r = 0;
            }
            else if (b[4][4] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[3][1] == 'X')
        {
            if (b[3][2] == 'X')
            {
                r = 0;
            }
            else if (b[1][4] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][2] == 'O')
            {
                if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else if (b[3][3] == 'X')
                {
                    if (b[2][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[1][3] == 'O')
                {
                    if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][2] == 'O')
            {
                if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[1][2] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[3][3] == 'X')
                {
                    if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][2] == 'X')
            {
                if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'O')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[3][2] == 'X')
        {
            if (b[1][4] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][2] == 'O')
            {
                if (b[3][4] == 'X')
                {
                    if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[1][2] == 'X')
                    {
                        if (b[3][3] == 'X')
                        {
                            r = 0;
                        }
                        else if (b[1][3] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][2] == 'O')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'O')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][1] == 'O')
                {
                    if (b[1][2] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'O')
                {
                    if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][4] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'O')
            {
                if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'X')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][4] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][4] == 'O')
        {
            if (b[3][4] == 'O')
            {
                r = 1;
            }
            else if (b[4][2] == 'X')
            {
                if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[1][2] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][2] == 'O')
            {
                r = 0;
            }
            else if (b[1][2] == 'X')
            {
                if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][2] == 'O')
        {
            if (b[2][2] == 'O')
            {
                if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][1] == 'O')
            {
                if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'X')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][4] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][2] == 'X')
        {
            if (b[3][4] == 'O')
            {
                if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[3][3] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][1] == 'X')
        {
            if (b[1][2] == 'X')
            {
                r = 1;
            }
            else if (b[4][4] == 'O')
            {
                if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                r = 1;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][2] == 'O')
        {
            r = 0;
        }
        else if (b[4][4] == 'O')
        {
            if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else if (b[2][4] == 'O')
        {
            r = 0;
        }
        else if (b[3][4] == 'X')
        {
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    else if (b[1][1] == 'O')
    {
        if (b[2][3] == 'O')
        {
            if (b[4][2] == 'X')
            {
                r = 1;
            }
            else if (b[2][1] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'O')
            {
                if (b[3][1] == 'O')
                {
                    r = 1;
                }
                else if (b[1][4] == 'O')
                {
                    r = 1;
                }
                else if (b[3][2] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][4] == 'X')
            {
                if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[3][1] == 'O')
        {
            if (b[4][2] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'O')
            {
                if (b[1][4] == 'O')
                {
                    r = 1;
                }
                else if (b[3][2] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][4] == 'X')
            {
                if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][4] == 'O')
            {
                r = 1;
            }
            else if (b[3][2] == 'O')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[3][2] == 'O')
        {
            if (b[1][4] == 'O')
            {
                if (b[4][2] == 'X')
                {
                    r = 1;
                }
                else if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][2] == 'X')
            {
                if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[1][2] == 'X')
                {
                    if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[3][4] == 'O')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'X')
            {
                if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'O')
            {
                r = 0;
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[1][2] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][4] == 'X')
        {
            if (b[3][4] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[1][2] == 'X')
                {
                    if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 1;
                }
                else if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][3] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[4][2] == 'O')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][4] == 'O')
            {
                r = 1;
            }
            else if (b[4][2] == 'O')
            {
                if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][3] == 'O')
            {
                r = 1;
            }
            else if (b[1][2] == 'X')
            {
                r = 0;
            }
            else if (b[4][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][2] == 'X')
        {
            if (b[2][2] == 'X')
            {
                r = 1;
            }
            else if (b[2][1] == 'X')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][2] == 'X')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'O')
            {
                r = 0;
            }
            else if (b[2][4] == 'X')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][2] == 'O')
        {
            if (b[2][1] == 'O')
            {
                if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][2] == 'O')
            {
                if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][4] == 'X')
            {
                r = 1;
            }
            else if (b[4][3] == 'O')
            {
                r = 0;
            }
            else if (b[2][4] == 'X')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][1] == 'X')
        {
            if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[1][2] == 'X')
        {
            if (b[4][4] == 'X')
            {
                r = 1;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[3][4] == 'X')
        {
            if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][4] == 'O')
        {
            r = 0;
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    else if (b[2][3] == 'X')
    {
        if (b[3][1] == 'X')
        {
            if (b[1][4] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][2] == 'X')
            {
                if (b[4][2] == 'O')
                {
                    r = 0;
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][2] == 'O')
            {
                if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'O')
                {
                    r = 0;
                }
                else if (b[1][2] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'X')
            {
                if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[2][1] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][4] == 'O')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[3][3] == 'O')
            {
                if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][2] == 'O')
            {
                r = 0;
            }
            else if (b[2][1] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[3][2] == 'O')
        {
            if (b[1][4] == 'O')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    if (b[4][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][4] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[4][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][2] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[4][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][2] == 'X')
            {
                if (b[2][2] == 'X')
                {
                    if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[2][1] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[2][1] == 'X')
                {
                    if (b[1][2] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][4] == 'X')
                    {
                        if (b[3][3] == 'O')
                        {
                            r = 1;
                        }
                        else if (b[3][4] == 'X')
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else if (b[4][3] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[3][4] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'X')
                {
                    if (b[2][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][2] == 'O')
            {
                if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'O')
                {
                    if (b[2][4] == 'O')
                    {
                        r = 0;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][4] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'O')
            {
                r = 0;
            }
            else if (b[4][4] == 'O')
            {
                if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[1][4] == 'X')
        {
            if (b[4][2] == 'O')
            {
                if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'X')
            {
                if (b[2][1] == 'O')
                {
                    r = 0;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][4] == 'O')
            {
                r = 1;
            }
            else if (b[4][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][2] == 'O')
        {
            if (b[2][2] == 'O')
            {
                if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else if (b[2][4] == 'X')
                {
                    if (b[3][3] == 'X')
                    {
                        r = 0;
                    }
                    else if (b[1][3] == 'X')
                    {
                        r = 0;
                    }
                    else
                    {
                        r = 1;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][1] == 'O')
            {
                if (b[1][2] == 'O')
                {
                    r = 0;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'X')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][4] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][2] == 'X')
        {
            if (b[3][4] == 'O')
            {
                if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[3][3] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][1] == 'X')
        {
            if (b[1][2] == 'X')
            {
                r = 1;
            }
            else if (b[4][4] == 'O')
            {
                if (b[2][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                r = 1;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][2] == 'O')
        {
            r = 0;
        }
        else if (b[4][4] == 'O')
        {
            if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else if (b[2][4] == 'O')
        {
            r = 0;
        }
        else if (b[3][4] == 'X')
        {
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    else if (b[3][1] == 'O')
    {
        if (b[3][2] == 'O')
        {
            r = 1;
        }
        else if (b[1][4] == 'O')
        {
            if (b[4][2] == 'X')
            {
                r = 1;
            }
            else if (b[1][2] == 'X')
            {
                r = 1;
            }
            else if (b[2][1] == 'X')
            {
                r = 1;
            }
            else if (b[2][2] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[4][2] == 'X')
        {
            if (b[3][4] == 'O')
            {
                r = 1;
            }
            else if (b[3][3] == 'O')
            {
                if (b[2][4] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'O')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][3] == 'X')
            {
                if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][4] == 'O')
            {
                r = 1;
            }
            else if (b[4][4] == 'X')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][2] == 'X')
        {
            if (b[2][1] == 'X')
            {
                r = 1;
            }
            else if (b[1][2] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[4][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][1] == 'O')
        {
            if (b[3][3] == 'X')
            {
                if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else if (b[3][4] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[1][2] == 'X')
        {
            if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[3][4] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][4] == 'O')
        {
            r = 0;
        }
        else if (b[4][3] == 'O')
        {
            r = 0;
        }
        else if (b[2][4] == 'X')
        {
            r = 1;
        }
        else if (b[1][3] == 'X')
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    else if (b[3][2] == 'O')
    {
        if (b[1][4] == 'O')
        {
            if (b[4][2] == 'X')
            {
                r = 1;
            }
            else if (b[2][2] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'O')
                {
                    r = 0;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][2] == 'X')
        {
            if (b[3][4] == 'O')
            {
                if (b[2][1] == 'X')
                {
                    r = 1;
                }
                else if (b[2][2] == 'X')
                {
                    r = 1;
                }
                else if (b[1][2] == 'X')
                {
                    if (b[4][4] == 'X')
                    {
                        r = 1;
                    }
                    else if (b[4][3] == 'X')
                    {
                        r = 1;
                    }
                    else
                    {
                        r = 0;
                    }
                }
                else if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][2] == 'X')
            {
                if (b[3][3] == 'O')
                {
                    r = 1;
                }
                else if (b[2][4] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[2][1] == 'X')
            {
                if (b[1][2] == 'X')
                {
                    r = 1;
                }
                else if (b[4][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[1][2] == 'O')
            {
                r = 0;
            }
            else if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'O')
            {
                r = 1;
            }
            else if (b[4][4] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][2] == 'O')
        {
            if (b[1][2] == 'O')
            {
                r = 0;
            }
            else if (b[2][1] == 'O')
            {
                r = 0;
            }
            else if (b[4][4] == 'X')
            {
                if (b[2][4] == 'X')
                {
                    r = 1;
                }
                else if (b[4][3] == 'X')
                {
                    r = 1;
                }
                else
                {
                    r = 0;
                }
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][1] == 'X')
        {
            if (b[1][2] == 'X')
            {
                r = 1;
            }
            else if (b[4][4] == 'X')
            {
                r = 1;
            }
            else if (b[4][3] == 'O')
            {
                r = 0;
            }
            else if (b[2][4] == 'X')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][2] == 'O')
        {
            if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][4] == 'O')
        {
            if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[3][4] == 'O')
        {
            r = 1;
        }
        else if (b[2][4] == 'X')
        {
            r = 1;
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    else if (b[1][4] == 'X')
    {
        if (b[3][4] == 'X')
        {
            r = 0;
        }
        else if (b[4][2] == 'O')
        {
            if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else if (b[4][4] == 'O')
            {
                r = 1;
            }
            else if (b[4][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][1] == 'X')
        {
            if (b[2][2] == 'X')
            {
                r = 1;
            }
            else if (b[1][2] == 'X')
            {
                if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[4][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[2][2] == 'O')
        {
            r = 0;
        }
        else if (b[1][2] == 'X')
        {
            if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][4] == 'O')
        {
            r = 0;
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    else if (b[4][2] == 'X')
    {
        if (b[2][2] == 'X')
        {
            if (b[3][4] == 'O')
            {
                r = 1;
            }
            else if (b[2][4] == 'X')
            {
                if (b[3][3] == 'X')
                {
                    r = 0;
                }
                else if (b[1][3] == 'X')
                {
                    r = 0;
                }
                else
                {
                    r = 1;
                }
            }
            else if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[2][1] == 'X')
        {
            if (b[1][2] == 'X')
            {
                r = 1;
            }
            else if (b[4][4] == 'X')
            {
                r = 1;
            }
            else if (b[4][3] == 'O')
            {
                r = 0;
            }
            else if (b[2][4] == 'X')
            {
                r = 1;
            }
            else if (b[1][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][2] == 'O')
        {
            if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][4] == 'O')
        {
            if (b[2][4] == 'O')
            {
                r = 0;
            }
            else if (b[4][3] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[3][4] == 'O')
        {
            r = 1;
        }
        else if (b[2][4] == 'X')
        {
            r = 1;
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    else if (b[2][2] == 'O')
    {
        if (b[3][4] == 'X')
        {
            if (b[2][4] == 'X')
            {
                r = 0;
            }
            else if (b[3][3] == 'X')
            {
                r = 0;
            }
            else if (b[1][3] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[3][3] == 'O')
        {
            if (b[1][2] == 'O')
            {
                r = 0;
            }
            else if (b[2][1] == 'X')
            {
                r = 1;
            }
            else
            {
                r = 0;
            }
        }
        else if (b[1][3] == 'X')
        {
            r = 0;
        }
        else if (b[2][4] == 'O')
        {
            r = 1;
        }
        else if (b[4][3] == 'X')
        {
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    else if (b[2][1] == 'X')
    {
        if (b[1][2] == 'X')
        {
            r = 1;
        }
        else if (b[4][4] == 'X')
        {
            if (b[3][3] == 'O')
            {
                r = 1;
            }
            else if (b[3][4] == 'X')
            {
                r = 0;
            }
            else
            {
                r = 1;
            }
        }
        else if (b[4][3] == 'O')
        {
            r = 0;
        }
        else if (b[2][4] == 'X')
        {
            r = 1;
        }
        else if (b[3][4] == 'X')
        {
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    else if (b[1][2] == 'O')
    {
        r = 0;
    }
    else if (b[4][4] == 'X')
    {
        if (b[2][4] == 'X')
        {
            r = 1;
        }
        else if (b[4][3] == 'X')
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    else if (b[3][4] == 'X')
    {
        r = 0;
    }
    else if (b[2][4] == 'O')
    {
        r = 0;
    }
    else if (b[4][3] == 'X')
    {
        r = 1;
    }
    else
    {
        r = 0;
    }
    if (r == 0)
    {
        cout << "KIPA WINS\n";
    }
    else
        cout << "HAVANA WINS\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        rmain();
    }
}
