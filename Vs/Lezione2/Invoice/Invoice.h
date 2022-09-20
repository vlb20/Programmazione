/*(Invoice class) Create a class called Invoice that a hardware store might
use to represent an invoice for an item sold at the store. An Invoice
should include six data members-a part number (type string), a part
description (type string), a quantity of the item being purchased (type
int), a price per item (type int) a value-added tax (VAT) rate as a decimal
(type float) and a discount rate as a decimal(type float).
• Your class should have a constructor that initializes the six data members.
• The constructor should initialize the first four data members with values
from parameters and the last two data members to default values of 0.20 per
cent and zero respectively.
• Provide a set and a get functions for each data member.
• In addition, provide a member function named getInvoiceAmount that
calculates the invoice amount (i.e., multiplies the quantity by the price
per item and applies the tax and discount amounts), then returns the
amount.
• Have the set data members perform validity checks on their parameters—if a
parameter value is not positive, it should be left unchanged. Write a
driver program to demonstrate Invoice’s capabilities.*/

#include<string.h>
#include<iostream>

class Invoice{
    public:

        Invoice(std::string number, std::string description, int qty, int price);

        void setPartNumber(std::string number);
        std::string getPartNumber();

        void setPartDescription(std::string description);
        std::string getPartDescription();

        void setQuantity(int qty);
        int getQuantity();

        void setPriceItem(int price);
        int getPriceItem();

        void setVat(float v);
        float getVat();

        void setDiscountRate(float discount);
        float getDiscountRate();

        float getInvoiceAmount();
            

    private:
        std::string partNumber;
        std::string partDescription;
        int quantity;
        int priceItem;
        float VAT;
        float discountRate;

};

