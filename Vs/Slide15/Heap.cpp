#include <iostream>
#include <algorithm>

class Heap{
    private:
        int* array;
        unsigned int array_size;
        unsigned int heap_size;
        int lChild(int i){ //restituisce il figlio sx
            return 2*i+1;
        }
        int rChild(int i){ //restituisce il figlio dx
            return 2*i+2;
        }
        int parent(int i){ //restituisce il genitore
        return i+1/2 ;
         }  
    public:
        Heap(unsigned int size=100){//costruttore di default, inizializza un heap
        heap_size=0;
        array_size=size;
        array=new int[size];
        }

        ~Heap(){
            delete [] array;
        }

        void addElement(int e){//funzione per aggiungere un elemento in heap
        int i=heap_size++; //incrementa la size di heap e inverisce l'elemento alla fine
        array[i]=e;
        while(i>0 && array[parent(i)]<e) {//sale la struttura scalando i genitori
        std::swap(array[i], array[parent(i)]);
        }
        std::cout<<"elemento aggiunto"<<std::endl;
        }

        void heapify(int ind){//funzione per far rispettare la proprietà di heap in un nodo
            int l=lChild(ind);
            int r=rChild(ind); //posiziono due sentinelle come figlio destro e figlio sinistro
            int largest{0};
            if(l<=heap_size && array[l]> array[ind])
                largest = l;
            else    //effettuo la ricerca del massimo elemento tra padre-figlio dx- figlio sx
                largest=ind;
            if(r<=heap_size && array[r]>array[largest])
                largest=r;
            if(largest != ind){//una volta trovato il massimo lo metto eventualmente nella giusta posizione
            std::swap(array[largest], array[ind]);
            heapify(largest);
            }
             
        }

        void buildHeap(){ //funzione per costruire l'albero heap
        heap_size=array_size; //l'heap sarà grande quanto l'array stesso

        for(int i=array_size/2; i>=0; i--){ //partendo dalla metà dell'array richiamo heapify per rispettare la proprietà di heap
        heapify(i);
        }
             }
        
        void heapSort(){//algoritmo di ordinamento basato sull'heap
        buildHeap(); //costruisco l'heap in modo tale che il massimo valore si troverà sempre in alto
        unsigned int i{array_size};
        for(; i>=1; i--){//scambio il primo e l'ultimo elemento e diminuisco la dim dell'heap
        std::swap(array[i], array[0]);
        heap_size--;
        heapify(0);
        }
        }

        int extractHeapMax(){//funzione per rimuovere e restituire il max dell'heap
        if(heap_size<1){
            throw std::runtime_error("heap vuoto");
        }
        int max=array[1];
        array[1]=array[heap_size];
        heap_size--;
        heapify(1);
        return max;

        }

        void toString() {
            for(int i{0}; i<array_size; i++){
                std::cout<<array[i]<<" ";
            }
            std::cout<<std::endl;
        }
};

int main(){
    Heap h(10);
    h.addElement(10);
    h.addElement(4);
    h.addElement(1);
    h.addElement(12);
    h.addElement(21);
    h.addElement(22);
    h.addElement(23);
    h.addElement(54);
    h.addElement(13);
    h.addElement(5);

    h.toString();
    h.heapSort();
    h.toString();

}