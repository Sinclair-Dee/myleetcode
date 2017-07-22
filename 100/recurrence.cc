//Run Code Status: compiled.
#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
// Definition for a binary tree node.
typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } TreeNode;
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!isSameNode(p, q))//两个父结点就不相等，就不用再往下遍历了。
            return false;
        if(!p && !q)//都为空，也算作是相等。
            return true;
        
        queue<TreeNode*> lqueue;
        queue<TreeNode*> rqueue;
        lqueue.push(p);
        rqueue.push(q);
        while(!lqueue.empty() && !rqueue.empty())
        {
            TreeNode* lfront = lqueue.front();
            TreeNode* rfront = rqueue.front();

            lqueue.pop();
            rqueue.pop();
            
            if(!isSameNode(lfront->left, rfront->left))
                return false;
            if(lfront->left && rfront->left)
            {
                lqueue.push(lfront->left);
                rqueue.push(rfront->left);
            }
            
            if(!isSameNode(lfront->right, rfront->right))
                return false;
            if(lfront->right && rfront->right)
            {
                lqueue.push(lfront->right);
                rqueue.push(rfront->right);
            }
        }
        return true;
    }
    bool isSameNode(TreeNode* p, TreeNode *q){//判断俩结点是否相等
        if(!p && !q)
            return true;
        if((p && !q) || (!p && q) || (p->val != q->val))
            return false;
        return true;
    }
    TreeNode* buildtree(TreeNode* tree){
		int  in;
		cin>>in;
		if(in == -1)
			tree = 0;
		else{
		    //必须申请空间
			tree = (TreeNode*)malloc(sizeof(TreeNode));
			tree->val = in;
			tree->left =  buildtree(tree->left);
			tree->right = buildtree(tree->right);
		}
	return tree;
	}
};
int main(){
    Solution solution;
    TreeNode* pt(NULL);
	TreeNode* qt(NULL);
    //
    pt = solution.buildtree(pt);
    qt = solution.buildtree(qt);
	bool issame = solution.isSameTree(pt,qt);
    if(issame)
        cout<<"yes!"<<endl;
    if(!issame)
        cout<<"no!"<<endl;
    return 0;
}