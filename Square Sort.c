## Question: Square Sort

### Given Problem
Given an integer array A sorted in non-decreasing order, print an array containing the squares of each element, sorted in non-decreasing order.

### Solution in C

#include <stdio.h>

int main()
{
    int n;
    int a[10000], b[10000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int left = 0;
    int right = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int x = a[left] * a[left];
        int y = a[right] * a[right];

        if (x > y)
        {
            b[i] = x;
            left++;
        }
        else
        {
            b[i] = y;
            right--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    return 0;
}

### Explanation

1. Read the size of the array `n`.
2. Read all array elements.
3. Create another array `b` to store the squares in sorted order.
4. Initialize `left = 0` and `right = n - 1`.
5. Compare the squares of the leftmost and rightmost elements.
6. Store the larger square at the last available position of array `b`.
7. If the left square is larger, increment `left`.
8. Otherwise, decrement `right`.
9. Repeat until all elements are processed.
10. Finally, print the sorted squared array.

### Example Dry Run

**Input:**
```text
5
2 2 3 3 11
```

**Calculation:**

| Element | Square |
|---|---:|
| 2 | 4 |
| 2 | 4 |
| 3 | 9 |
| 3 | 9 |
| 11 | 121 |

**Sorted squares:**

`4 4 9 9 121`

### Sample Output

```text
4 4 9 9 121
```

### Time Complexity

**O(N)** – Each element is processed exactly once.

### Space Complexity

**O(N)** – An additional array is used to store the sorted squares.

### Important Points

- The input array is already sorted.
- Use two pointers: `left` and `right`.
- Compare the squares of both ends.
- Store the larger square from right to left.
- This approach avoids using an extra sorting algorithm.
- It works with both positive and negative numbers.
