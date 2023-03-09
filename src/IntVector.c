#include "IntVector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
/*Создаёт массив нулевого размера.
  Принимает на вход ёмкость типа size_t
  Если не удаётся выделить память, возвращает NULL*/
IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *t = malloc(sizeof(IntVector));
	if (t == NULL)
	{
		return NULL;
	}
	t->data = malloc(initial_capacity * sizeof(int));
	if(t->data == NULL)
	{
		free(t);
		return NULL;
	}
	t->size = 0;
	t->capacity = initial_capacity;
	return t;
}
//
//Копируем вектор V в вектор T
//memcpy работает от заголовочного файла string.h
//Первый аргумент - куда копируем, второй - что, третий - сколько
IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *t = malloc(sizeof(IntVector));
	if (t == NULL)
		return NULL;
	t->data = malloc(v->capacity * sizeof(int));
	if (t->data == NULL) {
		free(t);
		return NULL;
	}
	memcpy(t->data, v->data, sizeof(int) * v->capacity);
	t->size = v->size;
	t->capacity = v->capacity;
	return t;
}
//
//Добавляет элемент в конец массива
int int_vector_push_back(IntVector *v, int item)
{
	if (v->size < v->capacity){
		v->data[v->size] = item;
		v->size++;
	}
	else {
		v->capacity *= 2;

		int *t = realloc(v->data, v->capacity * sizeof(int));
		if (t == NULL)
			return -1;
		v->data = t;
		v->data[v->size] = item;
		v->size++;
	}
	return 0;
}
//
//Возвращает индекс элемента массива
int int_vector_get_item(const IntVector *v, size_t index)
{
	return v->data[index];
}
//
//ВНИМАНИЕ: я использую тут функцию вычисления размера вектора:
size_t int_vector_get_size(const IntVector *v)
{
	return v->size;
}
//
//Очищает память вектора V
//Освобождает и структуру, и массив
void int_vector_free(IntVector *v)
{
	free(v->data);
	free(v);
}
//

