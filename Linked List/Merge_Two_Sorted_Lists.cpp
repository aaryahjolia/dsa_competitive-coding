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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode *var;
        if(list2->val>list1->val) 
        {
            var=list1;
            list1=list1->next;
        }
        else
        {
            var=list2;
            list2=list2->next;
        }
        ListNode *ans=var; 
        while(list1!=NULL&&list2!=NULL)
        {
            if(list2->val>list1->val)
            {
                ans->next=list1;
                list1=list1->next;
                ans=ans->next;
            }
            else
            {
                ans->next=list2;
                list2=list2->next;
                ans=ans->next;
            }
        }
        while(list1!=NULL)
        {
            ans->next=list1;
            list1=list1->next;
            ans=ans->next;
        }
        while(list2!=NULL)
        {
            ans->next=list2;
            list2=list2->next;
            ans=ans->next;
        }
        return var;
    }
};
