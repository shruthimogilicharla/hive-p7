## Evaluate Infix Notation – THE HIVE

### Problem
Given a mathematical expression in infix notation, evaluate it and print its result.

### Input Format
A single string `S` containing digits (1–9) and operators (`+`, `-`, `*`, `/`).

### Output Format
Print the evaluated result.

### Constraints
- 3 ≤ Length of S ≤ 50

### Example

**Input:**
```text
2+3*4
```

**Output:**
```text
14
```

### C Solution

#include<stdio.h>
int main(){
    char s[51],op='+';
    int st[51],t=-1,n=0;
    scanf("%s",s);

    for(int i=0;s[i];i++){
        if(s[i]>='1'&&s[i]<='9')
            n=s[i]-'0';

        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i+1]=='\0'){
            if(op=='+') st[++t]=n;
            if(op=='-') st[++t]=-n;
            if(op=='*') st[t]*=n;
            if(op=='/') st[t]/=n;
            op=s[i];
            n=0;
        }
    }

    int ans=0;
    while(t>=0) ans+=st[t--];

    printf("%d\n",ans);
    return 0;
}

### Explanation
For `2+3*4`:

1. Push 2.
2. Push 3.
3. Multiply 3 by 4.
4. Add 2 + 12.
5. Result = **14**.

### Complexity
- Time: O(N)
- Space: O(N)
