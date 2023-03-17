#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ll long long int

const ll mod=1e9+7;

typedef struct linked_list {
    ll data;
    struct linked_list *next;
} linked_list;

linked_list* add(ll data, linked_list* head);
void print(linked_list* head);
ll middle_element(linked_list* head);
linked_list* delete_middle(linked_list* head);
linked_list* delete_linked_list(linked_list* head);
void print_reverse(linked_list* head);
linked_list* reverse_linked_list(linked_list* head);
bool is_palindrome(linked_list** left, linked_list* right);
linked_list* remove_duplicate_sorted(linked_list* head);
linked_list* remove_duplicate_unsorted(linked_list* head);
bool detect_loop(linked_list* head);
linked_list* remove_loop(linked_list* head);
ll intersection_point(linked_list* head1, linked_list* head2);
linked_list* odd_even(linked_list* head);

linked_list* add(ll data, linked_list* head) {
    // CASE:1
    if (head == NULL) {
        linked_list *temp = (linked_list*)malloc(sizeof(linked_list));
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else {
        // CASE:2
        linked_list *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (linked_list*)malloc(sizeof(linked_list));
        temp->next->data = data;
        temp->next->next = NULL;
    }
    return head;
}

void print(linked_list* head) {
    linked_list* temp = head;
    while (temp != NULL) {
        printf("%lld ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

ll middle_element(linked_list* head) {
    linked_list *sp = head, *fp = head;
    while (fp != NULL && fp->next != NULL) {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp->data;
}

linked_list* delete_middle(linked_list* head) {
    linked_list *sp = head, *fp = head;
    linked_list* pre = sp;
    while (fp != NULL && fp->next != NULL) {
        pre = sp;
        sp = sp->next;
        fp = fp->next->next;
    }
    pre->next = sp->next;
    free(sp);
    return head;
}

linked_list* delete_linked_list(linked_list* head) {
    linked_list* pre = head;
    head = head->next;
    if (head == NULL) {
        free(pre);
    }
    while (head != NULL) {
        free(pre);
        pre = head;
        head = head->next;
    }
    return head;
}

void print_reverse(linked_list* head) {
    if (head == NULL)
        return;
    print_reverse(head->next);
    printf("%lld ", head->data);
}

linked_list* reverse_linked_list(linked_list* head) {
    linked_list* prev = NULL;
    linked_list* curr = head;
    linked_list* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Check if a linked list is a palindrome
bool is_palindrome(linked_list** left, linked_list* right) {
    if (right == NULL) {
        return true;
    }

    bool is_palin = is_palindrome(left, right->next);

    if (!is_palin) {
        return false;
    }

    is_palin = ((*left)->data == right->data);

    *left = (*left)->next;

    return is_palin;
}

// Remove duplicates from a sorted linked list
linked_list* remove_duplicate_sorted(linked_list* head) {
    if (head == NULL) {
        return NULL;
    }

    linked_list* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            linked_list* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

// Remove duplicates from an unsorted linked list
linked_list* remove_duplicate_unsorted(linked_list* head) {
    if (head == NULL) {
        return NULL;
    }

    linked_list* curr = head;
    while (curr != NULL) {
        linked_list* inner_curr = curr;
        while (inner_curr->next != NULL) {
            if (curr->data == inner_curr->next->data) {
                linked_list* temp = inner_curr->next;
                inner_curr->next = inner_curr->next->next;
                free(temp);
            } else {
                inner_curr = inner_curr->next;
            }
        }
        curr = curr->next;
    }

    return head;
}
