// leetcode 853: Car Fleet

853. Car Fleet
Solved
Medium
Topics
premium lock icon
Companies
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:

There is only one car, hence there is only one fleet.
Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]

Output: 1

Explanation:

The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
 

Constraints:

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106

//  my code 

class Solution {
public:
    // Define a class to represent each car with its position and speed
    class Car {
    public:
        int speed;
        int pos;

        // Constructor to initialize position and speed
        Car(int p, int s) : pos(p), speed(s) {};
    };

    // Custom comparator function to sort cars based on their starting position (in increasing order)
    static bool mycompare(Car &a, Car &b) {
        return a.pos < b.pos;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Step 1: Create a list of Car objects
        vector<Car> store;
        for (int i = 0; i < position.size(); i++) {
            Car cars(position[i], speed[i]);  // Create car with position and speed
            store.push_back(cars);            // Add to the list
        }

        // Step 2: Sort cars by their starting position (from farthest from target to closest)
        sort(store.begin(), store.end(), mycompare);

        // Step 3: Use a stack to count how many fleets reach the target
        stack<float> st;

        // Step 4: Traverse cars in reverse order (from the one closest to the target to the farthest)
        // This ensures that we process the car that would arrive first (if alone) first.
        for (int i = store.size() - 1; i >= 0; i--) {
            // Calculate time taken by this car to reach the target
            float time = (target - store[i].pos) / float(store[i].speed);

            // If this car catches up to the car ahead (or slower), they become one fleet
            // So we pop the earlier fleet time (it gets merged)
            while (!st.empty() && st.top() <= time) {
                st.pop();
            }

            // Push the current car's time as a new fleet (if not merged)
            st.push(time);
        }

        // Step 5: Number of fleets is equal to number of times in the stack
        return st.size();
    }
};




 //   code by lakchya 
class Solution {
    class Car{
    public:
        int pos, speed;
        Car(int p, int s): pos(p), speed(s){};
    };
    static bool myComp(Car&a, Car&b){
        return a.pos < b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i = 0; i<position.size();i++){
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),myComp);

        stack<float>st;
        for(auto car:cars){
            float time = (target - car.pos) / ((float)car.speed);
            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
