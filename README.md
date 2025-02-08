Jacob Becker and Adithya Hanakere Virupaksha

# CPS363 - 2025 Spring - Assignment #1

## DUE DATE: Feb. 14 (Fri.) no later than 11:59 PM EST via email

## REQUIREMENTS

- Each group will hand in only one submission.
- **Print names of all members are required in submissions.**
- The submission file should be titled: `cps362_2025_Spring_[HM NUMBER]_[PRINT NAMES].zip/others`.
- All submissions will be sent to Fanchao (`fmeng@misericordia.edu`) via emails or GitHub repo.
- Fanchao will confirm each submission.
- **Late submissions are NOT accepted unless you have the permission from Fanchao.**

## Problems (100 points in total)

### 1. (50 pts) Bi-directional Decimal-Double Converter
Write a bi-directional decimal-double converter. Given a decimal, the program converts it to the double, and given a double, it converts it to the decimal. IEEE 754 must be followed. In addition to the converted values, the program is required to print out the sign bit, the unbiased exponent, and the mantissa, in binary, for every input. C is highly recommended. High-level programming languages such as Python and Java are NOT recommended. (Hint: Use `-00 -g3 -Ma11` if you use `gcc`.)

### 2. (50 pts) Truncation Errors in Iterative Algorithm
Write a program to demo the truncation errors of the iterative algorithm for computing the n^th power of the golden ratio (i.e., φ = (1 + √(5))/2, compute φ^n). Try both `double` and `float`, and compare the respective n's at which you observe the errors. Plot the errors in figures as demonstrated in class. C is highly recommended for the iterative algorithm. Python can be used for plotting.

### 3. BONUS TASK: Asymptotic Analysis of Errors
Give an asymptotic analysis of the errors in Problem 2, i.e., give the tight bound (in θ) of the errors. The analysis procedure is required.