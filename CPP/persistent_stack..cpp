/*
 * persistent_stack..cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: mohammra
 */

#include "common.h"


/*
 * push(item) -> stack
 * pop() -> stack
 * peek() -> item
 * empty() ->empty
 * size() -> int
 *
 * stack = stack.empty()
 * newStack = stack.push(1)
 * newStack2 = stack.push(2)
 *
 * newStack.peek() -> 1
 * newStack2.peek() -> 2
 *
 * newStack3 = newStack2.pop()
 *
 * newStack2.peek() -> 2
 * newStack3.peek() -> 1
 * 1 2 3 5 6
 *
 * [1]
 * push(2)
 * [1] 2
 * pop()
 * [1]
 * push(3)
 * [1] 3
 *
 * [[1] 3] 2
 *
 * [1] 6
 */

#include <iostream>
#include <vector>
using namespace std;


class stack {
public:
  stack* prev;
  int data;
  int size;
  /*
  stack(int d){
    data = d;
    size = 1;
    prev = NULL;
  }*/

  stack(){
    size = 0;
    prev = NULL;
  }

  stack* push(int e) {
    stack* temp = this;
    stack* newStack = stack();
    newStack->data = e;
    newStack->size = this->size + 1;
    newStack->prev = temp;
    return newStack;
  }

  stack pop() {
    return this->prev;
  }

  stack peek() {
    return this->data;
  }

  static stack* empty(){
    return new stack();
  }

  int size() {
    return this->size;
  }
};


// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  return 0;
}
