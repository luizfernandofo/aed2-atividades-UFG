#include<iostream>
#include<queue>
#include<stdio.h>

#define TAMANHO 53

using namespace std;

class TreeNode{

    public:
        int data;

        TreeNode *LeftChild, *RightChild;

    public:

        TreeNode(){
            LeftChild = RightChild = NULL;
        }
};

class BSTree{

    public:
        TreeNode *Root;

        queue<TreeNode *> nivel;

    public:
    
        void InsertNode(int data);

        void BFS();

        BSTree(){
            Root = NULL;
        }

};


int main(void)
{
    int i; // contadores

    //BSTree t;

    vector<string> killers, killed;

    char temp[10+1];

    while(1){
        cin >> temp;
        killers.push_back(temp);
        cin >> temp;
        killed.push_back(temp);
        if(cin.eof()) break;
    }

    for(i=0; i<6; i++) cout << killers[i] << killers[i].size() << endl;

    for(i=0; i<6; i++) cout << killed[i] << killed[i].size() << endl;
    

    return 0;
}


void BSTree::InsertNode( int data ){

    TreeNode *Tmp, *NewNode = new TreeNode;

        NewNode->data = data;

        NewNode->LeftChild = NewNode->RightChild = NULL;
        if( Root == NULL) {
            Root = NewNode; return;
        }
        Tmp = Root ;
        while(Tmp != NULL ){
            if(data < Tmp->data){
                if(Tmp->LeftChild == NULL) {
                Tmp->LeftChild = NewNode; return;
                }
                Tmp = Tmp->LeftChild;
            }
            else{
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
        cout << nivel.front()->data;

        if(nivel.front()->LeftChild) nivel.push(nivel.front()->LeftChild);

        if(nivel.front()->RightChild) nivel.push(nivel.front()->RightChild);

        delete nivel.front();

        nivel.pop();

        if(nivel.size()) cout << " ";
    }

    Root = NULL;

    cout << endl;

    return;

}