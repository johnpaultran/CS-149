// Shayanna Gatchalian & John Paul Tran

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContactNode.h"

// function to create a new contact node
void CreateContactNode(ContactNode* thisNode, char nameInit[], char phoneNumInit[], ContactNode* nextLoc)
{
    strcpy(thisNode->contactName, nameInit);
    strcpy(thisNode->contactPhoneNum, phoneNumInit);
    thisNode->nextNodePtr = nextLoc;
    return;
}

// function to insert node in list
void InsertContactAfter(ContactNode* thisNode, ContactNode* newNode)
{
    ContactNode* temp = NULL;
    temp = thisNode->nextNodePtr;
    thisNode->nextNodePtr = newNode;
    newNode->nextNodePtr = temp;
    return;
}

// function to get next node
ContactNode* GetNextContact(ContactNode* thisNode)
{
   return thisNode->nextNodePtr;   
}

// function to print current node
void PrintContactNode(ContactNode* thisNode)
{
   printf("Name: %s\nPhone number: %s\n\n", thisNode->contactName, thisNode->contactPhoneNum);
   return;
}