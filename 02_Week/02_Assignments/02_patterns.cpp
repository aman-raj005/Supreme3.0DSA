#include <iostream>
using namespace std;

void numericHollowHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || i == j)
            {
                cout << j + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void numericHollowInvertedHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || i == n - j - 1)
            {
                cout << j + i + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void numericPalindromeEquilateralPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }
}

void solidHalfDiamond(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

void fancyPattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8 - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (j & 1)
            {
                cout << "*";
            }
            else
            {
                cout << i + 1;
            }
        }
        for (int j = 0; j < 8 - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{

    int n;
    cout << "Enter value of n : ";
    cin >> n;
    // numericHollowHalfPyramid(n);
    // numericHollowInvertedHalfPyramid(n);
    // numericPalindromeEquilateralPyramid(n);
    // solidHalfDiamond(n);
    fancyPattern1(n);

    return 0;
}