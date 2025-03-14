# Push_swap

## 📌 Introduction
Push_swap is a sorting algorithm project from 42 that requires sorting a stack of integers with the fewest possible moves, using a limited set of operations.

## 🚀 Features
- Sorts numbers using a set of stack-based operations.
- Implements efficient algorithms like **Chunk Sort** for large stacks.
- Handles input validation and error checking.
- Includes a bonus **checker** program for validation.

## 🛠️ Installation & Compilation
Clone the repository and compile the project:
```sh
make
```
To compile the bonus (checker):
```sh
make bonus
```
To clean object files:
```sh
make clean
```
To remove executable files:
```sh
make fclean
```
To recompile everything:
```sh
make re
```

## 📜 Usage
Run push_swap with a list of numbers:
```sh
./push_swap 4 67 3 87 23
```
To verify sorting using checker:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## 🔄 Allowed Operations
- `sa` / `sb` / `ss`  → Swap elements.
- `pa` / `pb` → Push between stacks.
- `ra` / `rb` / `rr` → Rotate up.
- `rra` / `rrb` / `rrr` → Rotate down.

## 📊 Algorithm Breakdown
1️⃣ **Input Handling**: Checks for duplicates, invalid characters, and overflows.  
2️⃣ **Sorting Small Stacks** (≤ 5 elements): Uses **brute-force** optimal sorting.  
3️⃣ **Sorting Large Stacks** (> 5 elements): Uses **Chunk Sorting**:  
   - **Divides stack into chunks** based on sorted values.
   - **Pushes numbers from stack A to B in chunks**.
   - **Retrieves them back in sorted order** efficiently.
   - [push_swap.pdf](https://github.com/user-attachments/files/19230971/push_swap.pdf)

## 🧪 Testing
✅ Large sets (100 / 500 numbers)
```sh
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

## 📌 Credits
Project completed as part of **42 School's curriculum**.

🎯 **Successfully validated & optimized!** 🚀

