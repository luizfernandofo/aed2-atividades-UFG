#include<iostream>
#include<queue>
#include<stdio.h>

#define TAMANHO 53

using namespace std;

class TreeNode{

    public:
        string *killer;
        int amount_killed;

        TreeNode *LeftChild, *RightChild;

    public:

        TreeNode(){
            LeftChild = RightChild = NULL;
            killer = NULL;
            amount_killed = 0;
        }
};

class BSTree{

    public:
        TreeNode *Root;

        queue<TreeNode *> nivel;

    public:
    
        void InsertNode(string *killer);

        void BFS();

        BSTree(){
            Root = NULL;
        }

};


int main(void)
{
    unsigned int i, j; // contadores

    BSTree killers_tree;

    vector<string> killers, killed;

    char temp[10+1];

    while(1){
        cin >> temp;
        if(cin.eof()) break;
        killers.push_back(temp);
        cin >> temp;
        killed.push_back(temp);
    }
    

    for(i=0; i<killers.size(); i++){
        for(j=0; j<killed.size(); j++){
            if(killers[i].compare(killed[j]) == 0){
                killers.erase(killers.begin()+i);
                break;
            }
        }
    }

    for(i=0; i<killers.size(); i++) cout << killers[i] << endl;
    cout << endl;
    for(i=0; i<killed.size(); i++) cout << killed[i] << endl;
    
    //for(i=0; i<killers.size(); i++) killers_tree.InsertNode(&killers[i]);

    cout << "HALL OF MURDERERS" << endl;

    killers_tree.BFS();

    return 0;
}


void BSTree::InsertNode(string *killer){

    TreeNode *Tmp, *NewNode = new TreeNode;

        NewNode->killer = killer;
        NewNode->amount_killed++;

        if( Root == NULL) {
            Root = NewNode; return;
        }
        Tmp = Root ;
        while(Tmp != NULL ){
            if(NewNode->killer->compare(*(Tmp->killer)) == 0){
                Tmp->amount_killed++;
                delete NewNode;

            }else if(NewNode->killer->compare(*(Tmp->killer)) < 0){
                if(Tmp->LeftChild == NULL) {
                Tmp->LeftChild = NewNode; return;
                }
                Tmp = Tmp->LeftChild;
            }
            else if(NewNode->killer->compare(*(Tmp->killer)) > 0){
                if(Tmp->RightChild == NULL){
                Tmp->RightChild = NewNode ; return;
            }
            Tmp = Tmp->RightChild;
        }
    }

    return;

}

void BSTree::BFS(){

    if(Root == NULL) return;

    nivel.push(Root);

    while(!nivel.empty()){
        cout << *(nivel.front()->killer) << " " << nivel.front()->amount_killed << endl;

        if(nivel.front()->LeftChild) nivel.push(nivel.front()->LeftChild);

        if(nivel.front()->RightChild) nivel.push(nivel.front()->RightChild);

        delete nivel.front();

        nivel.pop();

    }

    Root = NULL;

    return;

}