#include <iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node * right;
};
struct node* addNode(int key){
	node* temp = new node;
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int maxDepth(node* node)
{
	if(node == NULL)
		return 0;
	else{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		if(lDepth>rDepth)
			return (lDepth+1);
		else
			return (rDepth+1);
	}
}
int main(){
	struct node* root = addNode(1);
	root->left = addNode(3);
	root->right = addNode(2);
	root->left->left  = addNode(4);
	root->left->right = addNode(5);

	 printf("Hight of tree is %d", maxDepth(root));
   
    getchar();
    return 0;


}