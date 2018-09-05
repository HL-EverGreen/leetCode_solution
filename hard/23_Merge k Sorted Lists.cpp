/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { //merge list
        //even works well when NULL exists in #lists# without evidently determine if there is NULL
        if(lists.empty()) return nullptr;
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) { //recursive
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        //where is the bug??
        /*
        int l_size=lists.size(),i=1;
        if(l_size==0) return nullptr;
        else if(l_size==1) return lists[0];
        ListNode* dummy=new ListNode(0);
        dummy->next=lists[0];
        while(!dummy->next){
            dummy->next=lists[i];
            i++;
            if(i==l_size && !dummy->next) return nullptr;
            else if(i==l_size) return dummy->next;
        }
        ListNode* l1,*l2,*prev;
        for(;i<l_size;i++){
            l1=dummy->next;
            l2=lists[i];
            while(!l2){
                i++;
                if(i==l_size) return dummy->next;
                l2=lists[i];
            }
            prev=dummy;
            while(l1 || l2){
                if(!l1 || (l2&&l2->val<=l1->val)){
                    prev->next=l2;
                    l2=l2->next;
                }
                else if(!l2 || l1&&l1->val<=l2->val){
                    prev->next=l1;
                    l1=l1->next;
                }
            }
        }
        return dummy->next;
        */
    }
};