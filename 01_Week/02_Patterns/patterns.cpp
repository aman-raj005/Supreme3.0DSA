#include <iostream>
using namespace std;

void squarePattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void rectanglePattern(int l, int b)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void hollowRectangle(int l, int b)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 || i == (l - 1) || j == 0 || j == (b - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void hollowSquare(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void hollowDiamond(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1 || i == j)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void halfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void invertedHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void hollowHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == n - 1 || j == 0 || i == j)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void invertedHollowHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            if (i == 0 || j == n || i == j - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void numericHalfPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void invertedNumericHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;

    // int l, b;
    // cin >> l >> b;

    
    // squarePattern(n);
    // rectanglePattern(l, b);
    // hollowRectangle(l, b);
    // hollowSquare(n);
    // hollowDiamond(n);
    // halfPyramid(n);
    // invertedHalfPyramid(n);
    // hollowHalfPyramid(n);
    // invertedHollowHalfPyramid(n);
    // numericHalfPyramid(n);
    // invertedNumericHalfPyramid(n);

    return 0;
}