# Advent Of Code Solutions
Library and solutions to the problems in [Advent of Code](adventofcode.com).

## Solutions

- 2021
  - [ ] day 1
  - [ ] day 2
  - [ ] day 3
  - [ ] day 4
  - [ ] day 5
  - [ ] day 6
  - [ ] day 7
  - [ ] day 8
  - [ ] day 9
  - [ ] day 10
  - [ ] day 11
  - [ ] day 12
  - [ ] day 13
  - [ ] day 14
  - [ ] day 15
  - [ ] day 16
  - [ ] day 17
  - [ ] day 18
  - [ ] day 19
  - [ ] day 20
  - [ ] day 21
  - [ ] day 22
  - [ ] day 23
  - [ ] day 24
  - [ ] day 25

## Library

### Testing

Used within the library to test that the data structures work.

  **Methods:**
  - Assertions:
    - `assert_int_equals`
    - `assert_str_equals`
    - `assert_ptr_equals`
    - `assert_true`
    - `assert_false`
  - `register_test`
    - Adds test to the tests that will be run.
    - `test`: Test to be run.
  - `main`
    - Basic main function, to run the tests.

### Dynamic Array

  Array with dynamic size. Can also act as a stack.

  **Methods:**
  - `create_array`
    - Create completely new array.
    - !Note: default capacity is 8.
    - *Returns* pointer to the new array.
  - `add_element`
    - Add element to the back of the array.
    - `array`: The array where we want to save the element.
    - `ptr`:   The pointer to the element.
  - `insert_element`
    - Insert element at the given index into the array.
    - `array`: The array where we want to save the element.
    - `ptr`:   The pointer to the element.
    - `pos`:   The position where to inset the element.
  - `get_element`
    - Return pointer to element at given index.
    - `array`: The array where the element is stored.
    - `pos`:   The index to be retrieved.
    - *Returns* the pointer to the element at the given index.
  - `pop_element`
    - Remove element at the back from the array.
    - `array`: The array we want to remove the element from.
    - *Returns* the pointer to the element stored at the back.
  - `remove_element`
    - Remove element at the back from the array.
    - `array`: The array we want to remove the element from.
    - `pos`:   The position we want to remove.
    - *Returns* the pointer to the element stored at the position.
  - `delete_array`
    - Deletes and deallocates the whole array.
    - `array`:          The array to delete.
    - `delete_element`: Function to fully deallocate stored elements. If `null`, pointers will be simply freed.
