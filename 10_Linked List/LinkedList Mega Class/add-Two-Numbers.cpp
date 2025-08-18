// leetcode 2: Add Two Numbers

     // my code 
     //iterative method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //sabse pahle anseer store karne ke liye node banate hai
        ListNode* ans=new ListNode(-1);
        //iterate karne ke liye aik naya node bana lete hai 
        // or answer delte karne pe loss na ho jaye ish liye
        ListNode* it =ans;
        int carry=0;
        //agar l1 , l2 ,carry kuch bhi jab tak hai tab nak loop chlale ga
        while(l1 || l2 || carry)
         {
          int a=l1 ? l1->val :0;
          int b=l2 ? l2->val :0;
          int sum =a+b+carry;
          int digit=sum%10;
          carry=sum/10;
          //new node create kar kar rakhna hoga
          it->next= new ListNode(digit);
          //ans ko agle node pe badha dege taki next time yah rakh asake
          it=it->next;
         
          l1=l1?l1->next:nullptr;
          l2=l2?l2->next:nullptr;

         }
         ListNode* ansnode=ans->next;
         delete ans;
         return ansnode;
    }
};

  //              recursive method 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
  void functionto(ListNode* &l1,ListNode* &l2,int &carry,ListNode* &ans)
   {
    //base case
    if(l1 ==NULL && l2==NULL && carry==0){ return ; }
    //aik mai karuga
    int a=l1 ?l1->val:0;
    int b=l2?l2->val:0;
    int sum=a+b+carry;
    int digit=sum % 10;
    carry=sum/10;
    ans->next=new ListNode(digit);
    l1=l1?l1->next:nullptr;
    l2=l2?l2->next:nullptr;
    functionto(l1,l2,carry,ans->next) ;
   }
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode* ans=new ListNode(-1);
     functionto(l1,l2,carry,ans);
    ListNode* output= ans->next;
     delete ans;  
     return output; 
    }
};

         //  code by lakchya 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // iterative approach
    ListNode*iterative(ListNode*l1, ListNode*l2){
        ListNode* ans = new ListNode(-1);
        ListNode*it = ans ;
        int carry = 0;
        while(l1 || l2 || carry){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a+b+carry;
            int digit = sum%10;
            carry = sum/10;
            it->next = new ListNode(digit);
            it = it->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode*finalAns = ans->next;
        delete ans;
        return finalAns;
    }

    //recursive approach
    ListNode*recursive(ListNode*l1, ListNode*l2, int carry = 0){
        if(!l1 && !l2 && !carry) return 0;
        //1case
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a+b+carry;
        int digit = sum%10;
        carry = sum/10;
        //build the ans LL
        ListNode*ans = new ListNode(digit);
        ans->next = recursive(l1? l1->next:l1, l2? l2->next:0, carry);
        return ans;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return iterative(l1,l2);
        return recursive(l1,l2);
    }
};
