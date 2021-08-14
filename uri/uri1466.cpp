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
    int cases, i, j, n, data; // contadores

    BSTree t;

    cin >> cases;

    for(i=1; i<=cases; i++){
        cin >> n;
        for(j=0; j<n; j++){
            cin >> data;
            t.InsertNode(data);
            t.BFS();
        }

    }


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

    TreeNode *temp = NULL;

    if(Root == NULL) return;

    temp = Root;

    nivel.push(Root);

    while(!nivel.empty()){
        cout << nivel.front()->data << " ";
        if(nivel.front()->LeftChild) nivel.push(nivel.front()->LeftChild);
        if(nivel.front()->RightChild) nivel.push(nivel.front()->RightChild);
        nivel.pop();
    }

    cout << endl;

    return;

}