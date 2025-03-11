#include <iostream>
using namespace std;

void fullPyramid(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*   ";
        }

        cout << endl;
    }
}

void invertedFullPyramid(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*   ";
        }

        cout << endl;
    }
}

void diamond(int n)
{
    fullPyramid(n);
    invertedFullPyramid(n);
}

void hollowPyramid(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || i == j)
            {
                cout << "*   ";
            }
            else
            {
                cout << "    ";
            }
        }

        cout << endl;
    }
}

void invertedHollowFullPyramid(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - i - 1)
            {
                cout << "*   ";
            }
            else
            {
                cout << "    ";
            }
        }

        cout << endl;
    }
}

void hollowDiamond(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0 || j == 0 || i == j)
            {
                cout << "*   ";
            }
            else
            {
                cout << "    ";
            }
        }

        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++)
        {
            if (i == n - 1 || j == 0 || j == n - i - 1)
            {
                cout << "*   ";
            }
            else
            {
                cout << "    ";
            }
        }

        cout << endl;
    }
}

void mixPyramid(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void fancy12Pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j & 1)
            {
                cout << "* ";
            }
            else
            {
                cout << i + 1 << " ";
            }
        }

        cout << endl;
    }
}

void fullFancy12Pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j & 1)
            {
                cout << "* ";
            }
            else
            {
                cout << i + 1 << " ";
            }
        }

        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < 2 * i - 1; j++)
        {
            if (j & 1)
            {
                cout << "* ";
            }
            else
            {
                cout << i << " ";
            }
        }

        cout << endl;
    }
}

void ABCBA(int n)
{
    for (int i = 0; i < n; i++)
    {
        char A = 'A';
        for (int j = 0; j < i + 1; j++)
        {
            cout << A++ << " ";
        }
        A--;
        for (int j = 0; j < i; j++)
        {
            cout << --A << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << endl;
    cout << "Your Pattern is : " << endl;
    // fullPyramid(n);
    // invertedFullPyramid(n);
    // diamond(n);
    // hollowPyramid(n);
    // invertedHollowFullPyramid(n);
    // hollowDiamond(n);
    // mixPyramid(n);
//     fancy12Pattern(n);
     fullFancy12Pattern(n);
//    ABCBA(n);

    return 0;
}
