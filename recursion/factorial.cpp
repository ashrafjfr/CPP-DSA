// Recursive implementation of n! calculation

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    // Recursive care: n! = n * (n - 1)
    return n * factorial(n - 1);
}