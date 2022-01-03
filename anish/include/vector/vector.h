#include "vector/models.h"

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

Vector *new_vector(void);
void resize(Vector *, unsigned int);
void set(Vector *, unsigned int, void *);
void *get(Vector *, unsigned int);
void append(Vector *, void *);
void clear(Vector *);
void delete(Vector *, unsigned int);

#endif //VECTOR_VECTOR_H
