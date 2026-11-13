### The Missing Seat – C Solution

**Approach:** For every empty seat (`0`), find the distance to its nearest occupied seat (`1`). Print the maximum distance.

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    int flag = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if(a[i] == 1)
            flag = 1;
    }

    if(flag == 0)
    {
        printf("-1\n");
        return 0;
    }

    int max = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            int min = n;

            for(int j = 0; j < n; j++)
            {
                if(a[j] == 1)
                {
                    int d = i - j;

                    if(d < 0)
                        d = -d;

                    if(d < min)
                        min = d;
                }
            }

            if(min > max)
                max = min;
        }
    }

    printf("%d\n", max);

    return 0;
}

### Example

**Input:**
```text
10
1 0 0 1 0 0 1 0 0 0
```

**Output:**
```text
3
```

### Explanation
- Seat 2 → distance 1
- Seat 3 → distance 1
- Seat 5 → distance 1
- Seat 6 → distance 1
- Seat 8 → distance 1
- Seat 9 → distance 2
- Seat 10 → distance 3

Maximum distance = **3**.

### Complexity
- Time: O(N²)
- Space: O(N)

This solution handles the case where all seats are empty and prints `-1`.
