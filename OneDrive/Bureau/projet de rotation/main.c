#include <stdio.h>
#include <stdlib.h>

// D�finition de la structure d'un n�ud dans la liste cha�n�e
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour ajouter un n�ud � la fin de la liste cha�n�e
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Fonction pour afficher la liste cha�n�e
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Fonction pour faire pivoter la liste cha�n�e vers la droite par k �l�ments
void rotateRight(Node** head_ref, int k) {
    int count ;
     Node* current;
      Node* kthNode;
    if (k == 0)
        return;

    count = 1;
    current = *head_ref;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

   kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

// Fonction pour faire pivoter la liste cha�n�e vers la gauche par k �l�ments
void rotateLeft(Node** head_ref, int k) {
   int count;
   Node* current;
   Node* kthNode;
    if (k == 0)
        return;

    count = 1;
    current = *head_ref;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

int main() {
    Node* head = NULL;
    int n, i, data, k;

    printf("Entrez le nombre d'�l�ments de la liste : ");
    scanf("%d", &n);

    printf("Entrez les �l�ments de la liste : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Entrez la valeur de k pour la rotation : ");
    scanf("%d", &k);

    printf("Liste originale : ");
    printList(head);

    if (k > 0) {
        rotateRight(&head, k);
        printf("Liste apr�s rotation vers la droite par %d �l�ments : ", k);
    } else if (k < 0) {
        rotateLeft(&head, -k);
        printf("Liste apr�s rotation vers la gauche par %d �l�ments : ", -k);
    } else {
        printf("La liste reste inchang�e.");
    }

    printList(head);

    return 0;
}
