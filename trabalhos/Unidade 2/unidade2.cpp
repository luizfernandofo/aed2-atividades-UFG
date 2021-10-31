#include<iostream>
#include<vector>
#include<string>
#include<ios>
#include<limits>

#define TAMANHO_MAX 50

using namespace std;

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #define CLS "cls"
    	    
#else
	#define CLS "clear"

#endif

class Paciente
{
    public:
        int prioridade;
        string nome;
};

class Heap
{
    public:
        Paciente *heap;
        uint16_t tamanhoAtual;
        uint16_t tamanhoMax;

        Heap(uint16_t tamanhoMax)
        {
            this->tamanhoMax = tamanhoMax;
            heap = new Paciente[tamanhoMax];
            tamanhoAtual = 0;
        }

        ~Heap()
        {
            delete[] heap;
        }

        uint16_t pai(uint16_t i)
        {
            return (i-1)/2.0;
        }
        
        uint16_t filhoEsquerda(uint16_t i)
        {
            return 2*i+1;
        }

        uint16_t filhoDireita(uint16_t i)
        {
            return 2*i+2;
        }

        void reHeapUp(uint16_t i)
        {
            Paciente temp;

            while( i > 0 && heap[i].prioridade > heap[pai(i)].prioridade)
            {
                temp = heap[i];

                heap[i] = heap[pai(i)];
                heap[pai(i)] = temp;
                i = pai(i);
            }

            return;
        }

        void reHeapDown(uint16_t i){
            Paciente temp;
            uint16_t j;

            while(2*i + 1 < tamanhoAtual){
                j = 2*i + 1;

                if(j+1 < tamanhoAtual && heap[j + 1].prioridade >= heap[j].prioridade)
                    j = j + 1;

                if(heap[i].prioridade >= heap[j].prioridade)
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

        void insert(uint16_t prioridade, string nome) 
        {
            heap[tamanhoAtual].prioridade = prioridade;
            heap[tamanhoAtual].nome.assign(nome);
    
            reHeapUp(tamanhoAtual);
            tamanhoAtual++;

            return;
        }

        void deleteMaxVal()
        {
            Paciente temp;

            temp = heap[0];
            heap[0] = heap[tamanhoAtual - 1];
            heap[tamanhoAtual - 1] = temp;

            tamanhoAtual--;

            reHeapDown(0);

            return;
        }

        void printHeap()
        {
            uint16_t i;

            for(i=0; i<tamanhoAtual; i++)
            {
                cout <<"[" << i+1 << "] " << "Prioridade: " << heap[i].prioridade << " Paciente: " << heap[i].nome << endl;
            }

            return;
        }
};

void pause(){

    setbuf(stdin, NULL); //não pode ter "lixo" no stdin para ela funcionar
    printf("\nPressione ENTER para continuar..."); 
    cin.get();

    return;
}

int main(void)
{
    Heap fila_p(TAMANHO_MAX);

    Paciente temp;
    bool rodando=true;

    int opcao;

    while(rodando)
    {
        system(CLS);
        cout << "HEAP:" << endl;
        fila_p.printHeap(); // imprime todo o vetor heap
        cout << "\n===========================================\n" << endl ;
        cout << "(1) Triar paciente." << endl;
        cout << "(2) Encaminhar paciente." << endl;
        cout << "(9) Encerrar programa." << endl;

        cin >> opcao;

        //limpa o buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        switch(opcao)
        {
            case 1:
                system(CLS);

                cout << "Nome do paciente: ";
                getline(cin, temp.nome);

                cout << "Prioridade [1 (leve), 5 (grave)]: ";
                cin >> temp.prioridade;

                fila_p.insert(temp.prioridade, temp.nome);

                pause();

                break;

            case 2:
                system(CLS);

                fila_p.deleteMaxVal();

                cout << "Paciente " << fila_p.heap[fila_p.tamanhoAtual].nome << " encaminhado." << endl;

                pause();

                break;

            case 9:
                rodando = false;
                break;
        
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    }

    return 0;
}
