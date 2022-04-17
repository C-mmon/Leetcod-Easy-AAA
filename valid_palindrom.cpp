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
    bool isPalindrome(ListNode* head) 
    {
        

        if(head==NULL||head->next==NULL)
        {
            return true;
        }
        
        //counting the number of nodes
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        cout<<count<<endl;
        
        if(count==2 && head->next->val!=head->val)
        {
            return false;
        }
        //implemeting the slow and the fast pointer approach
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && slow!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //flag to see if the linked list is odd or even
        bool flag=false; //meaning even
        
        if(count %2!=0)
        {
            flag=true;
        }
        
        
        //dividing the count by 2
        count=count/2;
        

        //after counting reverse n/2 nodes
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(count>0)
        {
            count--;
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
        if(flag)
        {
            slow=slow->next;
        }
        
    
        while(slow!=NULL || head!=NULL)
        {
            if(slow->val!=head->val)
            {
                return false;
            }
            slow=slow->next;
            head=head->next;

        }
        return true;
        
        
                 
    }
}; 