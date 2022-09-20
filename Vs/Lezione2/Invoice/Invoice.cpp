#include<string.h>
#include "Invoice.h"
#include <iostream>

    Invoice::Invoice(std::string number, std::string description, int qty, int price)
     :partNumber{number}, partDescription{description}, quantity{qty}, priceItem{price}, VAT{0.2}, discountRate{0}{

     }

     void Invoice::setPartNumber(std::string number){
        partNumber=number;
     }

     std::string Invoice::getPartNumber(){
        return partNumber;
     }

     void Invoice::setPartDescription(std::string description){
        partDescription=description;
     }

     std::string Invoice::getPartDescription(){
        return partDescription;
     }

     void Invoice::setQuantity(int qty){
        if(qty>0){
            quantity=qty;
        }
     }

     int Invoice::getQuantity(){
        return quantity;
     }

     void Invoice::setPriceItem(int price){
        if(price>0)
            priceItem=price;
     }

     int Invoice::getPriceItem(){
        return priceItem;
     }

     void Invoice::setVat(float v){
        if(v>=0.0 && v<=1.0){
            VAT=v;
        }else{
            std::cout<<"Valore non valido!\n";
        }
     }

     float Invoice::getVat(){
        return VAT;
     }

    void Invoice::setDiscountRate(float discount){
        if(discount>=0 && discount<=1.0){
            discountRate=discount;
        }else{
            std::cout<<"Valore non valido!\n";
        }
    }

    float Invoice::getDiscountRate(){
        return discountRate;
    }

    float Invoice::getInvoiceAmount(){
        float Amount=quantity*priceItem;
        Amount=Amount-Amount*discountRate+Amount*VAT;
        return Amount;
        
    }    