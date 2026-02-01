#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coef, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insert(result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, c, e;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        poly1 = insert(poly1, c, e);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        poly2 = insert(poly2, c, e);
    }

    result = addPoly(poly1, poly2);

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}