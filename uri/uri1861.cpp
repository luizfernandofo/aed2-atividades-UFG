#include<iostream>
#include<vector>

using namespace std;

class Killer{ // classe que representa um assassino

    public:
        string name; // string para o nome
        bool alive; // checar se ele foi morto ou não
        int kills; // quantidade de pessoas que ele assassinou

        Killer(){ // construtor
            alive = true;
            kills = 1;
        }
};

class TreeNode{ // classe molde para um nó da árvore

    public:
        Killer killer; // data contida no nó 

        TreeNode *LeftChild, *RightChild; // ponteiros para nós filhos

    public:

        TreeNode(){ // construtor
            LeftChild = RightChild = NULL;
        }
};

class BSTree{ // classe da árvore 

    public:
        TreeNode *Root; // nó raiz

    public:

        /**
         * @brief Função para inserir um nó na árvore de forme binária.
         * 
         * @param killer ponteiro de uma string para o nome do assassino
         */
        void InsertNode(string *killer);

        /**
         * @brief Função que verifica se um assassino contido na árvore foi morto. Caso tenha sido a variável alive (bool) recebe false.
         * 
         * @param killer ponteiro para a string com o nome da pessoa assassinada.
         * @return int retorna 1 se o nome enviado é alguém que está na árvore e 0 caso não.
         */
        int Killed(string *killer);

        /**
         * @brief Função que percorre a árvore de forma InOrder e desaloca o ponteiro root no final.
         * 
         * @param root ponteiro nó onde será iniciado o percurso.
         */
        void InOrder(TreeNode *root);

        BSTree(){ // construtor
            Root = NULL;
        }

};

/**
 * @brief Função para comparar 2 strings.
 * 
 * @param str1 ponteiro para a string 1.
 * @param str2 ponteiro para a string 2.
 * @return int retorna -1 se str1 preceder str2; 0 se forem iguais; 1 se str2 preceder str1; 3 se ocorrer algum erro.
 */
int compare(string *str1, string *str2);

int main(void)
{
    unsigned int i; // contadores

    BSTree killers_tree;

    vector<string> killed;

    string temp_name;

    while(1){
        cin >> temp_name; // lê o primeiro nome
        if(cin.eof()) break; // checa se há fim do arquivo logo
        killers_tree.InsertNode(&temp_name); // insere um nó com o nome lido
        cin >> temp_name; // lê um segundo nome
        killed.push_back(temp_name); // insere o nome dos assassinados em um vetor para futura consulta na árvore
    }
    
    for(i=0; i<killed.size(); i++) killers_tree.Killed(&killed[i]); // chama a função BSTree::Killed()
    
    cout << "HALL OF MURDERERS" << endl; 

    killers_tree.InOrder(killers_tree.Root); // chama a função de percurso iniciando no nó da árvore

    return 0;
}


void BSTree::InsertNode(string *killer){

    TreeNode *Tmp = NULL, *NewNode=NULL;

        if( Root == NULL) {  
            NewNode = new TreeNode;
            NewNode->killer.name = *killer;
            Root = NewNode;
            return;
        }
        Tmp = Root;
        while(Tmp != NULL ){
            if(killer->compare(Tmp->killer.name) == 0){

                Tmp->killer.kills++;
                return;

            }else if(killer->compare(Tmp->killer.name) < 0){

                if(Tmp->LeftChild == NULL){

                    NewNode = new TreeNode;
                    NewNode->killer.name = *killer;
                    Tmp->LeftChild = NewNode;

                    return;
                }

                Tmp = Tmp->LeftChild;
            }
            else if(killer->compare(Tmp->killer.name) > 0){

                if(Tmp->RightChild == NULL){

                    NewNode = new TreeNode;
                    NewNode->killer.name = *killer;
                    Tmp->RightChild = NewNode;

                    return;
                }

                Tmp = Tmp->RightChild;
            }
        }
    

    return;

}

int BSTree::Killed(string *killer){

    TreeNode *Tmp = NULL;

        if( Root == NULL) {
            return 0;
        }
        Tmp = Root;
        while(Tmp != NULL ){
            
            if(compare(killer, &(Tmp->killer.name)) == 0){

                Tmp->killer.alive = false;
               
                return 1;

            }else if(compare(killer, &(Tmp->killer.name)) < 0){

                if(Tmp->LeftChild) Tmp = Tmp->LeftChild;
                else Tmp = NULL;
            }
            else if(compare(killer, &(Tmp->killer.name)) > 0){

                if(Tmp->RightChild) Tmp = Tmp->RightChild;
                else Tmp = NULL;
            }
        }
    
        
    return 0;

}

void BSTree::InOrder(TreeNode *root){

    if(root){
        InOrder(root->LeftChild);
        if(root->killer.alive) cout << root->killer.name << " " << root->killer.kills << endl;
        InOrder(root->RightChild);
        delete root;
    }

    return;

}

int compare(string *str1, string *str2){

    int i=0;
    int str1_len, str2_len;

    str1_len = str1->length();
    str2_len = str2->length();
    
    if(str1_len == str2_len){
        while(i < str1_len){

            if((*str1)[i] == (*str2)[i]) i++;
            else if ((*str1)[i] < (*str2)[i]) return -1;
            else return 1;

        }
        return 0;

    }else if(str1_len < str2_len){
        while(i < str1_len){

            if((*str1)[i] == (*str2)[i]) i++;
            else if ((*str1)[i] < (*str2)[i]) return -1;
            else return 1;

        }
        return 0;

    }else if(str1_len > str2_len){
        while(i < str2_len){

            if((*str1)[i] == (*str2)[i]) i++;
            else if ((*str1)[i] < (*str2)[i]) return -1;
            else return 1;

        }
        return 0;
    }
    
    return 3;
}