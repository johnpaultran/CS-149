// Shayanna Gatchalian & John Paul Tran

#ifndef CONTACTNODE_H
#define CONTACTNODE_H

// structure for ContactNode
typedef struct ContactNodeStruct 
{
   char contactName[50];
   char contactPhoneNum[50];
   struct ContactNodeStruct* nextNodePtr;
} ContactNode;

// function declarations
void CreateContactNode(ContactNode* thisNode, char nameInit[], char phoneNumInit[], ContactNode* nextLoc);
void InsertContactAfter(ContactNode* thisNode, ContactNode* newNode); 
ContactNode* GetNextContact(); 
void PrintContactNode();

#endif