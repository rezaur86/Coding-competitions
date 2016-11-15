/*
 * AVL_tree.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: mohammra
 */

#include "common.h"


/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

void fix_height(node** n){
    int n_left = (*n)->left ? (*n)->left->ht : -1;
    int n_right = (*n)->right ? (*n)->right->ht : -1;
    (*n)->ht = max(n_left, n_right) + 1;
}

void balance_left(node** real_root) {
    node *root = *real_root;
    int l_ht = root->left->left ? root->left->left->ht : -1;
    int r_ht = root->left->right ? root->left->right->ht : -1;
    node* t;
    if (l_ht < r_ht) {
        // left right case
        t = root->left->right;
        node* t_left = t->left;
        node* t_right = t->right;
        t->left = root->left;
        t->right = root;
        t->left->right = t_left;
        t->right->left = t_right;
    }
    if (l_ht > r_ht) {
        // left left case
        t = root->left;
        node* t_right = t->right;
        t->right = root;
        t->right->left = t_right;
    }
    fix_height(&t->left);
    fix_height(&t->right);
    *real_root = t;
}

void balance_right(node** real_root) {
    node *root = *real_root;
    int l_ht = root->right->left ? root->right->left->ht : -1;
    int r_ht = root->right->right ? root->right->right->ht : -1;
    node* t;
    if (l_ht > r_ht) {
        // right left case
        t = root->right->left;
        node* t_left = t->left;
        node* t_right = t->right;
        t->left = root;
        t->right = root->right;
        t->left->right = t_left;
        t->right->left = t_right;
    }
    if (l_ht < r_ht) {
        // right right case
        t = root->right;
        node* t_left = t->left;
        t->left = root;
        t->left->right = t_left;
    }
    fix_height(&t->left);
    fix_height(&t->right);
    *real_root = t;
}

node * insert(node * root,int val)
{
    if (root == NULL) {
        node* ins = new node();
        ins->val = val;
        ins->left = NULL;
        ins->right = NULL;
        ins->ht = 0;
        return ins;
    }
    if (val <= root->val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    int left_ht = root->left ? root->left->ht : -1;
    int right_ht = root->right ? root->right->ht : -1;
    int b = left_ht - right_ht;
    if (b > 1) {
        balance_left(&root);
    }
    if (b < -1) {
        balance_right(&root);
    }
    fix_height(&root);
    return root;
}
