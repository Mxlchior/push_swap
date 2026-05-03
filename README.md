*This project has been created as part of the 42 curriculum by megrelli.*

## 💡 Description

Push_swap is a C programming project whose goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 

This project introduces important concepts such as:
- Data structures (Linked lists)
- Sorting algorithms and complexity optimization (here I did the "Turk Algorithm" for maximum score)

The program must:
- Take a list of integers as arguments and sort them in ascending order into Stack A.
- Only use two stacks (A and B) and a specific set of operations (sa, pb, ra, rrr, etc.).
- Output the exact sequence of instructions used to sort the stack.
- Handle errors gracefully by displaying "Error\n" on the standard error output for any invalid input (duplicates, non-integers, exceeding INT_MAX/INT_MIN).

## 🚀 Instructions

Compile the project using the provided Makefile:
make

To execute the program, provide a list of integers (either as separate arguments or as a single string):
./push_swap 42 1337 -21 0 5

Or with a formatted string:
./push_swap "42 1337 -21 0 5"

Example:
./push_swap 2 1 3
sa
ra

## 📚 Resources

- The "Turk Algorithm" article by A. Yigit: https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- Push swap tutorial video by Thuggonaut: https://www.youtube.com/watch?v=wRvipSG4Mmk
- Push swap tutorial video by Oceano: https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s&pp=ygUJcHVzaCBzd2Fw
- AI (Gemini Pro) was used as an interactive tutor for conceptual clarification (code architecture, doubly linked list, complexity...) and the structuration of this README.md file.

## 📊 Performances

Here are the results showing the number of instructions needed to sort the stacks :

| Stack Size | Tests Run | Status | Average Moves | Min Moves | Max Moves |
|:----------:|:---------:|:------:|:-------------:|:---------:|:---------:|
|    100     |   1000    | ✅ OK  |     560       |    485    |    647    |
|    500     |   1000    | ✅ OK  |    5108       |   4704    |   5425    |

*Note: The algorithm consistently scores maximum points (5/5) on both the 100 numbers bracket (< 700 instructions) and the 500 numbers bracket (< 5500 instructions).*
