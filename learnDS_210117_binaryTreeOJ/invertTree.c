#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
* ·­×ªÒ»¿Ã¶þ²æÊ÷¡£
*/
struct treenode {
    int val;
    struct treenode *left;
    struct treenode *right;
};
 
 struct treenode* inverttree(struct treenode* root) {
     if (root) {
         struct treenode* node = root->left;
         root->left = root->right;
         root->right = node;
         inverttree(root->left);
         inverttree(root->right);
     }
     return root;
 }
 
