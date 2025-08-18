
//my solution  Factorial
// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
       vector<int>ans;
       ans.push_back(1);
       for(int i=2;i<=n;i++)
    {
                int carry=0;
         
           for(int j=0;j<ans.size();j++)
             {
               int fact=i*ans[j]+carry;
               ans[j]=fact%10;
               carry=fact/10;
             }
            //handle carrry
            while(carry)
              {
                 int carrydigit=carry%10;
                 ans.push_back(carrydigit);
                carry=carry/10; 
              }
         }

         reverse(ans.begin(),ans.end());
         return ans;
    }
};

//my solution adding two numbers 
  class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        // Complete the function
       int i=arr1.size()-1;
       int j=arr2.size()-1;
       int carry=0;
       string ans;
       while(i>=0 && j>=0)
          {
            int sum=arr1[i]+arr2[j]+carry;
            int digit=sum%10;
            ans.push_back(digit+'0');
            carry=sum/10;
            i--;
            j--;
          }
        while(j>=0)
          {
            int sum=0+arr2[j]+carry;
            int digit=sum%10;
            ans.push_back(digit+'0');
            carry=sum/10;
            j--;
          }
        while(i>=0)
          {
            int sum=arr1[i]+0+carry;
            int digit=sum%10;
            ans.push_back(digit+'0');
            carry=sum/10;
            i--;
          }
        if(carry)
           {
              ans.push_back(carry+'0');
           }
        while(ans[ans.size()-1]=='0')
          {
            ans.pop_back();
          }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};







// add two number represented by an array
class Solution{
    public:
        string calc_Sum(int *a, int n, int *b, int m){
            int carry=0;
            string ans;
            int i=n-1;
            int j=m-1;

            while(i>=0 && j>=0){
                int x=a[i]+b[j]+carry;
                int digit=x%10;
                ans.push_back(digit+'0');
                carry=x/10;
                i--,j--;
            }
            while(i>=0){
                int x=a[i]+0+carry;
                int digit=x%10;
                ans.push_back(digit+'0');
                carry=x/10;
                i--;
            }
            while(j>=0){
                int x=0+b[j]+carry;
                int digit=x%10;
                ans.push_back(digit+'0');
                carry=x/10;
                j--;
            }
            if(carry){
                ans.push_back(carry+'0');
            }
            while(ans[ans.size()-1]=='0'){
                ans.pop_back();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};

// factorial of large number
class Solution{
public:
    vector<int> factorial(int N){
        vector<int>ans;
        ans.push_back(1);
        int carry=0;
        for(int i=2;i<=N;i++){
            for(int j=0;j<ans.size();j++){
                int x=ans[j]*i + carry;
                ans[j]=x%10;
                carry=x/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        // for(int e:ans){
        //     cout<<e<<" ";
        // }
        // cout<<endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
