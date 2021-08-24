#include<iostream>
#include<queue>

using namespace std;

class Killer{

    public:
        string name;
        bool alive;
        int kills;

        Killer(){
            alive = true;
            kills = 1;
        }
};

class TreeNode{

    public:
        Killer *killer;

        TreeNode *LeftChild, *RightChild;

    public:

        TreeNode(){
            LeftChild = RightChild = NULL;
            killer = NULL;
        }
};

class BSTree{

    public:
        TreeNode *Root;

        queue<TreeNode *> nivel;

    public:
    
        void InsertNode(Killer *killer);

        void BFS();

        BSTree(){
            Root = NULL;
        }

};


int main(void)
{
    unsigned int i, j; // contadores

    BSTree killers_tree;

    vector<Killer> killers, killed;

    Killer temp;

    while(1){
        cin >> temp.name;
        if(cin.eof()) break;
        killers.push_back(temp);
        cin >> temp.name;
        killed.push_back(temp);
    }
    

    for(i=0; i<killers.size(); i++){
        for(j=0; j<killed.size(); j++){
            if(killers[i].name.compare(killed[j].name) == 0){
                killers[i].alive = false;
                break;
            }
        }
    }

    for(i=0; i<killers.size(); i++){
        if(killers[i].alive){
            for(j=i+1; j<killers.size(); j++){
                if(killers[j].alive){
                    if(killers[i].name.compare(killers[j].name) == 0){
                        killers[i].kills++;
                        killers[j].alive = false;
                        break;
                    }
                }
            }
        }
    }
    
    for(i=0; i<killers.size(); i++){
        if(killers[i].alive) killers_tree.InsertNode(&killers[i]);
    }

    cout << "HALL OF MURDERERS" << endl;

    killers_tree.BFS();

    return 0;
}


void BSTree::InsertNode(Killer *killer){

    TreeNode *Tmp, *NewNode = new TreeNode;

        NewNode->killer = killer;

        if( Root == NULL) {
            Root = NewNode;
            return;
        }
        Tmp = Root;
        while(Tmp != NULL ){
            if(NewNode->killer->name.compare(Tmp->killer->name) < 0){
                if(Tmp->LeftChild == NULL){
                    Tmp->LeftChild = NewNode;
                    return;
                }
                Tmp = Tmp->LeftChild;
            }
            else{
                if(Tmp->RightChild == NULL){
                    Tmp->RightChild = NewNode;
                    return;
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
        cout << nivel.front()->killer->name << " " << nivel.front()->killer->kills << endl;

        if(nivel.front()->LeftChild) nivel.push(nivel.front()->LeftChild);

        if(nivel.front()->RightChild) nivel.push(nivel.front()->RightChild);

        delete nivel.front();

        nivel.pop();

    }

    Root = NULL;

    return;

}