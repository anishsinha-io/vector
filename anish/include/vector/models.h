#ifndef VECTOR_MODELS_H
#define VECTOR_MODELS_H

typedef struct Vector {
    unsigned int length;
    unsigned int capacity;
    void **items;
    void (*append)(struct Vector *, void *);
    void (*set)(struct Vector *, unsigned int, void *);
    void *(*get)(struct Vector *, unsigned int);
    void (*delete)(struct Vector *, unsigned int);
    void (*clear)(struct Vector *);
    void (*resize)(struct Vector *, unsigned int);
} Vector;

#endif //VECTOR_MODELS_H
