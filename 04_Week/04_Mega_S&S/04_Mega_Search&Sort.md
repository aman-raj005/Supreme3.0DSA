# Mega Class on Searching and Sorting

## Q. Sqrt With Precision without using % / sqrt(), pow():
### Method 1:
### Code:
```cpp
#include <iostream>
using namespace std;

int getSqrt(int n)
{
    int s = 0;
    int e = n;
    int ans = -1;
    while (s <= e)
    {
        long long int mid = (s + e) >> 1;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

double getPrecisionSqrt(double sqrt, int n)
{
    int precision = 13;
    double step = 0.1;
    while (precision--)
    {
        double i = sqrt;
        while (i * i <= n)
        {
            sqrt = i;
            i += step;
        }
        step /= 10;
    }
    return sqrt;
}

int main()
{
    int target = 63;
    int sqrt = getSqrt(target);
    double precisionSqrt = getPrecisionSqrt(sqrt, target);
    // cout << "Precision Sqrt is " << precisionSqrt;
    printf("Precision Sqrt : %.13f\n", precisionSqrt);

    return 0;
}
```
### Method 2:
### Code:
```cpp
#include <iostream>
using namespace std;

int getSqrt(int n)
{
    int s = 0;
    int e = n;
    int ans = -1;
    while (s <= e)
    {
        long long int mid = (s + e) >> 1;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

double BSPrecision(int n)
{
    double s = 0;
    double e = n;
    double ans = 0;
    while ((e - s) > 0.000000001)
    {
        double mid = (s + e) / 2;
        double sqr = mid * mid;
        if (sqr <= n)
        {
            ans = mid;
            s = mid + 0.000000000000000000000000001;
        }
        else
        {
            e = mid - 0.000000000000000000000000001;
            ;
        }
    }
    return ans;
}

int main()
{

    int num = 64;
    double ans = BSPrecision(num);
    printf("Precision Sqrt : %.9f\n", ans);

    return 0;
}
```
## Q. 29. Divide Two Integers 

### LeetCode Solution:
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor == -1) return INT_MAX;

        bool ansPosiSign = true;
        if(dividend <0 && divisor>0 || dividend>0 && divisor<0){
            ansPosiSign = false;
        }

        long long int divid = abs(dividend);
        long long int divis = abs(divisor);

        long long int s=0, e = divid;
        long long ans = 0;

        while(s<=e){
            long long mid = s+((e-s)>>1);
            if(mid*divis<=divid)
            {
                ans =mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(ansPosiSign==false)
            return -ans;   
        return ans;
    }
};class Solution {
public:
    int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor == -1) return INT_MAX;

        bool ansPosiSign = true;
        if(dividend <0 && divisor>0 || dividend>0 && divisor<0){
            ansPosiSign = false;
        }

        long long int divid = abs(dividend);
        long long int divis = abs(divisor);

        long long int s=0, e = divid;
        long long ans = 0;

        while(s<=e){
            long long mid = s+((e-s)>>1);
            if(mid*divis<=divid)
            {
                ans =mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(ansPosiSign==false)
            return -ans;   
        return ans;
    }
};
```
## Q 875. Koko Eating Bananas

### LeetCode Solution:

```cpp
class Solution
{
public:
    bool canKokoFinishBananasWithKSpeed(vector<int> &piles, int h, int k)
    {
        long long int totalHoursTakenByKokoToFinishAllBananas = 0;
        for (int i = 0; i < piles.size(); i++)
            totalHoursTakenByKokoToFinishAllBananas += ceil(piles[i] / (double)k);

        return totalHoursTakenByKokoToFinishAllBananas <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = 0;

        // TC: O(Log(Max(Piles)) * O(n)) -> O(n*log(max(piles)))
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            int k = mid;
            if (canKokoFinishBananasWithKSpeed(piles, h, k))
            {
                ans = k;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
```

## Q 1482. Minimum Number of Days to Make m Bouquets:

### LeetCode Solution:

```cpp
class Solution {
public:
    bool canWeMakeBouquetsWithDDays(vector<int>& bloomDay, int m, int k,int D){
        int counter = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= D)
            {
                counter++;
            }
            if (counter == k)
            {
                m--;
                counter = 0;
                if (m == 0)
                    break;
            }
            if (bloomDay[i] > D)
                counter = 0;
        }
        return m == 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int requirement = (long long int)m*(long long int)k;
        if(bloomDay.size() < requirement) return -1;
        int s = *min_element(bloomDay.begin(), bloomDay.end()); 
        int e = *max_element(bloomDay.begin(), bloomDay.end()); 
        int ans=0;
        while(s<=e){
            int mid = s+((e-s)>>1);
            int day = mid;
            if(canWeMakeBouquetsWithDDays(bloomDay, m, k, day)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
```

## Q 162. Find Peak Element:

### LeetCode Solution:

```cpp
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int start = 1, end = n - 2;
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
```
