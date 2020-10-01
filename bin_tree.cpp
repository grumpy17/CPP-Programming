#include<iostream.h>
#include <cstring>

using namespace std;

typedef struct node
{
    int data;
    struct node *lf, *rt;
}NODE;

class BST
{
    NODE *root;
    public: BST()
            {
                root = NULL;
            }
            void createBinary();
            void addNewNode();
            NODE* search(NODE *root, int key);
            void deletenode(int key);
            void display(NODE *cn);
            NODE* getroot()
           {
               return root;
           }
};

void BST :: createBinary()
{
    int n;
    cout << "\n Enter the number of nodes: ";
    cin >> n;

    bool flag=0; //0 for left and 1 for right
    NODE *newnode, *cn, *parent;

    for(int i=0; i<n; i++)
    {
        newnode = new NODE;
        newnode->lf = newnode->rt = NULL;
        cout << "\n Enter the data: ";
        cin >> newnode->data;

        if(root == NULL)
            root = newnode;
        else{
            cn = root;
            while(cn != NULL)
            {
                parent = cn;
                if(newnode->data < cn->data)    //go to left subtree
                {
                    flag = 0;
                    cn = cn->lf;
                }
                else                           //go to right subtree
                {
                    flag = 1;
                    cn = cn->rt;
                }
            }

            if(flag == 0)
                parent->lf = newnode;
            else
                parent->rt = newnode;
        }//end outer else
    }//end for
}

void BST :: addNewNode()
{
    if(root == NULL)
        cout << "\n The tree is not created. ";
    else
    {
        bool flag=0; //0 for left and 1 for right
        NODE *newnode, *cn, *parent;
        newnode = new NODE;
        newnode->lf = newnode->rt = NULL;

        cout << "\n Enter the data: ";
        cin >> newnode->data;

        cn = root;
        while(cn != NULL)
        {
            parent = cn;
            if(newnode->data < cn->data)
            {
                flag = 0;
                cn = cn->lf;
            }
            else
            {
                flag = 1;
                cn = cn->rt;
            }
        }
        if(flag == 0)
            parent->lf = newnode;
        else
            parent->rt = newnode;
    }
}

NODE* BST :: search(NODE *root, int key)
{
    if(root == NULL || root->data == key)
        return root;                     // Key is greater than cn's data
    if (root->data < key)
        return search(root->rt, key);    // Key is smaller than cn's data
    return search(root->lf, key);
}

void BST :: deletenode(int key)
{
    bool flag=0;
    int data1;
    NODE *cn, *parent, *temp;
    cn = root;

    while(cn != NULL)
    {
        if(key < cn->data)
        {
            parent = cn;
            cn = cn->lf;
            flag = 0;
        }
        else if(key > cn->data)
        {
            parent = cn;
            cn = cn->rt;
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        if(cn->lf == NULL && cn->rt == NULL)      //case 1
        {
            if(cn == root)
                root = NULL;
            else if(cn->data < parent->data)
                parent->lf = NULL;
            else
                parent->rt = NULL;

            delete cn;
        }

        else if(cn->lf == NULL && cn->rt != NULL)  //case 2
        {
            if(cn == root)
                root = cn->rt;
            else if(cn->data < parent->data)
                parent->lf = cn->rt;
            else
                parent->rt = cn->rt;

            delete cn;
        }

        else if(cn->rt == NULL && cn->lf != NULL)  //case 2
        {
            if(cn == root)
                root = cn->lf;
            else if(cn->data < parent->data)
                parent->lf = cn->lf;
            else
                parent->rt = cn->lf;

            delete cn;
         }

         else if(cn->lf != NULL && cn->rt != NULL)  //case 3
         {
             temp = cn->lf;
             while(temp->rt != NULL)
                 temp = temp->rt;

             data1 = temp->data;
             deletenode(temp->data);

             cn->data = data1;
         }

         else
            cout << "\n Node is not present. ";
    }
}

void BST :: display(NODE *cn)
{
    if(cn != NULL)
    {
        display(cn->lf);
        cout << "\n " << cn->data << "\n";
        display(cn->rt);
    }
}

int main()
{
    BST obj;
    NODE *temp;
    int choice;
    int key;

    do
    {
        cout << "\n ---------------------------------------- ";
        cout << "\n Enter your choice "
                "\n 1. Create Dictionary "
                "\n 2. Add new node "
                "\n 3. Search for a node "
                "\n 4. Delete a node "
                "\n 5. Display the tree "
                "\n 6. Exit "
                "\n Here : ";

        cin >> choice;

        switch(choice)
        {
            case 1: obj.createBinary();
                    break;

            case 2: obj.addNewNode();
                    break;

           case 3: cout << "\n Enter the data to be searched : ";
                   cin >> key;
                   temp = obj.search(obj.getroot(), key);
                   if(temp != NULL)
                      cout << "\n" << temp->data << "\n";
                   else
                      cout << "\n Data not found! " << "\n";
                   break;

           case 4: cout << "\n Enter the data to be deleted : ";
                   cin >> key;
                   obj.deletenode(key);
                   cout << "\n The data is deleted. ";
                   break;

           case 5: obj.display(obj.getroot());
                   break;

           default : cout << "\n ----------------- END ----------------- ";
                     break;
        }
    }while(choice < 10);

    return 0;
}
