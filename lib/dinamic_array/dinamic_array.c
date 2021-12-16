#include "dinamic_array.h"

#include <malloc.h>
#include <assert.h>

struct array {
  unsigned int capacity;
  unsigned int size;
  void *data_ptrs[];
};

/**
 * Create completely new array.
 */
Array create_array(){
  Array arr = calloc(1, sizeof(array) + 8 * sizeof(void *));
  arr->capacity = 8;
  return arr;
}

/**
 * Add element to the back of the array.
 *
 * array: The array where we want to save the element.
 * ptr:   The pointer to the element.
 */
void add_element(Array array, void *ptr){
  if (array->capacity == array.size){
    // increase size
    array->capacity *= 2;
    array = realloc(array, sizeof(array) + array->capacity * sizeof(void *));
  }
  array->data_ptrs[array->size] = ptr;
  array->size++;
}

/**
 * Insert element at the given index into the array.
 *
 * array: The array where we want to save the element.
 * ptr:   The pointer to the element.
 */
void insert_element(Array array, void *ptr, unsigned int pos){
  assert(pos <= array.size());
  if (array->capacity == array.size){
    // increase size
    array->capacity *= 2;
    array = realloc(array, sizeof(array) + array->capacity * sizeof(void *));
  }
  array->size++;
  void *tmp;
  while (pos < array->size) {
    tmp = array->data_ptrs[pos];
    array->data_ptrs[pos] = ptr;
    ptr = tmp;
    pos++;
  }
}

/**
 * Return pointer to element at given index.
 *
 * array: The array where the element is stored.
 * pos:   The index to be retrieved.
 *
 * Returns the pointer to the element at the given index.
 */
void *get_element(Array array, unsigned int pos){
  assert(pos < array.size());
  return array->data_ptrs[pos];
}

/**
 * Remove element at the back from the array.
 *
 * array: The array we want to remove the element from.
 *
 * Returns the pointer to the element stored at the back.
 */
void *pop_element(Array array){
  assert(array->size > 0);
  array->size--;
  void *tmp = array->data_ptrs[array->size];

  if (array->size * 4 < array->capacity){
    array->capacity /= 2;
    array = realloc(array, sizeof(array) + array->capacity * sizeof(void *));
  }

  return tmp;
}

/**
 * Remove element at the back from the array.
 *
 * array: The array we want to remove the element from.
 * pos:   The position we want to remove.
 *
 * Returns the pointer to the element stored at the position.
 */
void *remove_element(Array array, unsigned int pos){
  assert(array->size > 0);
  assert(pos < array->size);

  array->size--;
  void *tmp = array->data_ptrs[pos];

  while (pos < array->size) {
    array->data_ptrs[pos] = array->data_ptrs[pos + 1];
    pos++;
  }

  if (array->size * 4 < array->capacity){
    array->capacity /= 2;
    array = realloc(array, sizeof(array) + array->capacity * sizeof(void *));
  }

  return tmp;
}

/**
 * Deletes and deallocates the whole array.
 *
 * array:          The array to delete.
 * delete_element: Function to fully deallocate stored elements.
 *                 If null, pointers will be simply freed.
 */
void delete_array(Array array, void (*delete_element)(void *)){
  for (unsigned int i = 0; i < array->size; i++){
    if (delete_element == 0){
      free(array->data_ptrs[i]);
    }
    else {
      delete_element(array->data_ptrs[i]);
    }
  }
  free(array);
}
