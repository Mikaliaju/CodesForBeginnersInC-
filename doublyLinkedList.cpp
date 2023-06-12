#include <iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};

class double_linked_list
{
    private:
    node *first;
    public:
    double_linked_list()
    {
        first = NULL;
    }
    bool is_empty()
    {
        return first == NULL;
    }
    void insert_first(int x)
    {
        node* temp = new node;
        temp->data = x;
        temp->next = first;
        temp->prev = NULL;
        if(first != NULL)
        first->prev = temp;
        first = temp;
    }
    void insert_last(int x)
    {
        node* temp = new node;
        temp->data = x;
        temp->next = NULL;
        node* ptr = new node;
        ptr = first;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if(ptr->next == NULL)
        {
            ptr->next = temp;
            temp->prev = ptr;
        }
    }
    void search(int x)
    {
        node* temp = new node;
        temp = first;
        int counter = 0;
        while(temp != NULL)
        {
            if(temp->data == x)
            {
                cout << counter << endl;
                break;
            }
            else
            {
                temp = temp->next;
                counter++;
            }
            if(temp == NULL)
            {
                cout << "element does not exist. ";
            }
        }
    }
    void insert_atindex(int c, int x)
    {
        node* temp = new node;
        temp->data = x;
        node* ptr = first;
        node* after = first->next;
        int counter = 0;
        while(after != NULL && counter != c - 1)
        {
            after = after->next;
            ptr = ptr->next;
            counter++;
        }
        if(c - 1 == counter)
        {
            temp->prev = ptr;
            ptr->next = temp;
            after->prev = temp;
            temp->next = after;
        }
    }
    void print_data()
    {
        node* temp = first;
        while(temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void delete_first()
    {
        node* temp = new node;
        temp = first;
        first = first->next;
        delete temp;
        first->prev = NULL;
    }
    void delete_last()
    {
        node* ptr = first;
        node* before;
        while(ptr->next != NULL)
        {
            before = ptr;
            ptr = ptr->next;
        }
        if(ptr->next == NULL)
        {
            before->next = NULL;
            delete ptr;
        }
    }
    void delete_atindex(int c)
    {
        int counter = 0;
        node* ptr = new node;
        ptr = first;
        node* after = ptr;
        node* before;
        while(counter != c)
        {
            before = ptr;
            ptr = ptr->next;
            after = ptr;
            counter++;
        }
        if(counter == c)
        {
            before->next = ptr->next;
            after->prev = ptr->prev;
            delete ptr;
        }
    }
};