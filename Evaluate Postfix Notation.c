## Evaluate Postfix Notation – THE HIVE

### Problem
Given a mathematical expression in postfix notation, evaluate the expression and print its result.

### Input Format
A single string `S` containing digits (1–9) and operators (`+`, `-`, `*`, `/`).

### Output Format
Print the evaluated result.

### Constraints
- 1 ≤ Length of S ≤ 50
- Division gives an integer result.
- Division by zero will not occur.

### Example

**Input:**
```text
924+-3+2/
```

**Output:**
```text
3
```

### C Solution (Short Code)

#include<stdio.h>
int main(){
    char s[51];
    int st[50],t=-1,a,b;
    scanf("%s",s);

    for(int i=0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9')
            st[++t]=s[i]-'0';
        else{
            b=st[t--];
            a=st[t--];
            if(s[i]=='+') st[++t]=a+b;
            if(s[i]=='-') st[++t]=a-b;
            if(s[i]=='*') st[++t]=a*b;
            if(s[i]=='/') st[++t]=a/b;
        }
    }
    printf("%d",st[t]);
    return 0;
}

### Explanation

For input `924+-3+2/`:

1. 2 + 4 = 6
2. 9 - 6 = 3
3. 3 + 3 = 6
4. 6 / 2 = 3

**Final Answer: 3**

### Complexity
- Time: O(N)
- Space: O(N)
