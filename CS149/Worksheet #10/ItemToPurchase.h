// Shayanna Gatchalian & John Paul Tran

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

// structure for ItemToPurchase
typedef struct ItemToPurchaseStruct 
{
   char itemName[50];
   int itemPrice;
   int itemQuantity;
} ItemToPurchase;
  
// function declarations
void MakeItemBlank(ItemToPurchase* item);
void PrintItemCost(ItemToPurchase item);

#endif