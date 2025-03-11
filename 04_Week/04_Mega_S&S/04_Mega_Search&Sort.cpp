// // Sqrt With Precision without using % / sqrt(), pow():
// METHOD 1
// #include <iostream>
// using namespace std;

// int getSqrt(int n)
// {
//     int s = 0;
//     int e = n;
//     int ans = -1;
//     while (s <= e)
//     {
//         long long int mid = (s + e) >> 1;
//         if (mid * mid <= n)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//     }
//     return ans;
// }

// double getPrecisionSqrt(double sqrt, int n)
// {
//     int precision = 13;
//     double step = 0.1;
//     while (precision--)
//     {
//         double i = sqrt;
//         while (i * i <= n)
//         {
//             sqrt = i;
//             i += step;
//         }
//         step /= 10;
//     }
//     return sqrt;
// }

// int main()
// {

//     int target = 81;
//     int sqrt = getSqrt(target);
//     double precisionSqrt = getPrecisionSqrt(sqrt, target);
//     // cout << "Precision Sqrt is " << precisionSqrt;
//     printf("Precision Sqrt : %.13f\n", precisionSqrt);

//     return 0;
// }

// METHOD 2
// #include <iostream>
// using namespace std;

// int getSqrt(int n)
// {
//     int s = 0;
//     int e = n;
//     int ans = -1;
//     while (s <= e)
//     {
//         long long int mid = (s + e) >> 1;
//         if (mid * mid <= n)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//     }
//     return ans;
// }

// double BSPrecision(int n)
// {
//     double s = 0;
//     double e = n;
//     double ans = 0;
//     while ((e - s) > 0.000000001)
//     {
//         double mid = (s + e) / 2;
//         double sqr = mid * mid;
//         if (sqr <= n)
//         {
//             ans = mid;
//             s = mid + 0.000000000000000000000000001;
//         }
//         else
//         {
//             e = mid - 0.000000000000000000000000001;
//             ;
//         }
//     }
//     return ans;
// }

// int main()
// {

//     int num = 64;
//     double ans = BSPrecision(num);
//     printf("Precision Sqrt : %.9f\n", ans);

//     return 0;
// }


