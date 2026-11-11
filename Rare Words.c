## Question: Rare Words

### Given Problem
Given two messages `m1` and `m2`, print all the rare words in lexicographical order.

A word is called rare if:

1. It occurs exactly once in one message.
2. It does not occur at all in the other message.

### Solution in C

#include <stdio.h>
#include <string.h>

int main()
{
    char m1[1005], m2[1005];
    char a[500][100], b[500][100];
    int c1 = 0, c2 = 0;

    fgets(m1, sizeof(m1), stdin);
    fgets(m2, sizeof(m2), stdin);

    char *p = strtok(m1, " \n");

    while (p != NULL)
    {
        strcpy(a[c1], p);
        c1++;
        p = strtok(NULL, " \n");
    }

    p = strtok(m2, " \n");

    while (p != NULL)
    {
        strcpy(b[c2], p);
        c2++;
        p = strtok(NULL, " \n");
    }

    char rare[1000][100];
    int count = 0;

    for (int i = 0; i < c1; i++)
    {
        int freq1 = 0, freq2 = 0;

        for (int j = 0; j < c1; j++)
        {
            if (strcmp(a[i], a[j]) == 0)
                freq1++;
        }

        for (int j = 0; j < c2; j++)
        {
            if (strcmp(a[i], b[j]) == 0)
                freq2++;
        }

        if (freq1 == 1 && freq2 == 0)
        {
            strcpy(rare[count], a[i]);
            count++;
        }
    }

    for (int i = 0; i < c2; i++)
    {
        int freq1 = 0, freq2 = 0;

        for (int j = 0; j < c2; j++)
        {
            if (strcmp(b[i], b[j]) == 0)
                freq2++;
        }

        for (int j = 0; j < c1; j++)
        {
            if (strcmp(b[i], a[j]) == 0)
                freq1++;
        }

        if (freq2 == 1 && freq1 == 0)
        {
            strcpy(rare[count], b[i]);
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(rare[i], rare[j]) > 0)
            {
                char temp[100];
                strcpy(temp, rare[i]);
                strcpy(rare[i], rare[j]);
                strcpy(rare[j], temp);
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s ", rare[i]);
    }

    printf("\n");

    return 0;
}

### Explanation

1. Read the two messages using `fgets()`.
2. Use `strtok()` to separate the messages into individual words.
3. Store the words of the first message in array `a`.
4. Store the words of the second message in array `b`.
5. Check the frequency of each word in both messages.
6. If a word occurs exactly once in the first message and zero times in the second message, it is rare.
7. Similarly, check the words of the second message.
8. Store all rare words in another array.
9. Sort the rare words using `strcmp()` in lexicographical order.
10. Print all rare words.

### Example Dry Run

**Input:**
```text
red blue green
red blue yellow
```

**Message 1:**
- red → occurs once
- blue → occurs once
- green → occurs once

**Message 2:**
- red → occurs once
- blue → occurs once
- yellow → occurs once

**Checking rare words:**

| Word | Message 1 | Message 2 | Rare? |
|---|---:|---:|---|
| red | 1 | 1 | No |
| blue | 1 | 1 | No |
| green | 1 | 0 | Yes |
| yellow | 0 | 1 | Yes |

### Sample Output

```text
green yellow
```

### Time Complexity

**O(N² + M² + NM + R²)**

- N = Number of words in the first message.
- M = Number of words in the second message.
- R = Number of rare words.

### Space Complexity

**O(N + M + R)** – Arrays are used to store words and rare words.

### Important Points

- Use `fgets()` to read messages containing spaces.
- Use `strtok()` to separate words.
- Use `strcmp()` to compare words.
- A word must occur exactly once in one message.
- It must not occur in the other message.
- Sort the final words alphabetically before printing.
