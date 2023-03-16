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
//Получает на вход указатель на массив, индекс элемента и значение, на которое нужно произвести замену
void int_vector_set_item(IntVector *v, size_t index, int item)
{
	if (index <= v->capacity)
		v->data[index] = item;
	v->size++;
}
//
//Выводит обьём вектора
size_t int_vector_get_capacity(const IntVector *v)
{
	return v->capacity;
}
//
void int_vector_pop_back(IntVector *v)
{
	if (v->size != 0) 
		v->size--;
}
//
int int_vector_shrink_to_fit(IntVector *v)
{
	if (v->size < v->capacity)
	{
		v->capacity = v->size;
		int *t = realloc(v->data, v->capacity * sizeof(int));
		if (t == NULL)
		{
			return -1;
		}
		v->data = t;
		return 0;
	}
	return -1;
}
//
int int_vector_resize(IntVector *v, size_t new_size)
{
	if (new_size == v->size)
		return 0;
	if (new_size > v->size) {

		int *t = realloc(v->data, new_size * sizeof(int));
		if (t == NULL)
		{
			return -1;
		}
		v->data = t;
		for (int i = v->size; i < new_size; i++)
			v->data[i] = 0;
	}
	v->size = new_size;
	return 0;	
}
int int_vector_reserve(IntVector *v, size_t new_capacity)
{
	if (new_capacity > v->capacity) {
		v->capacity = new_capacity;
		int *t = realloc(v->data, new_capacity * sizeof(int));
		if (t == NULL)
			return -1;
		v->data = t;
		return 0;
	}
	return -1;
}
