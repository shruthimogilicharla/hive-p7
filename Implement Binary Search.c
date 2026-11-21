## Question: Implement Binary Search.

### Given Problem
Given a sorted array A of size N and an integer target K, implement Binary Search to find the target K in the array.

For every iteration of Binary Search, print the values of `low`, `high`, and `mid`.

At the end:
- Print `"True"` if the target K is found.
- Print `"False"` if the target K is not found.

### Solution in C

#include <stdio.h>

int main()
{
    int n, k;
    int a[20];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int low = 0;
    int high = n - 1;
    int found = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        printf("%d %d %d\n", low, high, mid);

        if (a[mid] == k)
        {
            found = 1;
            break;
        }
        else if (a[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}

### Explanation

1. Read the size of the array `n` and target `k`.
2. Read the sorted array elements.
3. Initialize `low = 0` and `high = n - 1`.
4. Repeat while `low <= high`.
5. Calculate the middle index using `mid = (low + high) / 2`.
6. Print the values of `low`, `high`, and `mid`.
7. If `a[mid] == k`, the target is found.
8. If `a[mid] < k`, search the right half by updating `low = mid + 1`.
9. If `a[mid] > k`, search the left half by updating `high = mid - 1`.
10. Finally, print `"True"` if the target is found; otherwise, print `"False"`.

### Example Dry Run

**Input:**
```text
9 12
1 4 6 7 10 11 12 20 23
```

**Iteration 1:**

- low = 0
- high = 8
- mid = (0 + 8) / 2 = 4
- a[4] = 10
- 10 < 12, so low = 5.

**Iteration 2:**

- low = 5
- high = 8
- mid = (5 + 8) / 2 = 6
- a[6] = 12
- Target found!

### Sample Output
```text
0 8 4
5 8 6
True
```

### Time Complexity

**O(log₂ N)** – The search space is divided into half in every iteration.

### Space Complexity

**O(N)** – An array of size N is used to store the elements.

**Important:**
- Binary Search works only on a sorted array.
- `low` represents the starting index.
- `high` represents the ending index.
- `mid` represents the middle index.
- Use `low = mid + 1` to search the right half.
- Use `high = mid - 1` to search the left half.
