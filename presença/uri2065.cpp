#include<iostream>
#include<vector>

#define TAMANHO_MAX 10000

using namespace std;

//Código não funcional

class Func
{
    public:
        uint64_t velocidade, tempo, id;
};

class Heap
{
    public:
        Func *heap;
        uint64_t tamanhoAtual;
        uint64_t tamanhoMax;

        Heap(uint64_t tamanhoMax)
        {
            this->tamanhoMax = tamanhoMax;
            heap = new Func[tamanhoMax];
            tamanhoAtual = 0;
        }

        ~Heap()
        {
            delete[] heap;
        }

        uint64_t pai(uint64_t i)
        {
            return (i-1)/2.0;
        }
        
        uint64_t filhoEsquerda(uint64_t i)
        {
            return 2*i+1;
        }

        uint64_t filhoDireita(uint64_t i)
        {
            return 2*i+2;
        }

        void reHeapUp(uint64_t i)
        {
            Func temp;

            while( i > 0 && heap[i].tempo < heap[pai(i)].tempo)
            {
                temp = heap[i];

                heap[i] = heap[pai(i)];
                heap[pai(i)] = temp;
                i = pai(i);
            }

            return;
        }

        void reHeapDown(uint64_t i){
            Func temp;
            uint64_t j;

            while(2*i + 1 < tamanhoAtual){
                j = 2*i + 1;

                if(j+1 < tamanhoAtual && heap[j + 1].tempo < heap[j].tempo)
                    j = j + 1;

                if(heap[i].tempo < heap[j].tempo)
                    break;
                else {
                    temp = heap[i];
                    heap[i] = heap[j];
                    heap[j] = temp;

                    i = j;
                }
            }

            return;
        }

        void insert(uint64_t valor, uint64_t velocidade) 
        {
            heap[tamanhoAtual].tempo = valor;
            heap[tamanhoAtual].velocidade = velocidade;
            reHeapUp(tamanhoAtual);
            tamanhoAtual++;

            return;
        }

        /*void deleteMaxVal()
        {
            Func temp;

            temp = heap[0];
            heap[0] = heap[tamanhoAtual - 1];

            tamanhoAtual--;

            reHeapDown(0);

            return;
        }

        void printHeap()
        {
            uint64_t i;

            for(i=0; i<tamanhoAtual; i++)
            {
                cout << heap[i].tempo << ", ";
            }

            return;
        }*/
};

int main(void)
{
    Heap h(TAMANHO_MAX);

    uint64_t vendorSpeed;
    uint64_t funcs;
    uint64_t customers;
    uint64_t customersProducts;

    cin >> funcs >> customers;

    while(funcs--)
    {
        cin >> vendorSpeed;
        h.insert(0, vendorSpeed);
    }

    for(uint64_t i=0; i<h.tamanhoAtual; i++)
    {
        h.heap[i].id = i;
    }
    
    while(customers--)
    {
        cin >> customersProducts;
        if(h.tamanhoAtual > 1 && h.heap[0].tempo == h.heap[1].tempo)
        {
            if(h.heap[0].id < h.heap[1].id)
            {
                h.heap[0].tempo += customersProducts * h.heap[0].velocidade;    
                h.reHeapDown(0);    
            }
            else
            {
                h.heap[1].tempo += customersProducts * h.heap[1].velocidade;    
                h.reHeapDown(1);    
            }
        }
        else
        {
            h.heap[0].tempo += customersProducts * h.heap[0].velocidade;
            h.reHeapDown(0);
        }
                
    }
    
    cout << h.heap[h.tamanhoAtual-1].tempo << endl;

    return 0;
}
