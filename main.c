#include <stdio.h>
#include <stdlib.h>
#include "vector/vector.h"

int main() {
    Vector *v1 = new_vector();
    v1->append(v1, "Bonjour");
    for (int i = 0; i < v1->length; i++)
        printf("%s ", (char *) v1->get(v1, i));
    printf("\n");
    Vector *v2 = new_vector();
//    this is kind of ugly, but I don't really see a better way
    for (int i = 0; i < 111; i++) {
        int *j = malloc(sizeof(int));
        (*j) = i;
        v2->append(v2, j);
    }
    for (int i = 0; i < 111; i++) {
        printf("%d\n", *(int *) v2->items[i]);
    }
    return 0;
}
