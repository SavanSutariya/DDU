// To print Linked List

#include<bits/stdc++.h>
using namespace std;

class node{
   public:
   int data;
   node* next;
};

void printList(node* n){
    while(n != NULL){
        cout<<n->data<<->;
        n = n->next;
    }
    cout<<"NULL";
}

int main()
{
    node* head, *second, *third;
    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    return 0;
}

//************************************************************
// insertion of node.

#include<bits/stdc++.h>
using namespace std;

class node{
   public:
   int data;
   node* next;
};

// inserts a new node on the front of the list.
void push(node *&head_ref, int new_data)
{
    /* 1. allocate node */
    node *new_node = new node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = head_ref;

    /* 4. move the head to point to the new node */
    head_ref = new_node;
}

// inserts a new node on the end of the list.
void tailInsertion(node *&head, int val)
{
    node *n = new node();
    n->data = val;

    node *last = head;

    if (head == NULL)
    {
        n->next = NULL;
        head = n;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
    n->next = NULL;
}

// inserts a new node on at given node of the list.
void insertAfter(node *prev_node, int new_data)
{

    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. Allocate new node
    node *new_node = new node();

    // 3. Put in the data
    new_node->data = new_data;

    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next;

    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}

void printList(node* n){
    while(n != NULL){
        cout<<n->data<<"->";
        n = n->next;
    }
    cout<<"NULL";
}

int main()
{
    node* head, *second, *third;
    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    push(head, 4);
    printList(head);

    // int arr[] = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < 6; i++)
    // {
    //     tailInsertion(head, arr[i]);
    // }
    // printList(head);

    // insertAfter(second, 4);
    // printList(head);
    return 0;
}

//**************************************************************************
// To delete a node

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL";
}

void deletion(node *&head, int key)
{
    node *temp = head;
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp->next != NULL && temp->next->data != key)
        {
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
    }
}

int main()
{
    node *head, *second, *third;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printList(head);
    deletion(head, 3);
    cout << endl;
    printList(head);
    return 0;
}

//**************************************************************************
//To change the value of Node (Updation)

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void headInsertion(node *&ref, int val)
{
    node *n = new node();
    n->data = val;
    n->next = ref;
    ref = n;
}

void change(node *&ref, int key, int val)
{
    node *temp = ref;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            temp->data = val;
        }
        temp = temp->next;
    }
}

void print(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
int main()
{
    node *head = NULL;
    headInsertion(head, 1);
    headInsertion(head, 2);
    headInsertion(head, 3);
    headInsertion(head, 4);
    headInsertion(head, 5);
    print(head);
    cout << endl;
    change(head, 3, 0);
    print(head);
    return 0;
}

//********************************************************************
//To search a node

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL";
}

int main()
{
    node *head, *second, *third;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printList(head);
    cout << endl;
    cout << search(head, 3) << endl;
    return 0;
}

//********************************************************************
// Reverse a Linkedlist

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void headInsertion(node *&ref, int val)
{
    node *n = new node();
    n->data = val;
    n->next = ref;
    ref = n;
}

// Recursive Method
node *recurReverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = recurReverse(head->next);
    {
        head->next->next = head;
    }
    head->next = NULL;
    return newhead;
}

// Iterative method
node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void print(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
int main()
{
    node *head = NULL;
    headInsertion(head, 1);
    headInsertion(head, 2);
    headInsertion(head, 3);
    headInsertion(head, 4);
    headInsertion(head, 5);
    print(head);
    cout << endl;
    print(reverse(head));
    // print(recurReverse(head));
    cout << endl;
    return 0;
}

//***********************************************************************
//Reverse K node

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void headInsertion(node *&ref, int val)
{
    node *n = new node();
    n->data = val;
    n->next = ref;
    ref = n;
}

node *reverseK(node *&ref, int k)
{
    node *prevptr = NULL;
    node *currptr = ref;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        ref->next = reverseK(nextptr, k);
    }

    return prevptr;
}

void print(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    node *head = NULL;
    headInsertion(head, 9);
    headInsertion(head, 8);
    headInsertion(head, 7);
    headInsertion(head, 6);
    headInsertion(head, 5);
    headInsertion(head, 4);
    headInsertion(head, 3);
    headInsertion(head, 2);
    headInsertion(head, 1);
    print(head);
    cout << endl;
    print(reverseK(head, 3));
    return 0;
}

//************************************************************************
//Length of Linkedlist

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

// inserts a new node on the end of the list.
void tailInsertion(node *&head, int val)
{
    node *n = new node();
    n->data = val;

    node *last = head;

    if (head == NULL)
    {
        n->next = head;
        head = n;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
    n->next = NULL;
}

void display(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int count(node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count(head->next);
    }
}

int main()
{
    node *head = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        tailInsertion(head, arr[i]);
    }
    display(head);
    cout << count(head) << endl;
    return 0;
}

