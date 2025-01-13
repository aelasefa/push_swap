# Push_Swap

`push_swap` is a project that aims to sort a stack of integers using the smallest number of operations. It is a typical algorithmic challenge where you need to simulate stack operations to sort the integers in ascending order.

## Table of Contents
- [Introduction](#introduction)
- [Project Objective](#project-objective)
- [Operations](#operations)
- [Algorithm Explanation](#algorithm-explanation)
- [Compilation and Usage](#compilation-and-usage)
- [Test Cases](#test-cases)
- [Examples](#examples)
- [Contributors](#contributors)

## Introduction

The goal of this project is to sort a stack of integers using two stacks and a set of predefined operations. The challenge consists of sorting the elements in the stack as efficiently as possible with the least number of operations.

The push_swap project will take an unsorted list of integers and apply operations to sort them. The efficiency of the solution will be judged based on the number of operations used. 

## Project Objective

The main goal is to:
- Sort a stack of integers with the fewest number of operations.
- Implement a sorting algorithm that doesn't use built-in sorting functions.

## Operations

In this project, you are limited to a set of operations that can be performed on two stacks (denoted as `a` and `b`):

- `sa` : Swap the first two elements of stack `a`.
- `sb` : Swap the first two elements of stack `b`.
- `pa` : Push the first element of stack `b` to stack `a`.
- `pb` : Push the first element of stack `a` to stack `b`.
- `ra` : Rotate stack `a` by shifting all elements up by one.
- `rb` : Rotate stack `b` by shifting all elements up by one.
- `rra`: Reverse rotate stack `a` by shifting all elements down by one.
- `rrb`: Reverse rotate stack `b` by shifting all elements down by one.
- `rr`: Rotate both stacks `a` and `b` simultaneously.
- `rrr`: Reverse rotate both stacks `a` and `b` simultaneously.

These operations are the only allowed moves to modify the two stacks.

## Algorithm Explanation

The algorithm behind the push_swap project can be broken down into several phases, depending on the size of the stack. Here's an outline of how the algorithm works:

### 1. Initial Setup and Parsing
- First, the input is parsed and converted into an array or list of integers.
- The integers are then pushed into a stack `a`.

### 2. Sorting Strategy
Depending on the number of elements in the stack, the algorithm adapts the approach:
- **For small stacks (e.g., 2 or 3 elements)**: Direct sorting with a few basic operations like swaps is performed.
- **For larger stacks**: More advanced strategies like the "divide and conquer" method are used:
    - **Stack splitting**: The stack is divided into two smaller sub-stacks.
    - **Pivot selection**: A pivot element is chosen (usually the median or an element close to it) to partition the elements.
    - **Recursive sorting**: The algorithm recursively sorts the sub-stacks using a combination of `push`, `swap`, and `rotate` operations.

### 3. Optimization
- A key focus is on minimizing the number of operations by choosing the most efficient moves at each step.
- The algorithm avoids unnecessary moves by looking ahead and planning the sequence of operations intelligently.

### 4. Finalization
- Once the stack `a` is sorted, the algorithm ensures that all elements are placed in `a` and that stack `b` is empty.

## Compilation and Usage

To compile the project and use the push_swap program:

1. Clone the repository:
   ```bash
   git clone https://github.com/aelasefa/push_swap.git
   cd push_swap
