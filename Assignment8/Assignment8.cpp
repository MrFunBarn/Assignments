void AddNode(TreeNode *node){
    Node *tmp = new Node;
    Node *parent = new Node;
    while( tmp->next != NULL ){
        parent = tmp;
        tmp = tmp->next;
    }
    Node *newnode = new Node;
    newnode->key = node->key;
    parent->next = newdone;
}


bool checkNode(TreeNode *node, char m, char n){
    if( char m < node->key < char n ){
        return true;
    }
    else{
        return false;
    }
}


void RangeSearch( TreeNode *node, char m, char, n ){
    TreeNode *current = new TreeNode;
    current = node;
    TreeNode *tmp = new TreeNode;
    TreeNode *down = new TreeNode;
    while( current != NULL ){
           current = current->left; 
    }
    current = current->parent;
    if( checkNode( current->right ) ){
        down = current->right;
    }
}
