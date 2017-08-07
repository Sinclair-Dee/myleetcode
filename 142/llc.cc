//have done.great
//Run Code Status: compiled
#include <iostream>
using namespace std;
// Definition for singly-linked list.
 typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  } ListNode;
//solution by two pointers
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        //building two pointers-walker and runner
        ListNode* walker = head->next;
        ListNode* runner = head->next->next;
        //Traverse the linked list while walker doesn't meet runner
        while(walker != runner){
            //If runner come to null,return false. 
            if(runner == NULL ||runner->next == NULL)//note this!
                return NULL;
            walker = walker->next;
            runner = runner->next->next;//that's the reason why we shoule Judge runner and runner-next simultaneously
        }
        //if runner meet walker eventually. 
        walker = head->next;
        runner = runner->next;
        while(walker != runner){
            walker = walker->next;
            runner = runner->next;
        }
        return walker;//or runner
    }
    ListNode* buildlist(ListNode* head){
		int  in;
		cin>>in;
		if(in == -1)
			head = NULL;
		else{
		    //必须申请空间
			head = (ListNode*)malloc(sizeof(ListNode));
			head->val = in;
			head->next =  buildlist(head->next);
		}
	return head;
	}
	//建环，在第begin个点切入
	ListNode* addcycle(int flag,ListNode* head){
	    if(flag){
	        cout<<"where??"<<endl;
	        int begin;
	        cin>>begin;
	        ListNode* temp = head;
	        for(int i=1;i < begin;i++){
	            temp = temp->next;
	        }
            ListNode* temp2 = temp;
	        while(temp->next != NULL){
	            temp = temp->next;
	        }
	        temp->next = temp2;
	    }
	    return head;
	}
};
//test
int main(){
    Solution solution;
    ListNode* head(NULL);
    head = solution.buildlist(head);
    cout<<"if add cycle please input 1; else 0"<<endl;
    int flag;
    cin>>flag;
    head = solution.addcycle(flag,head);
    ListNode* listnode = solution.detectCycle(head);
    if(!listnode)
        cout<<"null!"<<endl;
    else
        cout<<listnode->val<<endl;
    return 0;
}