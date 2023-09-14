/** @addtogroup [C] [C: C Programming Exercise]
* [C Programming Exerceise]
* @{
*/

/*
 * Copyright (C) 2023 Creative Technology Ltd.
 * All Rights Reserved.
 *
 * This software and its associated documentation may contain some
 * proprietary, confidential and trade secret information of
 * Creative Technology Ltd. and except as provided by written agreement with
 * Creative Technology Ltd.
 *
 * a)   no part may be disclosed, distributed, reproduced, transmitted,
 *      transcribed, stored in a retrieval system, adapted or translated
 *      in any form or by any means electronic, mechanical, magnetic,
 *      optical, chemical, manual or otherwise,
 *
 *      and
 *
 * b)   the recipient is not entitled to discover through reverse
 *      engineering or reverse compiling or other such techniques or
 *      processes the trade secrets contained therein or in the
 *      documentation.
 */

#include <stdio.h>    //printf()
#include <stdlib.h>   //free() malloc()

#include "bst.h"

/**
* Helper Function to Insert a new Node.
* @param key  key of the Node need to be Inserted
* @return returns the newnode Inserted
*/
struct Node* NewNode(int key) {
   struct Node* pNodeNew = (struct Node*)malloc(sizeof(struct Node));  // Memory allocation
   pNodeNew->data = key;   // Initialize
   pNodeNew->left = NULL;  // Initialize
   pNodeNew->right = NULL; // Initialize

   return pNodeNew;
}

/**
* Insert the value key to the appropriate place in the BST.
* @param root root of the input BST
* @param key  key of the Node need to be Inserted
* @return root
*/
struct Node* Insert(struct Node* root, int key){
   if (root == NULL) {
      return NewNode(key);
   }

   if (key < root->data){
      /* Insert in the left */
      root->left = Insert(root->left, key);
   } else
   if (key > root->data) {
      /* Inser to the right */
      root->right = Insert(root->right, key);
   }

   return root;
}

/**
* remove the value key from the tree.
* @param root root of the input BST
* @param key  key of the Node need to be removed
* @return root
*/
struct Node* RemoveKey(struct Node* root, int key){
   if (root == NULL) {
      return root;
   }

   if (key < root->data) {        /* key < current Node data*/
      root->left = RemoveKey(root->left, key);
      return root;
   } else
   if (key > root->data) {        /* key > current Node data*/
      root->right = RemoveKey(root->right, key);
      return root;
   } else {                       /* key == current Node data, remove current Node */

      if (root->left == NULL) {
      /* Condition 1: root->left is empty, replace root with root->right */
         struct Node* pTemp = root->right;
         free(root);
         return pTemp;
      } else
      if (root->right == NULL) {
      /* Condition 2: root->right is empty, replace root with root->left */
         struct Node* pTemp = root->left;
         free(root);
         return pTemp;
      }

      /* Condition 3: root have both left and right child, swap the data of min(root->right) and free min(root->right)*/
      struct Node* pTemp = FindMin(root->right);
      root->data = pTemp->data;
      root->right = RemoveKey(root->right, pTemp->data);

   }

   return root;
}

/**
* Return the Node of the tree which has the value key.
* @param root root of the input BST
* @param key  key of the Node need to be Inserted
* @return the Node that has the value key
*/
struct Node* Search(struct Node* root, int key){
   if (root->data == key || root == NULL) {
      return root;
   } else
   if (key < root->data) {
      return Search(root->left, key);
   } else {
      return Search(root->right, key);
   }
}

/**
* Return the minimum value in the tree.
* @param root root of the input BST
* @return the minimum key's Node in the BST
* @see FindMax()
*/
struct Node* FindMin(struct Node* root){
   while (root->left != NULL) {
      root = root->left;
   }
   return root;
}

/**
* Return the maximum value in the tree.
* @param root root of the input BST
* @return the max key's Node in the BST
* @see finMin()
*/
struct Node* FindMax(struct Node* root){
   while (root->right != NULL) {
      root = root->right;
   }
   return root;
}

/**
* Print the in-order traversal of the tree.
* @param root root of the input BST
* @return 0
* @see PreOrderTraversal(), PostOrderTraversal()
*/
void InOrderTraversal(struct Node* root){
   if (root == NULL) {
      return;
   }

   InOrderTraversal(root->left);
   printf(" %d", root->data);
   InOrderTraversal(root->right);
}

/**
* Print the pre-order traversal of the tree.
* @param root
* @return 0
* @see pInOrderTraversal(), PostOrderTraversal()
*/
void PreOrderTraversal(struct Node* root){
   if (root == NULL) {
      return;
   }

   printf(" %d", root->data);
   PreOrderTraversal(root->left);
   PreOrderTraversal(root->right);

}

/**
* Print the post-order traversal of the tree.
* @param root
* @return 0
* @see PreOrderTraversal(), InOrderTraversal()
*/
void PostOrderTraversal(struct Node* root){
   if (root == NULL) {
      return;
   }

   PostOrderTraversal(root->left);
   PostOrderTraversal(root->right);
   printf(" %d", root->data);
}

/**
* Return sorted list of keys that is smaller than the specified key.
* @param root
* @param key
* @return 0
* @see KeysMoreThan()
*/
void KeysLessThan(struct Node* root, int key){

   if(root == NULL) {
      return;
   }
   if (key <= root->data) {
      KeysLessThan(root->left, key);
   } else {
      KeysLessThan(root->left, key);
      printf(" %d", root->data);
      KeysLessThan(root->right, key);
   }
}

/**
* Return sorted list of keys that is smaller than the specified key.
* @param root
* @param key
* @return 0
* @see KeysLessThan()
*/
void KeysMoreThan(struct Node* root, int key){
   if(root == NULL) {
      return;
   }

   if (key >= root->data) {
      KeysMoreThan(root->right, key);
   } else {
      KeysMoreThan(root->left, key);
      printf(" %d", root->data);
      KeysMoreThan(root->right, key);
   }
}


