#include<iostream>
#include"Invoice.h"
#include<string.h>

using std::cout;
using std::cin;

int main(){
    Invoice invoice1{"B-2001","PS4",2,1200};
    Invoice invoice2{"C-3300","Asus PC",3, 1800};

    invoice2.setDiscountRate(0.2); //20% di sconto
    invoice2.setVat(0.1);

    cout<<invoice1.getPartDescription()<<" "<<"x"<<" "<<invoice1.getQuantity()<<": "
        <<invoice1.getInvoiceAmount()<<" euro"<<std::endl;

    cout<<invoice2.getPartDescription()<<" x "<<invoice2.getQuantity()<<" - "<<invoice2.getDiscountRate()<<" + "
        <<invoice2.getVat()<<": "<<invoice2.getInvoiceAmount()<<" euro"<<std::endl;
    
    return 0;
}