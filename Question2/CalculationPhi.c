#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Calculate φ
Show difference
Save the data to csv and plot in python

Formula:
φ^n = φ^(n-1) + φ^(n-2)
*/

// Double Bellow
double iterative_double(double phi, int n)
{
    double phi_n_minus_2 = 1.0;
    double phi_n_minus_1 = phi;
    double result = 0.0;

    for (int i = 2; i <= n; i++)
    {
        result = phi_n_minus_1 + phi_n_minus_2;
        phi_n_minus_2 = phi_n_minus_1;
        phi_n_minus_1 = result;
    }

    return result;
}

float iterative_float(float phi, int n)
{
    float phi_n_minus_2 = 1.0;
    float phi_n_minus_1 = phi;
    float result = 0.0;

    for (int i = 2; i <= n; i++)
    {
        result = phi_n_minus_1 + phi_n_minus_2;
        phi_n_minus_2 = phi_n_minus_1;
        phi_n_minus_1 = result;
    }

    return result;
}

// Check if Python is installed
int is_python_installed()
{
    int result_python3 = system("python3 --version");
    if (result_python3 == 0)
    {
        return 1;
    }

    int result_python = system("python --version");
    return (result_python == 0);
}

// Get the correct Python command
const char *get_python_command()
{
    int result_python3 = system("python3 --version");
    if (result_python3 == 0)
    {
        return "python3";
    }

    int result_python = system("python --version");
    if (result_python == 0)
    {
        return "python";
    }

    return NULL;
}

int main()
{
    double phi_double = (1 + sqrt(5)) / 2;
    float phi_float = (1 + sqrtf(5)) / 2;
    int nth_term;

    // Some good n values are 225 and 1475
    printf("Enter the value of n : ");
    scanf("%d", &nth_term);

    char filename[50];
    snprintf(filename, sizeof(filename), "calculating_%dth_phi.csv", nth_term);

    FILE *file_pointer;
    file_pointer = fopen(filename, "w+");

    if (file_pointer == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file_pointer, "n,Iterative_double,Iterative_float,Delta\n");

    for (int i = 2; i <= nth_term; i++)
    {
        // Double
        double iterative_phi_double = iterative_double(phi_double, i);

        // Float
        float iterative_phi_float = iterative_float(phi_float, i);

        double delta_phi = fabs(iterative_phi_double - iterative_phi_float);


        // Saving to csv
        fprintf(
            file_pointer,
            "%d,%lf,%f,%lf\n",
            i,
            iterative_phi_double,
            iterative_phi_float,
            delta_phi);
    }

    fclose(file_pointer);
    printf("Data saved to %s\n", filename);

    // Check if Python is installed and get the correct command
    const char *python_command = get_python_command();
    if (python_command != NULL)
    {
        char command[100];
        snprintf(command, sizeof(command), "%s ./readPhi.py %d", python_command, nth_term);
        system(command);
    }
    else
    {
        printf("Python is not installed. Skipping Python script execution.\n");
        printf("You can manually run the Python script 'readPhi.py' with the generated CSV file.\n");
    }

    return 0;
}

/*
gcc CalculationPhi.c -o CalculationPhi -lm && ./CalculationPhi
*/