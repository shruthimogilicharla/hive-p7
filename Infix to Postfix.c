### Infix to Postfix – C Solution

**Approach:** Use a stack to store operators.

**Operator precedence:**
1. `*`, `/` → Higher priority
2. `+`, `-` → Lower priority

When an operator with lower or equal precedence comes, pop the previous operator from the stack.

### C Code (THE HIVE)

#include<stdio.h>

int main(){
char s[51],st[51],p[51];int t=-1,k=0;
scanf("%s",s);
for(int i=0;s[i];i++){
if(s[i]>='0'&&s[i]<='9')p[k++]=s[i];
else{
while(t>=0&&(st[t]=='*'||st[t]=='/'||((s[i]=='+'||s[i]=='-')&&(st[t]=='+'||st[t]=='-'))))
p[k++]=st[t--];
st[++t]=s[i];
}}
while(t>=0)p[k++]=st[t--];
p[k]=0;
printf("%s",p);
return 0;
}

### Example

**Input:**
```text
2+3*4
```

**Output:**
```text
234*+
```

### Another Example

**Input:**
```text
2*3+4
```

**Output:**
```text
23*4+
```

### Complexity
- Time: O(N)
- Space: O(N)

**Use C (GNU GCC) and submit.**
