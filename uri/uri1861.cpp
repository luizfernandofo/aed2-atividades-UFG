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
        Killer killer;

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
    
        void InsertNode(string *killer);

        int Killed(string *killer);

        void BFS();

        BSTree(){
            Root = NULL;
        }

};

int compare(string *str1, string *str2);

int main(void)
{
    unsigned int i; // contadores

    BSTree killers_tree;

    vector<string> killed;

    string temp_name;

    while(1){
        cin >> temp_name;
        if(cin.eof()) break;
        killers_tree.InsertNode(&temp_name);
        cin >> temp_name;
        killed.push_back(temp_name);
        //if(killers_tree.Killed(&killed.back())) killed.pop_back();
    }
    
    for(i=0; i<killed.size(); i++) killers_tree.Killed(&killed[i]);
    
    cout << "HALL OF MURDERERS" << endl;

    killers_tree.BFS();

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

void BSTree::BFS(){

    if(Root == NULL) return;

    nivel.push(Root);

    while(!nivel.empty()){
        if(nivel.front()->killer.alive) cout << nivel.front()->killer.name << " " << nivel.front()->killer.kills << endl;

        if(nivel.front()->LeftChild) nivel.push(nivel.front()->LeftChild);

        if(nivel.front()->RightChild) nivel.push(nivel.front()->RightChild);

        delete nivel.front();

        nivel.pop();

    }

    Root = NULL;

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