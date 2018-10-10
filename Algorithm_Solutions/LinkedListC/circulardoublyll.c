#include<stdio.h>
#include<stdlib.h>

struct DNode {
    int info;
    struct DNode *next;
    struct DNode *prev;
};
typedef struct DNode DNODE;

DNODE *insertEnd(DNODE *head, int val) {
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = head;
    p->prev = NULL;
    if(head == NULL) {
        head = p;
        p->prev=p;
        p->next=p;
        return head;
    }
    DNODE *q = head;
    while(q->next != head) {
        q = q->next;
    }
    q->next = p;
    p->prev = q;
    return head;
}

DNODE *insertStart(DNODE *head, int val) {
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    if(head==NULL){
      p->next=p;
      p->prev=p;
      return p;
    }
    else{
      p->next = head;
      DNODE *q= head;
      while(q->next!=head){
        q=q->next;
      }
      p->prev = q;
      head = p;
      return head;
    }

}

DNODE *insertAfter(DNODE *head, int val, int key) {
    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
    }
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = q->next;
    q->next->prev = p;
    q->next = p;
    p->prev = q;
    return head;
}

DNODE *insertBefore(DNODE *head, int val, int key) {
    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
    }
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = q;
    p->prev = q->prev;
    q->prev = p;
    p->prev->next = p;
    return head;
}
DNODE *deletionS(DNODE *head){
  if(head == NULL) {
      printf("List is already empty.");
      return head;
  }
  DNODE *p = head;
  head->prev->next = head->next;
  head->next->prev = head->prev;
  head = head->next;
  p->next = p->prev = NULL;
  free(p);
  return head;
    }


DNODE *deletionE(DNODE *head){
  if (head==NULL){
    printf("List is empty");
  }
  DNODE *q = head->prev;
  q->prev->next = head;
  head->prev = q->prev;
  free(q);
  return head;
}

DNODE *deletion(DNODE *head, int key) {
    if(head == NULL) {
        printf("List is already empty.");
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
    }
    if(q->next == q) {
        free(q);
        return NULL;
    }
    q->prev->next = q->next;
    q->next->prev = q->prev;
    if(q==head)
        head = q->next;
    free(q);
    return head;
  }

void display(DNODE *head) {
    if(head == NULL) {
        printf("List is empty");
        return ;
    }
    DNODE *q = head;
    while(q->next!=head) {
        printf("%d \t", q->info);
        q = q->next;
    }
      printf("%d \t", q->info);
}

void main() {
    DNODE *head = NULL;
    int input,val,key;
    while(1) {
        printf("\n1. Create a doubly linked list.\n");
        printf("2. Insert an element at the start of the doubly linked list.\n");
        printf("3. Insert an element at the end of the doubly linked list.\n");
        printf("4. Insert an element before an existing element whose information is x in a doubly linked list.\n");
        printf("5. Insert an element after an existing element whose information is x in a doubly linked list.\n");
        printf("6. Delete the first element of the doubly linked list.\n");
        printf("7. Delete the last element of the doubly linked list.\n");
        printf("8. Delete the element whose information is x from a doubly linked list.\n");
        printf("9. Display list.\n");
        printf("10. quit.\n");
        printf("Enter your choice: ");
        scanf("%d",&input);
        switch(input) {
            case 1:
                printf("New list is created.\n");
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                head = insertStart(head,val);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                head = insertEnd(head,val);
                break;
            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("Enter key before you want to insert: ");
                scanf("%d", &key);
                head = insertBefore(head,val,key);
                break;
            case 5:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("Enter key after you want to insert: ");
                scanf("%d", &key);
                head = insertAfter(head,val,key);
                break;
            case 6:
                printf("Action performed");
                head = deletionS(head);
                break;
            case 7:
                printf("Action performed");
                head = deletionE(head);
                break;
            case 8:
                printf("Enter key which you want to delete: ");
                scanf("%d", &key);
                head = deletion(head,key);
                break;
            case 9:
                display(head);
                break;
            case 10:
                exit(1);
            default:
                printf("Enter number in between 1 to 10.\n");
        }
    }
}
