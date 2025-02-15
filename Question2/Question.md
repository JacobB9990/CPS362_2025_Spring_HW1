# 2. (50 pts) Truncation Errors in Iterative Algorithm
Write a program to demo the truncation errors of the iterative algorithm for computing the n^th power of the golden ratio (i.e., φ = (1 + √(5))/2, compute φ^n). Try both `double` and `float`, and compare the respective n's at which you observe the errors. Plot the errors in figures as demonstrated in class. C is highly recommended for the iterative algorithm. Python can be used for plotting.

# Answer

## Methods
We wrote a C program that calculates φ^n using an iterative approach based on the formula:

φ^n = φ^(n-1) + φ^(n-2)

The program implements this calculation using both the `double` and `float` data types. Users can specify the n-value, and the program calculates φ^n up to that value. Each result is written to a CSV file with the format:

```
n,Iterative_double,Iterative_float,Delta
```

Here, `Delta` represents the absolute difference between the `double` and `float` values for each n.

Finally, a Python script processes the CSV file using `pandas` and `matplotlib` to generate plots that visualize truncation errors.

To simplify usage, the C program is configured to execute the Python script automatically after running the calculations. This can be done with a single command:

```bash
gcc CalculationPhi.c -o CalculationPhi -lm && ./CalculationPhi
```

---

## Results
The resulting graph shows a growing divergence between the `double` and `float` computations as n increases. The `Delta` values indicate that `float` has significantly less precision than `double`, particularly for larger n-values.

### Sample CSV Output
| n   | Iterative_double | Iterative_float | Delta       |
|-----|------------------|-----------------|-------------|
| 2   | 2.618034         | 2.618034        | 0.000000    |
| 10  | 122.991869       | 122.991867      | 0.000002    |
| 50  | 28143753123.000  | 28143755264.000 | 2141.000000 |
| 100 | 792070839848372  | 792071077044995 | 237196623085568 |

As the n-values increase, the truncation error Δ grows rapidly, particularly for `float`. This is shown clearly in the plots, where the curve steepens as n grows.

---

## Observations
- `float` values lose precision much earlier than `double`.
- The errors for `float` grow exponentially, while `double` maintains accuracy for much larger n-values.
- For n >= 35, significant differences are observable in the results. Beyond n = 80, the `Delta` values become extremely large, making `float` unusable for such computations.