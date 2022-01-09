#include <iostream>

using namespace std;
struct node
{
    int info;
    int leftbit;
    int rightbit;
    node *left;
    node *right;
};
class threaded
{
public:
    node *root,*dummy,*temp2,*insist,*temp1;
    threaded()
    {
        dummy=new node;
        dummy->right=dummy;
        dummy->left=NULL;
        dummy->rightbit=1;
        dummy->leftbit=0;
        dummy->info=-4000;
        root=temp2=NULL;
    }
    void insertion(int key,node *temp)
    {
        if(root==NULL)
        {
            root=new node;
            root->info=key;
            dummy->left=root;
            dummy->leftbit=1;
            root->right=root->left=dummy;
            root->rightbit=root->leftbit=0;
            return;
        }
        if(key<temp->info)
        {
            if(temp->leftbit!=0)
            {
                insertion(key,temp->left);
            }
            else
            {
                temp2=new node;
                temp2->info=key;
                temp2->left=temp->left;
                temp->left=temp2;
                temp2->leftbit=temp->leftbit;
                temp->leftbit=1;
                temp2->right=temp;
                temp2->rightbit=0;
                return;


            }
        }
        if(key>temp->info)
        {
            if(temp->rightbit!=0)
            {
                insertion(key,temp->right);
            }
            else
            {
                temp2=new node;
                temp2->info=key;
                temp2->rightbit=temp->rightbit;
                temp2->right=temp->right;
                temp2->left=temp;
                temp2->leftbit=0;
                temp->right=temp2;
                temp->rightbit=1;
                return;
            }
        }
    }
    void in_order(node *temp)
    {
        if(root==NULL)
        {
            return;
        }
        if(temp->leftbit!=0)
        {
            in_order(temp->left);
        }
        cout<<temp->info<<"   ";
        if(temp->rightbit!=0)
        {
            in_order(temp->right);
        }
    }



    void deletion(int key,node *temp)
    {
       /* if(temp==root && root->info==key)
        {
            if(root->leftbit==0 && root->rightbit==0)
            {
                delete root;
                root= NULL;
                dummy->left=dummy;
                dummy->leftbit=0;
                return;

            }
            if(root->leftbit==1 && root->rightbit==0)
            {
                temp2=root;
                root->left->right=root->right;
                root->left->rightbit=root->rightbit;
                dummy->left=root->left;
                root=root->left;
                delete temp2;
                temp2=NULL;
                return;
            }
            if(root->rightbit==1 && root->leftbit==0)
            {
                temp2=root;
                root->right->left=root->left;
                root->right->leftbit=root->leftbit;
                dummy->left=root->right;
                root=root->right;
                delete temp2;
                temp2=NULL;
                return;
            }
        }
    }*/
    if(root==NULL)
    {
        cout<<"Khali hai "<<endl;
        return;
    }
    if(temp->left->info==key)
    {
        Delete_Node(temp->left,temp);
        return;
    }
    if (temp!=dummy && temp->right->info==key)
    {
        Delete_Node(temp->right,temp);
        return;
    }
    if(temp==dummy)
    {
        deletion(key,temp->left);
        return;
    }



    if(key<temp->info && temp->leftbit==1)
    {
        deletion(key,temp->left);
        return;
    }
    if(key>temp->info)
    {
        deletion(key,temp->right);
        return;
    }
    cout<<"Value doesnt exist"<<endl;
    return;
}
void Delete_Node(node *temp,node *parent)
{
    if(temp->leftbit==1 && temp->rightbit==1)
    {
        node *successor_parent=temp;
        node *successor=Find_successor(temp->right,successor_parent);
        temp->info=successor->info;
        Delete_Node(successor,successor_parent);
        return;
    }
    if(temp->leftbit==1 && temp->rightbit==0)
    {
        /*parent->left=temp->left;
        parent->leftbit=temp->leftbit;
        if(temp->left->rightbit==1)
        {
            node *temp2=temp->left->right;
            while(temp2->right!=temp)
            {
                temp2=temp2->right;

            }
            temp2->right=temp->right;
        }
        else
        {
            temp->left->right=temp->right;
        }
        delete temp;*/
        if(temp->info<parent->info)
        {
            parent->left=temp->left;
            parent->leftbit=temp->leftbit;
        }
        else
        {
            parent->right=temp->left;
            parent->rightbit=temp->leftbit;
        }
        node *temp2=temp->left;
        while(temp2->rightbit!=0)
        {
            temp2=temp2->right;
        }
        temp2->right=temp->right;
        delete temp;
        return;

    }
    if(temp->rightbit==1 && temp->leftbit==0)
    {
        /*parent->right=temp->right;
        parent->rightbit=temp->rightbit;
        if(temp->right->leftbit==1)
        {
            node *temp2=temp->right->left;
            while(temp2->left!=temp)
            {
                temp2=temp2->left;

            }
            temp2->left=temp->left;
        }
        else
        {
            temp->right->left=temp->left;
        }
        delete temp;*/
        if(temp->info>parent->info)
        {
            parent->right=temp->right;
            parent->rightbit=temp->rightbit;
        }
        else
        {
            parent->left=temp->right;
            parent->leftbit=temp->rightbit;
        }
        node *temp2=temp->right;
        while(temp2->leftbit!=0)
        {
            temp2=temp2->left;
        }
        temp2->left=temp->left;
        delete temp;
        return;
    }
    if(temp->leftbit==0 && temp->rightbit==0)
    {
        if(parent->left==temp)
        {
            parent->left=temp->left;
            parent->leftbit=0;
        }
        if(parent->right==temp && parent!=dummy)
        {
            parent->right=temp->right;
            parent->rightbit=0;
        }
        if(temp==root)
        {
            root=NULL;
            dummy->left=dummy;
            dummy->leftbit=0;
        }
        delete temp;
    }
}
node *Find_successor(node *temp,node *&parent)
{
    if(temp->leftbit==0)
    {
        return temp;
    }
    parent=temp;
    return Find_successor(temp->left,parent);
}
};

int main()
{
    threaded t1;
    t1.insertion(6,t1.root);
    t1.insertion(8,t1.root);
    t1.insertion(7,t1.root);
    t1.insertion(11,t1.root);
    t1.insertion(9,t1.root);
    t1.insertion(13,t1.root);
    t1.insertion(3,t1.root);
    t1.insertion(5,t1.root);
    t1.insertion(1,t1.root);
    t1.in_order(t1.root);
    t1.deletion(13,t1.dummy);


    cout<<endl;
    t1.in_order(t1.root);
    //cout<<t1.searchtree(100,t1.root)<<endl;
    //node *temp9=t1.findsucessor(110);
    //cout<<temp9->info;



}
