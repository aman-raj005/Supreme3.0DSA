29. Divide Two Integers
Solved
Medium
Topics
Companies
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [-231, 231 - 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0


//class Solution {
//public:
//    // helper function to multiply two numbers without using '*'
//    long long multiply(long long a, long long b) {
//        long long res = 0;
//        while (b > 0) {
//            if (b & 1) res += a;
//            a += a;
//            b >>= 1;
//        }
//        return res;
//    }
//
//    int divide(int dividend, int divisor) {
//
//        if (dividend == INT_MIN && divisor == -1) {
//            return INT_MAX;  // to avoid overflow
//        }
//
//        long long divd = abs((long long)dividend);
//        long long divs = abs((long long)divisor);
//
//        long long s = 0, e = divd, ans = 0;
//
//        while (s <= e) {
//            long long mid = s + ((e - s) >> 1);
//
//            // ? replace multiplication with custom multiply function
//            if (multiply(mid, divs) <= divd) {
//                ans = mid;
//                s = mid + 1;
//            } else {
//                e = mid - 1;
//            }
//        }
//
//        // set the sign of answer
//        if ((dividend < 0) ^ (divisor < 0)) {
//            ans = -ans;
//        }
//
//        return ans;
//    }
//};














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


