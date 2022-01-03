#include "vector/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void resize(Vector *self, unsigned int capacity) {
    void **data = realloc(self->items, sizeof(void *) * capacity);
    if (data) {
        self->items = data;
        self->capacity = capacity;
    }
}

void append(Vector *self, void *item) {
    if (self->length == self->capacity) {
        self->resize(self, (unsigned int) (ceil((float) self->capacity * 1.25)));
    }
    self->items[self->length++] = item;
}

void set(Vector *self, unsigned int index, void *item) {
    if (self->length >= index) self->items[index] = item;
}

void *get(Vector *self, unsigned int index) {
    if (self->length >= index) return self->items[index];
    return NULL;
}

void delete(Vector *self, unsigned int index) {
    if (index > self->length) return;
    self->items[index] = NULL;
    for (unsigned int i = index; i < self->length; i++) {
        self->items[i] = self->items[i + 1];
        self->items[i] = NULL;
    }
    self->length--;
    if (self->length < self->capacity / 4) self->resize(self, self->capacity / 2);
}

void clear(Vector *self) {
    free(self->items);
}

Vector *new_vector() {
    Vector *new_vector = malloc(sizeof(Vector));
    new_vector->capacity = 50;
    new_vector->length = 0;
    new_vector->items = malloc(sizeof(void *) * new_vector->capacity);
    new_vector->clear = clear;
    new_vector->resize = resize;
    new_vector->append = append;
    new_vector->delete = delete;
    new_vector->set = set;
    new_vector->get = get;
    return new_vector;
}