//**************************************************************************
// Cycle Detection in Linkedlist

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

// To make cycle in Linkedlist
void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *cyclepoint;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cyclepoint = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cyclepoint;
}

bool detect(node *&head) // Floyd's Algorithm or Hare and tortoise algorithm
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// to remove cycle present in linkedlist
void removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void headInsertion(node *&ref, int val)
{
    node *n = new node();
    n->data = val;
    n->next = ref;
    ref = n;
}

void print(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    node *head = NULL;
    headInsertion(head, 9);
    headInsertion(head, 8);
    headInsertion(head, 7);
    headInsertion(head, 6);
    headInsertion(head, 5);
    headInsertion(head, 4);
    headInsertion(head, 3);
    headInsertion(head, 2);
    headInsertion(head, 1);

    print(head);
    cout << endl;
    makecycle(head, 5);

    cout << detect(head);
    cout << endl;

    removecycle(head);
    cout << detect(head);

    cout << endl;
    print(head);

    return 0;
}

//**************************************************************************
// Merge Linkedlist

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

// inserts a new node on the end of the list.
void tailInsertion(node *&head, int val)
{
    node *n = new node();
    n->data = val;

    node *last = head;

    if (head == NULL)
    {
        n->next = head;
        head = n;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
    n->next = NULL;
}

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

node *merge(node *&head1, node *&head2)
{
    node *pt1 = head1;
    node *pt2 = head2;
    node *initial = new node();
    
    node *pt3 = initial;

    while (pt1 != NULL && pt2 != NULL)
    {
        if (pt1->data > pt2->data)
        {
            pt3->next = pt2;
            pt2 = pt2->next;
        }
        else
        {
            pt3->next = pt1;
            pt1 = pt1->next;
        }
        pt3 = pt3->next;
    }

    while (pt1 != NULL)
    {
        pt3->next = pt1;
        pt1 = pt1->next;
        pt3 = pt3->next;
    }
    while (pt2 != NULL)
    {
        pt3->next = pt2;
        pt2 = pt2->next;
        pt3 = pt3->next;
    }
    return initial->next;
}

int main()
{
    node *head1 = NULL;

    int arr1[] = {1, 3, 5, 7};
    for (int i = 0; i < 4; i++)
    {
        tailInsertion(head1, arr1[i]);
    }
    node *head2 = NULL;

    int arr2[] = {2, 4, 6};
    for (int i = 0; i < 3; i++)
    {
        tailInsertion(head2, arr2[i]);
    }
    printList(head1);
    printList(head2);
    node *a = merge(head1, head2);
    printList(a);
    return 0;
}

//****************************************************************
// Append K node

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;

    head = n;
}

void insertAttail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}

int length(node *&head)
{
    node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

node *append(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;
    int l = length(head);
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    tail->next = head;
    newtail->next = NULL;
    return newhead;
}

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAttail(head, arr[i]);
    }
    printList(head);
    // append(head, 3);
    printList(append(head, 3));
    return 0;
}


//************************************************************************
// Intersection of two linkedlist

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void inserthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;

    head = n;
}

void insertAttail(node *&head, int val)
{
    if (head == NULL)
    {
        inserthead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}

int length(node *&head)
{
    node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

// to find the intersection node first we have to make two linkedlist intersect with eachother.
int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;

    if (l2 > l1)
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    else
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAttail(head, arr[i]);
    }
    printList(head);

    return 0;
}

//************************************************************************
// Even and odd nodes in a Linked List

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

// inserts a new node on the end of the list.
void tailInsertion(node *&head, int val)
{
    node *n = new node();
    n->data = val;

    node *last = head;

    if (head == NULL)
    {
        n->next = head;
        head = n;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
    n->next = NULL;
}

void display(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void OddafterEven(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenstart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}

int main()
{
    node *head = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        tailInsertion(head, arr[i]);
    }
    display(head);
    OddafterEven(head);
    display(head);
    return 0;
}

//************************************************************************
// Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void inserthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

void insertAttail(node *&head, int val)
{
    if (head == NULL)
    {
        inserthead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletenode(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteathead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int main()
{
    node *head = NULL;
    insertAttail(head, 2);
    insertAttail(head, 3);
    insertAttail(head, 4);
    insertAttail(head, 5);
    // display(head);
    inserthead(head, 1);
    display(head);
    deletenode(head, 5);
    display(head);
    deletenode(head, 1);
    display(head);
    return 0;
}