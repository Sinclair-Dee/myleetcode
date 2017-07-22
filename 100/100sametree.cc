// Definition for a binary tree node.
//Run Code Status: compiled.
// Definition for a binary tree node.
#include <iostream>
#include<stdlib.h>
using namespace std;
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