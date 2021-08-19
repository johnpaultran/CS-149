// Shayanna Gatchalian & John Paul Tran

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContactNode.h"

int main(void)
{
    // initialize contact nodes
    ContactNode* head = NULL;
    ContactNode* current = NULL;
    ContactNode* nextNode = NULL;
    ContactNode* nextNode2 = NULL;

    // initialize char array for contact name & phone number
    char contactName[50] = "";
    char contactPhoneNum[50] = "";
    
    // loop to keep track of multiple nodes
    for(int i = 1; i <= 3; i++) 
    {
        printf("Person %d\nEnter name:\n", i);
        scanf("%[^\n]%*c", contactName);
        printf("Enter phone number:\n");
        scanf("%[^\n]%*c", contactPhoneNum);
        
        // first node
        if(i == 1) 
        {
            head = (ContactNode*)malloc(sizeof(ContactNode));
            CreateContactNode(head, contactName, contactPhoneNum, NULL);
        } 
        // second node
        else if(i == 2)
        {
            nextNode = (ContactNode*)malloc(sizeof(ContactNode));
            CreateContactNode(nextNode, contactName, contactPhoneNum, NULL);
            InsertContactAfter(head, nextNode);
        } 
        // other node
        else 
        {
            nextNode2 = (ContactNode*)malloc(sizeof(ContactNode));
            CreateContactNode(nextNode2, contactName, contactPhoneNum, NULL);
            InsertContactAfter(nextNode, nextNode2);
        }

        // print current node
        printf("You entered: %s, %s\n\n", contactName, contactPhoneNum);
    }

    // print the linked list
    printf("CONTACT LIST\n");
    for(current = head; current != NULL; current = GetNextContact(current))
    {
        PrintContactNode(current);
    }
    return 0;
}