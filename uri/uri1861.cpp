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

        void Killed(Killer *killer);

        void BFS();

        BSTree(){
            Root = NULL;
        }

};


int main(void)
{
    unsigned int i; // contadores

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
        if(killers[i].alive) killers_tree.InsertNode(&killers[i]);
    }

    for(i=0; i<killers.size(); i++){
        if(killers[i].alive) killers_tree.Killed(&killed[i]);
    }

    cout << "HALL OF MURDERERS" << endl;

    killers_tree.BFS();

    return 0;
}


void BSTree::InsertNode(Killer *killer){

    TreeNode *Tmp = NULL, *NewNode=NULL;

        if( Root == NULL) {
            NewNode = new TreeNode;
            NewNode->killer = killer;
            Root = NewNode;
            return;
        }
        Tmp = Root;
        while(Tmp != NULL ){
            if(killer->name.compare(Tmp->killer->name) == 0){

                Tmp->killer->kills++;
                return;

            }else if(killer->name.compare(Tmp->killer->name) < 0){

                if(Tmp->LeftChild == NULL){

                    NewNode = new TreeNode;
                    NewNode->killer = killer;
                    Tmp->LeftChild = NewNode;

                    return;
                }

                Tmp = Tmp->LeftChild;
            }
            else if(killer->name.compare(Tmp->killer->name) > 0){

                if(Tmp->RightChild == NULL){

                    NewNode = new TreeNode;
                    NewNode->killer = killer;
                    Tmp->RightChild = NewNode;

                    return;
                }

                Tmp = Tmp->RightChild;
            }
        }
    

    return;

}

void BSTree::Killed(Killer *killer){

    TreeNode *Tmp = NULL;

        if( Root == NULL) {
            return;
        }
        Tmp = Root;
        while(Tmp != NULL ){
            if(killer->name.compare(Tmp->killer->name) == 0){

                Tmp->killer->alive = false;

                return;

            }else if(killer->name.compare(Tmp->killer->name) < 0){

                if(Tmp->LeftChild) Tmp = Tmp->LeftChild;
                else Tmp = NULL;
            }
            else if(killer->name.compare(Tmp->killer->name) > 0){

                if(Tmp->RightChild) Tmp = Tmp->RightChild;
                else Tmp = NULL;
            }
        }
    

    return;

}

void BSTree::BFS(){

    if(Root == NULL) return;

    nivel.push(Root);

    while(!nivel.empty()){
        if(nivel.front()->killer->alive) cout << nivel.front()->killer->name << " " << nivel.front()->killer->kills << endl;

        if(nivel.front()->LeftChild) nivel.push(nivel.front()->LeftChild);

        if(nivel.front()->RightChild) nivel.push(nivel.front()->RightChild);

        delete nivel.front();

        nivel.pop();

    }

    Root = NULL;

    return;

}