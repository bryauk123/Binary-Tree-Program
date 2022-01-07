#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
        string name;
        int data;
        Node *left,*right; // left and right links
        Node()
        {
            left=right= 0;
        }

        Node(int data, string name, Node* l = 0, Node* r = 0)
        {
            this->data = data;
            this->name = name;
            left = l;
            right = r;
        }
};

class BinaryTree
{
    public:
        Node *root;

        BinaryTree()
        {
            root = 0;
        }

        bool addNode(int data, string name)
        {
            Node* newNode = new Node(data,name);
            if(root == 0)
            {
                root = newNode;
                return true;
            }

            Node* temp = root; //temp node to traverse list
            while(true)
            {
                if (data < temp->data) //traverse to left if data is less than roots data
                {
                    if(temp->left == 0)
                    {
                        temp->left = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if(data > temp->data) // traverse to right if data is greater than root data
                {
                    if(temp->right == 0)
                    {
                        temp->right = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else if(data == temp->data)
                {
                    return false; // no dupes
                }
            }
            return true;
        }

        void inOrderTraversal(Node* temp)
        {
            if(temp!= 0)
            {
                inOrderTraversal(temp->left);
                cout<<temp->name<<": "<<temp->data<<endl;
                inOrderTraversal(temp->right);
            }
        }

        void preOrderTraversal(Node* temp)
        {
            if(temp!=0)
            {
                cout<<temp->name<<": "<<temp->data<<endl;
                inOrderTraversal(temp->left);
                inOrderTraversal(temp->right);
            }
        }

        void postOrderTraversal(Node* temp)
        {
            if(temp!=0)
            {
                inOrderTraversal(temp->left);
                inOrderTraversal(temp->right);

                cout<<temp->name<<": "<<temp->data<<endl;
            }
        }

        int findLeaves(Node* temp)
        {
            if(temp == 0)
            {
                return 0;
            }
            if(temp->left == 0 && temp->right == 0)
            {
                return 1;
            }
            else
            {
                return findLeaves(temp->left) + findLeaves(temp->right);
            }
        }

        int findHeight(Node* root)
        {
            if(root == 0)
            {
                return 0;
            }
            else
            {
                int leftHeight = findHeight(root->left);
                int rightHeight = findHeight(root->right);

                if(leftHeight > rightHeight)
                {
                    return leftHeight + 1;
                }
                else
                {
                    return rightHeight +1;
                }
            }
        }

        Node* findPerson(Node* root,string name)
        {
            if(root == 0)
            {
                return nullptr;
            }
            if(root->name == name)
            {
                return root;
            }
            Node* temp = findPerson(root->left, name);
            if(temp != 0)
            {
                return temp;
            }
            return findPerson(root->right,name);
        }

        void lowestWeight(Node* root)
        {
            Node* temp = root;
            while(temp->left != 0)
            {
                temp = temp->left;
            }
            cout<<temp->name<<"'s weight is the lowest at: "<<temp->data<<endl; 
        }
};

int main(void)
{
    string userInput;
    string findPerson;
    int leafCount;
    Node* temp;
    BinaryTree tree;
    string name;
    int weight;
    cout<<"Enter weight and name associated with person, -1 to quit\n";
    for(int i = 0; i < 15; i++)
    {
        cin>>weight;
        if(weight == -1)
        {
            break;
        }
        cin>>name;
        if(name == "-1")
        {
            break;
        }
        tree.addNode(weight,name);
    }

    cout<<"-----------In Order-------------"<<endl;
    tree.inOrderTraversal(tree.root);
    cout<<"-----------Pre Order------------"<<endl;
    tree.preOrderTraversal(tree.root);
    cout<<"------------Post Order----------"<<endl;
    tree.postOrderTraversal(tree.root);
    cout<<"------------------------"<<endl;
    leafCount = tree.findLeaves(tree.root);
    cout<<"This tree has "<<leafCount<<" leaves"<<endl;

    cout<<"Would you like to look for someone? Y or N?\n";
    cin>>userInput;
    if(userInput == "Y")
    {
        cout<<"Great, who are you looking for?\n";
        cin>>findPerson;
        temp = tree.findPerson(tree.root,findPerson);
        cout<<temp->name<<"'s weight is: "<<temp->data<<endl;
    }
    tree.lowestWeight(tree.root);
    cout<<"Height of tree is "<<tree.findHeight(tree.root)<<endl;

    return 0;

    /*Enter weight and name associated with person, -1 to quit
299 Bryan
298 Shanni
100 Leslie
432 Scott
180 Irving
93 Cat
232 Jake
900 Steve
1500 Bob
-1
-----------In Order-------------
Cat: 93
Leslie: 100
Irving: 180
Jake: 232
Shanni: 298
Bryan: 299
Scott: 432
Steve: 900
Bob: 1500
-----------Pre Order------------
Bryan: 299
Cat: 93
Leslie: 100
Irving: 180
Jake: 232
Shanni: 298
Scott: 432
Steve: 900
Bob: 1500
------------Post Order----------
Cat: 93
Leslie: 100
Irving: 180
Jake: 232
Shanni: 298
Scott: 432
Steve: 900
Bob: 1500
Bryan: 299
------------------------
This tree has 3 leaves
Would you like to look for someone? Y or N?
Y
Great, who are you looking for?
Scott
Scott's weight is: 432
Cat's weight is the lowest at: 93
Height of tree is 5
*/
}
