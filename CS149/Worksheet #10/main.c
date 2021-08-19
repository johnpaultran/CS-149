// Shayanna Gatchalian & John Paul Tran

#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

int main(void) 
{
   char c;
   ItemToPurchase firstItem;
   ItemToPurchase secondItem;
   
   for (int i = 0; i < 2; i++) 
   {
        // first item info
        if (i == 0)
        {
            printf("Item %d\n", i + 1);
            printf("Enter the item name:\n");
            fgets((firstItem.itemName), 50, stdin);
            fflush(stdin);
            int length = strlen(firstItem.itemName);
            firstItem.itemName[length - 1] = '\0';
            printf("Enter the item price:\n");
            scanf("%d", &(firstItem.itemPrice));
            printf("Enter the item quantity:\n\n");
            scanf("%d", &(firstItem.itemQuantity));
        }

        // second item info
        if (i == 1) 
        {
            printf("Item %d\n", i + 1);
            printf("Enter the item name:\n");
            fgets((secondItem.itemName), 50, stdin);
            fflush(stdin);
            int length = strlen(secondItem.itemName);
            secondItem.itemName[length - 1] = '\0'; // for removing new line
            printf("Enter the item price:\n");
            scanf("%d", &(secondItem.itemPrice));
            printf("Enter the item quantity:\n");
            printf("\n");
            scanf("%d", &(secondItem.itemQuantity));
        }
        
        // allow the user to input a new string
        c = getchar();
        while(c != '\n' && c != EOF) 
        {
            c = getchar();
        }
   }
   
   // calculate and print total cost
   int total = (firstItem.itemPrice * firstItem.itemQuantity) + (secondItem.itemPrice * secondItem.itemQuantity);
   printf("TOTAL COST\n");
   PrintItemCost(firstItem);
   PrintItemCost(secondItem);
   printf("\nTotal: $%d\n", total);
   
   return 0;
}