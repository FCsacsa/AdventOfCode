typedef struct array *Array;

/**
 * Create completely new array.
 */
Array create_array();

/**
 * Add element to the back of the array.
 *
 * array: The array where we want to save the element.
 * ptr:   The pointer to the element.
 */
void add_element(Array array, void *ptr);

/**
 * Insert element at the given index into the array.
 *
 * array: The array where we want to save the element.
 * ptr:   The pointer to the element.
 */
void insert_element(Array array, void *ptr, unsigned int pos);

/**
 * Return pointer to element at given index.
 *
 * array: The array where the element is stored.
 * pos:   The index to be retrieved.
 *
 * Returns the pointer to the element at the given index.
 */
void *get_element(Array array, unsigned int pos);

/**
 * Remove element at the back from the array.
 *
 * array: The array we want to remove the element from.
 *
 * Returns the pointer to the element stored at the back.
 */
void *pop_element(Array array);

/**
 * Remove element at the back from the array.
 *
 * array: The array we want to remove the element from.
 * pos:   The position we want to remove.
 *
 * Returns the pointer to the element stored at the position.
 */
void *remove_element(Array array, unsigned int pos);

/**
 * Deletes and deallocates the whole array.
 *
 * array:          The array to delete.
 * delete_element: Function to fully deallocate stored elements.
 *                 If null, pointers will be simply freed.
 */
void delete_array(Array array, void (*delete_element)(void *));
