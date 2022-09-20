testInvoice: testInvoice.o Invoice.o
	g++ -o testInvoice testInvoice.o Invoice.o -g 
	
#-g serve a creare un file eseguibile che possa essere interpretato dal debugger
testInvoice.o: testInvoice.cpp Invoice.h
	g++ -std=c++11 -c testInvoice.cpp
Invoice.o: Invoice.cpp Invoice.h
	g++ -std=c++11 -c Invoice.cpp	