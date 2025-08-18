//          189. Rotate Array
  //        https://youtu.be/Z7_nMTHROZo?feature=shared


//   my code 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the array

        // If k is bigger than size, rotate only k % n times
        k = k % n;

        // Create a new array to store the rotated result
        vector<int> rotatedArray(n);

        // Place each element at its new position
        for (int i = 0; i < n; i++) {
            int newPosition = (i + k) % n;  // Calculate the new index after rotation
            rotatedArray[newPosition] = nums[i];
        }

        // Copy rotatedArray back into nums
        for (int i = 0; i < n; i++) {
            nums[i] = rotatedArray[i];
        }
    }
};



// code by love babbar 
class Solution {
public:
    void rotate(vector<int>& nums, int k)
     {
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++)
          {
            temp[(i+k)%nums.size()]=nums[i];
          }
          nums=temp;
     }
};
