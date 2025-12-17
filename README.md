*This project has been created as part of the 42 curriculum by csuomins.*

## Description

This project is called push_swap, and its main idea is to sort a stack of integers
in ascending order using a limited set of operations.
The program receives a list of integer arguments, 
which are added to stack A, and with the help of stack B, 
they are sorted using the smallest possible number of operations.

## Instructions

**Compilation:**

make

**Execution:**

./push_swap 3 2 1

**Example:**

$>./push_swap 3 2 1
sa
rra

**To check larger sets of numbers using the checker:**

ARG=$(seq 1 500 | shuf -n <qtd de args> | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

**To test the number of movements:**

ARG=$(seq 1 500 | shuf -n <qtd de args> | tr '\n' ' '); ./push_swap $ARG | wc -l

## Resources

https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
https://share.google/pZpsOYLrWrFMOsEFD
https://youtu.be/Lb_1R6JGD6o?si=5gU53MZ31g3xyT9b
https://youtu.be/XiuSW_mEn7g?si=dfITxspXWPdR269K
https://youtu.be/KwiyNWQoMy0?si=xqSWYt7aqYQt9bxq
https://share.google/G7TF3NGnVswbV5NyR

AI tools were used to help understand the project requirements, 
review algorithmic choices, generate ideas for testing edge cases, 
and clarify theoretical questions.
