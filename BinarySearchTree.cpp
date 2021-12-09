#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct treeNode
{
	int val;
	treeNode*left;
	treeNode*right;
};



treeNode* createNode(int x)
{
	treeNode*temp=new treeNode;  // treeNode*temp=treeNode* mallc(sizeof(struct treeNode))->>>>>this is dynamic memory allocation in c
	temp->val=x;
	temp->right=temp->left=NULL;
	return temp;
}


treeNode* insert(treeNode* root,int x)
{
	if(root==NULL)
	{
		root=createNode(x);
		return root;
	}
	treeNode*temp=root;
	treeNode*p;
	while(temp!=NULL)
	{
		p=temp;
		if(temp->val==x)
			return temp;
		else if(temp->val < x)
			temp=temp->right;
		else
			temp=temp->left;
	}

	if(p->val < x)
		p->right=createNode(x);
	else
		p->left=createNode(x);
return root;
}


void inorder(treeNode*root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<" "<<root->val;
	inorder(root->right);
}

// void leaf_node(treeNode *root)
// {
// 	if(root==NULL)
// 		return;
// 	if(root->left==NULL && root->right==NULL)
// 		count++;
// 	leaf_node(root->left);
// 	leaf_node(root->right);
// }
void level_order(treeNode*root)
{
	queue < treeNode*> q;
	                  
	q.push(root);
	while(!q.empty())
	{
		treeNode* temp=q.front();
		cout<<" "<<temp->val;
	    q.pop();
		if(temp->left)
		{
			q.push(temp->left);

		}
		if(temp->right)
		{
			q.push(temp->right);
		}

	}

}
int height_tree(treeNode*root)
{
	if(root==NULL)
		return 0;
	int x=height_tree(root->left)+1;
	int y=height_tree(root->right)+1;

	return max(x,y);

}
int main()
{
	treeNode*root=NULL;
	// root=insert(root,50);root=insert(root,25);root=insert(root,90);root=insert(root,15);root=insert(root,30);root=insert(root,60);root=insert(root,121);
	root=insert(root,50);root=insert(root,49);root=insert(root,48);root=insert(root,9);root=insert(root,8);root=insert(root,7);root=insert(root,6);
	inorder(root);
    cout<<endl;
	level_order(root);
	cout<<endl<< height_tree(root);


	return 0;
}