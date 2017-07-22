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