## Question: Implement Merge Sort

### Given Problem
Given an array of size N, implement the Merge Sort algorithm to sort the array in ascending order.

For every merge operation, print the elements of the entire array.

### Solution in C

This is the **corrected code for THE HIVE**. It avoids the previous mistake of declaring `n` twice.

#include <stdio.h>

int a[20], n;

void merge(int low, int mid, int high)
{
    int temp[20];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low, j = 0; i <= high; i++, j++)
    {
        a[i] = temp[j];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergeSort(0, n - 1);

    return 0;
}

### Explanation

1. Read the size of the array `n`.
2. Read all array elements.
3. Call `mergeSort(0, n-1)`.
4. Divide the array into two halves using the middle index.
5. Continue dividing until each subarray contains only one element.
6. Call the `merge()` function to combine the two sorted halves.
7. Compare elements from both halves and place the smaller element into a temporary array.
8. Copy the remaining elements into the temporary array.
9. Copy the sorted elements back into the original array.
10. Print the entire array after every merge operation.

### Merge Sort Visualization

For the input array:

`5 1 3 15 10 4`

### Example Dry Run

**Input:**
```text
6
5 1 3 15 10 4
```

**Merge operations:**

1. Merge `[5]` and `[1]`
   - `1 5 3 15 10 4`

2. Merge `[1 5]` and `[3]`
   - `1 3 5 15 10 4`

3. Merge `[15]` and `[10]`
   - `1 3 5 10 15 4`

4. Merge `[10 15]` and `[4]`
   - `1 3 5 4 10 15`

5. Merge `[1 3 5]` and `[4 10 15]`
   - `1 3 4 5 10 15`

### Sample Output

```text
1 5 3 15 10 4
1 3 5 15 10 4
1 3 5 10 15 4
1 3 5 4 10 15
1 3 4 5 10 15
```

### Time Complexity

**O(N log N)** – The array is divided into halves, and merging takes linear time.

### Space Complexity

**O(N)** – A temporary array is used during merging.

### Important Points

- Merge Sort uses the Divide and Conquer technique.
- First divide the array into smaller parts.
- Then merge the parts in sorted order.
- Print the entire array after every merge call.
- Do not print anything when dividing the array.
- **Important coding point:** Declare `int a[20], n;` globally so that both `main()` and `merge()` can access `n`. Do not declare `int n` again inside `main()`.
