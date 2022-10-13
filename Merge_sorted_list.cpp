class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val > list2->val)std::swap(list1,list2);
        ListNode *res=list1;
        while(list1!=NULL && list2!=NULL){
            ListNode *temp=NULL;
            while(list1!=NULL && list1->val <= list2->val){
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            std::swap(list1,list2);
        }
       return res;
    }
    
};
