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

#include <stdio.h>
#include <string.h>

#include "bst.h"

/**
* Binary Search Tree with element data in each nodes and have basic Binary Search Tree API/functions.
* @return 0
*/
void main(){

   struct Node* pRoot = NULL;    // pRoot of the BST
   char instruction[10];        // instruction read
   int data = 0;

   while (1) {

      scanf("%s", instruction);

      /* exit */
      if (0 == strcmp(instruction, "exit")) {
         break;
      }

      /* The lenth of first instruction is not 1 */
      if (instruction[1] != '\0') {
         printf("Incorrect instruction. Usage: <a-j> <integer>\n");
         break;
      }

      if (instruction[0] == 'a') {
         if(1 != scanf("%d", &data)) {
            printf("Invalid input. Usage: <a-f> <integer>\n");
            return;
         }
         pRoot = Insert(pRoot, data);
      } else
      if (instruction[0] == 'b') {
         if(1 != scanf("%d", &data)) {
            printf("Invalid input. Usage: <a-f> <integer>\n");
            return;
         }
         pRoot = RemoveKey(pRoot, data);
      } else
      if (instruction[0] == 'c') {
         if(1 != scanf("%d", &data)) {
            printf("Invalid input. Usage: <a-f> <integer>\n");
            return;
         }
         struct Node* Result = Search(pRoot, data);   // seach result
         if (Result) {
            printf("Key found.\n");
         } else {
            printf("Key not in the Binary Search Tree.\n");
         }
      } else
      if (instruction[0] == 'd') {
         struct Node* pMinNode = FindMin(pRoot);    // Node which has the minimum key of the BST
         printf("Min: %d\n", pMinNode->data);
      }else
      if (instruction[0] == 'e') {
         struct Node* pMaxNode = FindMax(pRoot);    // Node which has the max key of the BST
         printf("Max: %d\n", pMaxNode->data);
      } else
      if (instruction[0] == 'f') {
         printf("In-Order Traveral:");
         InOrderTraversal(pRoot);
         printf("\n");
      } else
      if (instruction[0] == 'g') {
         printf("Pre-Order Traveral:");
         PreOrderTraversal(pRoot);
         printf("\n");
      } else
      if (instruction[0] == 'h') {
         printf("Post-Order Traveral:");
         PostOrderTraversal(pRoot);
         printf("\n");
      } else
      if (instruction[0] == 'i') {
         if(1 != scanf("%d", &data)) {
            printf("Invalid input. Usage: <a-f> <integer>\n");
            return;
         }
         printf("Keys less than %d:", data);
         KeysLessThan(pRoot, data);
         printf("\n");
      } else
      if (instruction[0] == 'j') {
         if(1 != scanf("%d", &data)) {
            printf("Invalid input. Usage: <a-f> <integer>\n");
            return;
         }
         printf("Keys more than %d:", data);
         KeysMoreThan(pRoot, data);
         printf("\n");
      } else {
         printf("Invalid Input. Usage: <a-j> <integer>\n");  // instruction is not from <a-j>
         break;
      }
   }
}
