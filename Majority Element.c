### Majority Element – C Solution

Use the **Boyer-Moore Voting Algorithm**. It finds the majority element in one traversal without sorting.

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long a[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    long long candidate = a[0];
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(count == 0)
        {
            candidate = a[i];
        }

        if(a[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    printf("%lld\n", candidate);

    return 0;
}

### Example

**Input:**
```text
7
2 2 1 1 1 2 2
```

**Output:**
```text
2
```

### Explanation
- 2 → count = 1
- 2 → count = 2
- 1 → count = 1
- 1 → count = 0
- 1 → candidate = 1, count = 1
- 2 → count = 0
- 2 → candidate = 2, count = 1

Majority element = **2**.

### Complexity
- **Time:** O(N)
- **Space:** O(N) for storing the array.

**Submit using C (GNU GCC).**
