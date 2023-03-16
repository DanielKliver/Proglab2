#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "IntVector.h"

int main()
{

	//Готовим параметр на вход первой функции
	printf("Введите ёмкость массива: ");
	size_t initial_capacity = 0;
	scanf("%zu", &initial_capacity);
	printf("\n");
	//Создаём вектор V
	IntVector *v = int_vector_new(initial_capacity);
	printf("vector V = \ndata:%p\nsize:%d\ncapacity:%d\n", v->data, v->size, v->capacity);
	//
	//Копируем вектор V в вектор A
	IntVector *a = int_vector_copy(v);
	printf("\nvector A = \ndata:%p\nsize:%d\ncapacity:%d\n", a->data, a->size, a->capacity);
	for (int i = 0; i < v->size; i++) 
	{
		printf("%d\t", a->data[i]);
	}
	//
	//Добавляю элемент в конец массива
	printf("\n\n");
	int item = 0;
	printf("What number to add to the end of the array?\n\n");
	printf("Число: ");
	scanf("%d", &item);
	int_vector_push_back(v, item);
	printf("\n\n");
	//
	//Выводим элемент номера index
	//Попутно вычисляя вычисляя размер вектора
	for (int i = 0; i < int_vector_get_size(v); i++)
	{
		printf("index[i]:%d\t", int_vector_get_item(v, i));
	}
	//
	printf("\n\n");
	printf("Capacity = %ld\n", int_vector_get_capacity(v));
	int_vector_get_size(v);
	int_vector_pop_back(v);
	int_vector_shrink_to_fit(v);
	printf("Введите новый размер вектора: ");
	int new_size;
	scanf("%d", &new_size);
	int_vector_resize(v, new_size);
	printf("\n");
	printf("Введите новую ёмкость вектора: ");
	int new_capacity;
	scanf("%d", &new_capacity);
	int_vector_reserve(v, new_capacity);
        printf("\n");
	//Освобождаем память, выделенную под вектор V
	int_vector_free(v);
	printf("vector V after free = \ndata:%p\nsize:%d\ncapacity:%d\n", v->data,v->size,v->capacity);	
	//
	return 0;
}
