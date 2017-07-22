## 以下代码是最初的版本没有产生正确结果

```
#include <iostream>
#include<stdlib.h>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)
            return true;
        else if(!p&&q)
            return false;
        else if(p&&!q)
            return false;
        else if(p->val != q->val)
            return false;
        else
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
	void buildtree(TreeNode* tree){
	int  in;
	cin>>in;
	if(in == -1)
		tree = 0;
	else{
		tree = (TreeNode*)malloc(sizeof(TreeNode));
		tree->val = in;
		/*tree->left =   */buildtree(tree->left);
	/*	tree->right = */buildtree(tree->right);
	}
//return tree;
}
};

int main(){
	TreeNode* pt(NULL);
	TreeNode* qt(NULL);
    Solution solution;
    /*pt =*/ solution.buildtree(pt);
   /* qt =*/ solution.buildtree(qt);
	bool issame = solution.isSameTree(pt,qt);
    if(issame)
        cout<<"yes!"<<endl;
    if(!issame)
        cout<<"no!"<<endl;
    return 0;
}
```
错误出现在了第49行和第50行，后来加上了注释的内容才通过的。

## 更简短的写法

```
//
// Algorithm for the recursion:
// 1)
// If one of the node is NULL then return the equality result of p an q.
// This boils down to if both are NULL then return true, 
// but if one of them is NULL but not the other one then return false
// 2)
// At this point both root nodes represent valid pointers.
// Return true if the root nodes have same value and 
// the left tree of the roots are same (recursion)
// and the right tree of the roots are same (recursion). 
// Otherwise return false. 
//

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
```

## 用队列的方法进行层序遍历

```
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
```