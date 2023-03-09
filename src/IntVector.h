#ifndef INTVECTOR_H
#define INTVECTOR_H
#include<stddef.h>
typedef struct
{
	int *data;
	int size;
	int capacity;
	
} IntVector;

IntVector *int_vector_new(size_t initial_capacity);
IntVector *int_vector_copy(const IntVector *v);
void int_vector_free(IntVector *v);
int int_vector_get_item(const IntVector *v, size_t index);
size_t int_vector_get_size(const IntVector *v);
int int_vector_push_back(IntVector *v, int item);
#endif //INTVECTOR_H
