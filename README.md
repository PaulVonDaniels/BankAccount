# Personal account of the bank (console application)

This is a console application that simulates a bank's personal account, written in C++. The program allows the user to manage their balance, view transaction history, and perform basic banking operations such as deposits and withdrawals.

## Main functions

- **Registration and login**: The user can create a login and PIN code to log in.
- **Replenishment of the balance**: The user can replenish his balance by the specified amount.
- **Withdrawals**: The user can withdraw money from the balance if there are enough funds in the account.
- **Balance View**: The user can find out the current balance.
- **Operation History**: The user can view the history of all completed operations.
- **History Cleanup**: The user can clear the transaction history.
- **Exit**: The user can log out of the personal account.

## Features

- **Correct declension of the word "ruble"**: The program automatically determines the correct declension of the word "ruble" depending on the amount.
- **PIN code restriction**: The PIN code must consist of at least 6 digits.
- **Protection against incorrect input**: The program checks the correctness of data entry and gives the user the opportunity to try again.

## How to use

1. Compile the program using a C++ compiler (for example, g++):
``bash
   g++ -o bankAccount main.cpp -lncurses

2. Run the program:
./BankAccount


## Requirements

- **The C++ compiler (for example, g++).

- **The ncurses library (if used).
