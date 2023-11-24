#include<iostream>
#include<cstring>
using namespace std;

struct Node
{
    int dt;
    Node *nxt;
};

class Nodes
{
private:
    Node *head = NULL;

public:
    void insert_end(int d)
    {
        Node *n = new Node;
        n->dt = d;
        n->nxt = NULL;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *temp;
            temp = head;
            while (temp->nxt != NULL)
            {
                temp = temp->nxt;
            }
            temp->nxt = n;
        }
    }

    void display()
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->dt << "\t";
            temp = temp->nxt;
        }
    }

    void insert_beg(int d)
    {
        Node *temp = new Node;
        temp->dt = d;
        temp->nxt = head;
        head = temp;
    }

    void insert_pos(int d)
    {
        int pos;
        cout << "Enter Data to insert after it:";
        cin >> pos;
        Node *temp = new Node;
        temp = head;
        Node *temp1 = new Node;
        temp->dt = d;
        temp->nxt = NULL;
        while (temp->dt != pos)
        {
            temp = temp->nxt;
        }
        temp1->nxt = temp->nxt;
        temp->nxt = temp1;
    }

    void del(int d)
    {
        Node *temp = new Node;
        Node *temp1 = new Node;
        temp = head;
        if (temp->dt == d)
        {
            temp->nxt = head;
            delete temp;
        }
        else
        {
            while (temp->nxt != NULL)
            {
                temp1 = temp;
                temp = temp->nxt;
                if (temp->dt == d)
                {
                    temp1->nxt = temp->nxt;
                    delete temp;
                    return;
                }
            }
            cout << "Element not found";
        }
    }

    void reverseDisplay()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->nxt;
            current->nxt = prev;
            prev = current;
            current = next;
        }
        head = prev;
        display();
        while (head != NULL)
        {
            next = head->nxt;
            head->nxt = current;
            current = head;
            head = next;
        }
        head = current;
    }
};

int main()
{
    Nodes n1;
    n1.insert_end(1);
    n1.insert_end(4);
    n1.insert_end(6);
    n1.insert_end(15);
    n1.display();
    cout << "\n";
    n1.reverseDisplay();
    cout << "\n";
    n1.del(8);
    n1.display();
    return 0;
}