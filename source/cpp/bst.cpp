#include <iostream>
using namespace std;

class BSTNode{
    public:
        int info;
        long int position;
        BSTNode *left;
        BSTNode *right;
        
        BSTNode(long int value, int pos){
            info = value;
            position = pos;
            left=NULL;
            right=NULL;
        }

        int insertNode();
        int deleteNode(BSTNode *node);
};

int BSTNode::insertNode(long int value, int pos){
    BSTNode *root = this;
    if(root){
        
    }
}


int main() {
    int Q, pos=0;
    long int value;
    char operation;
    BSTNode root = NULL;
    
    cin>>Q;
    while(Q--){
        cin>>operation>>value;
        
        if(operation == 'i'){
            if(root)
                root = new BSTNode(value, pos++);
            else{
                root->insertNode(value, pos++);
            }
        }    
        if(operation == 'd'){
            
        }
    }
	return 0;
}
