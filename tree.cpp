/*
 * This is the impementation of binary search tree in c++
 * */

#include "iostream"


class node
{
public:
	int value;
	node *left;
	node *right;
	node(int val)
	{
	    value = val;
	    left = NULL;
	    right = NULL;
	}

};


class treeClass
{
public:
    treeClass()
    {
        root = NULL;
    }
    ~treeClass()
    {
       clear();
    }
    void clear(node *p)
    {
        while(p != NULL)
        {
            clear(p->right);
            clear(p->left);
            delete p;
        }
    }
    void clear()
    {
        node *p = root;
        while(p != NULL)
        {
            clear(p);
        }
    }
    node *root;
    void insertNode(int val)
    {
        node *insnode = new node(val);
        insertSubTree(insnode);
    }

    void insertSubTree(node *insNode)
    {
        if(insNode == NULL)
        {
            return;
        }
        node * parent;
        int val = insNode->value;
        if(root != NULL)
        {
            node *tree = root;
            while(tree != NULL)
            {
                parent = tree;
                if(tree->value >= val)
                {
                    tree = tree->left;
                }
                else
                {
                    tree = tree->right;
                }
            }
            if(parent->value >= val)
            {
                parent->left = insNode;
            }
            else
            {
                parent->right = insNode;
            }
        }
        else {
            root = insNode;
        }
    }

    void inorder(node *p)
    {
        if(p != NULL)
        {
            inorder(p->left);
            std::cout<<" "<<p->value;
            inorder(p->right);
        }
    }
    void preorder(node *p)
    {
        if(p != NULL)
        {
            std::cout<<" "<<p->value;
            preorder(p->left);
            preorder(p->right);
        }
    }
    void postorder(node *p)
    {
        if(p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            std::cout<<" "<<p->value;
        }
    }
    void inorder()
    {
        std::cout<<"\ninorder: ";
        node *p = root;
        if(p != NULL)
        {
            inorder(p);
        }
    }
    void preorder()
    {
        std::cout<<"\npreorder: ";
        node *p = root;
        if(p != NULL)
        {
            preorder(p);
        }
    }

    void postorder()
    {
        std::cout<<"\npostorder: ";
        node *p = root;
        if(p != NULL)
        {
            postorder(p);
        }
    }

    void deleteNode(int val)
    {
        if(root == NULL)
        {
            return;
        }
        node *parent = NULL;
        bool isLeft = false;
        if(!getParentNode(parent, val, isLeft))
        {
            return;
        }

        if(parent == NULL) //root node is the node containing given value;
        {
            node *p = root;
            if (root->right != NULL)
            {
                node *left = root->left;
                root = root->right;
                insertSubTree(left);
            }
            else
            {
                root = root->left;
            }
            delete p;
        }
        else
        {
            node *insnode = NULL;
            node *delnode = NULL;
            if(isLeft)
            {
                insnode = parent->left->left;
                delnode = parent->left;
                parent->left = parent->left->right;
            }
            else
            {
                insnode = parent->right->left;
                delnode = parent->right;
                parent->right = parent->right->right;
            }
            insertSubTree(insnode);
            if(delnode != NULL)
            {
                delete delnode;
            }
        }
    }
private:
    bool getParentNode(node* &parent, int &val, bool &isLeft)
    {
        bool status = false;
        parent = NULL;
        if(root != NULL)
        {
            node *tree = root;
            while(tree != NULL)
            {
                if(tree->value == val)
                {
                    status = true;
                    break;
                }
                parent = tree;
                if(tree->value > val)
                {
                    tree = tree->left;
                    isLeft = true;
                }
                else
                {
                    tree = tree->right;
                    isLeft = false;
                }
            }
        }
        return status;
    }
};

int main()
{
    treeClass testTree;
    testTree.insertNode(19);
    testTree.insertNode(100);
    testTree.insertNode(10);
    testTree.insertNode(12);
    testTree.insertNode(15);
    testTree.insertNode(14);
    testTree.insertNode(10);
    testTree.insertNode(18);
    testTree.insertNode(13);
    testTree.insertNode(11);

    testTree.inorder();
    testTree.deleteNode(200);
    testTree.preorder();
    testTree.postorder();
    testTree.deleteNode(10);
    testTree.postorder();

    std::cout<<"\nExecution completed."<<std::endl;
    return 0;
}




