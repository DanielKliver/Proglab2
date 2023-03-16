#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "IntVector.h"

int main()
{
	//Создаём вектор V
	printf("Enter the capacity of the array: ");
	size_t initial_capacity = 0;
	scanf("%zu", &initial_capacity);
	printf("\n");
	IntVector *v = int_vector_new(initial_capacity);
	printf("vector V = \ndata:%p\nsize:%d\ncapacity:%d\n", v->data, v->size, v->capacity);								
	//Копируем вектор V в вектор A
	IntVector *a = int_vector_copy(v);
	printf("\nvector A = \ndata:%p\nsize:%d\ncapacity:%d\n", a->data, a->size, a->capacity);
	
	//Добавляем элемент в конец вектора
	printf("\n\n");
	int item = 0;
	printf("What number to add to the end of the array?\n\n");
	printf("item: ");
	scanf("%d", &item);
	int_vector_push_back(v, item);
	printf("\n");
	
	//Выводим элемент номера index
	for (int i = 0; i < int_vector_get_size(v); i++)
	{
		printf("value number %d: %d\t", i, int_vector_get_item(v, i));
	}
	printf("\n");

	//Ёмкость вектора
	printf("Capacity = %ld\n", int_vector_get_capacity(v));

	//Размер вектора
	printf("Size = %ld\n", int_vector_get_size(v));

	//Удаляем последний элемент вектора
	int_vector_pop_back(v);

	//Сокращаем ёмкость вектора до его размера
	int_vector_shrink_to_fit(v);
	printf("Enter a new vector size: ");
	int new_size;
	scanf("%d", &new_size);
	int_vector_resize(v, new_size);
	printf("\n");

	//Увеличиваем ёмкость вектора
	printf("Enter a new vector capacity: ");
	int new_capacity;
	scanf("%d", &new_capacity);
	int_vector_reserve(v, new_capacity);
	printf("\n");

	//Освобождаем память, выделенную под вектор V
	int_vector_free(v);
	printf("vector V after free = \ndata:%p\nsize:%d\ncapacity:%d\n", v->data,v->size,v->capacity);
	return 0;
}
