#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) p=malloc(s)
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
typedef int iType;
typedef struct{
	int key;
	iType item;
}element;
typedef struct node *treePointer;
typedef struct node{
	element data;
	treePointer leftChild, rightChild;
}tNode;

int count;

void insert(treePointer *node,int k, iType theItem);
treePointer modifiedSearch(treePointer tree, int k);
treePointer search(treePointer root, int key);
treePointer make();
void printBST(treePointer root);

int main (void){

	int key=0;
	treePointer root,sear;

	root = make();
	printf("the key to search : ");
	scanf("%d",&key);
	sear=search(root,key);
	if(sear==NULL)
		printf("there is no such element\n\n");
	else
		printf("the element's item is %d\n\n",sear->data.item);
	printf("inorder traversal of BST shows the sorted sequence\n");
	printBST(root);
	printf("\n");
	return 0;
}
void insert(treePointer *node,int k, iType theItem){

	treePointer ptr,temp=modifiedSearch(*node,k);
	if(temp||!(*node)){
		MALLOC(ptr,sizeof(*ptr));
		ptr->data.key=k;
		ptr->data.item=theItem;
		ptr->leftChild=ptr->rightChild=NULL;
		if(*node){
			if(k<temp->data.key){
				temp->leftChild=ptr;
			}
			else{
				temp->rightChild=ptr;
			}
		}
		else{
			*node=ptr;
		}
	}
}
treePointer modifiedSearch(treePointer tree, int k){

	while(tree){
		if(k==tree->data.key) return NULL;
		if(k<tree->data.key){
			if(tree->leftChild==NULL) return tree;
			tree=tree->leftChild;
		}
		else{
			if(tree->rightChild==NULL) return tree;
			tree=tree->rightChild;
		}
	}
	return NULL;

}
treePointer search(treePointer root, int key){

	if(!root) return NULL;
	if(key==root->data.key) return root;
	if(key<root->data.key)
		return search(root->leftChild,key);
	return search(root->rightChild,key);
}
treePointer make(){

	treePointer root=NULL;
	int seed=0,i=0,item=0;

	printf("random number generation <1~500>\nthe number of nodes in BST<less than and equal to 50> : ");
	scanf("%d",&count);
	printf("seed : ");
	scanf("%d",&seed);
	srand(seed);

	printf("\ncreating a BST from random numbers\n");
	for(i=0;i<count;i++){
		insert(&root,item=rand()%500+1,item);
	}

	return root;
}
void printBST(treePointer root){

	treePointer temp=root;

	if(temp){
		printBST(temp->leftChild);
		printf("%4d",temp->data.key);
		printBST(temp->rightChild);
	}
}