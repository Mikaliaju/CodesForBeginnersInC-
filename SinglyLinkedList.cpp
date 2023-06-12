#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class linkedlist
{
    private:
    struct node* head;
    public:
    linkedlist()
    {
        head = NULL;
    }
    void insert_inFirst(int x)
    {
        node* temp;
        temp = new node;
        temp->data = x;
        temp->next = head; 
        head = temp;
    }
    void insert_afterindex(int x, int c)
    {
        node* temp = head;
        node* star = new node;
        star->data = x;
        int counter = 0;
        while(temp != NULL)
        {
            if(counter == c - 1)
            {
                star->next = temp->next;
                temp->next = star;
                break;
            }
            else
            {
            temp = temp->next;
            counter++;
            }
        }
    }
    void insert_inEnd(int x)
    {
        node* temp = new node;
        node* last = head;
        temp->data = x;
        temp->next = NULL;
        if(head == NULL)
        head = temp;
        else
        {
          while(last->next != NULL)
          {
            last = last->next;
          }
          last->next = temp;
        }
    }
    void Search(int x)
    {
         node* search = new node;
         search = head;
         int counter = 0;
         while(search != NULL)
         {
            if(search->data == x){
            cout << "Element index: ";
            cout << counter << "\t";
            cout << "element does exist. ";
            break;
            }
            else
            search = search->next;
            counter++;
         }
         if(search == NULL)
         cout << "element does not exist. ";
    }
    void delete_fromFirst()
    {
        node* temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    void delete_fromEnd()
    {
        node* last = new node;
        node* pre_last = new node;
        last = head;
        pre_last = head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        while(pre_last->next != last)
        {
            pre_last = pre_last->next;
        }
        pre_last->next = NULL;
        delete last;
    }
    void delete_fromIndex(int c)
    {
        int counter = 0;
        node* ptr = head;
        node* pre_ptr;
        while(counter != c)
        {
            pre_ptr = ptr;
            ptr = ptr->next;
            counter++;
        }
        if(counter == c)
        {
            pre_ptr->next = ptr->next;
            delete ptr;

        }
    }
    void print_list()
    {
        node* temp = new node;
        temp = head;
        while(temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};