/*************************************************************************
	> File Name: buildTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 May 2019 06:04:56 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool buildNode(TreeNode* node,vector<int>& preorder,int pre_left_pos,int pre_right_pos, vector<int>& inorder,int in_left_pos,int in_right_pos)
{
    if(node == NULL)
    {
        return false;
    }
        
    int in_root_pos = -1;
    for(int pos = in_left_pos;pos<in_right_pos;++pos)
    {
        if(inorder[pos] == preorder[pre_left_pos])
        {
            in_root_pos = pos;
            node->val = inorder[pos];
            break;
        }
    }

    if(in_root_pos == -1) return false;
    if(in_root_pos==in_left_pos && in_root_pos==in_right_pos) return true;
        
    if(in_root_pos-in_left_pos>0)
    {
        node->left = new TreeNode(0);
        buildNode(node->left,preorder,pre_left_pos+1,pre_left_pos+in_root_pos-in_left_pos,inorder,in_left_pos,in_root_pos-1);
    }
        
    if(in_root_pos-in_right_pos < 0)
    {
        node->right= new TreeNode(0);
        buildNode(node->right,preorder,pre_left_pos+in_root_pos-in_left_pos+1,pre_right_pos,inorder,in_root_pos+1,in_right_pos);
    }
    return true;

}
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode * root = new TreeNode(0);
    cout<<buildNode(root,preorder,0,preorder.size()-1,inorder,0,inorder.size()-1)<<endl;
    return root;
}

int main(int argc,char** argv)
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder =  {9,3,15,20,7};
    buildTree(preorder,inorder);
}
