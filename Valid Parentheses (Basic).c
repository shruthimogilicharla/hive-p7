## Valid Parentheses (Basic) – THE HIVE

### Problem
Given a string containing brackets `()`, `{}`, and `[]`, check whether the brackets are valid and properly balanced.

### Input Format
A single string `S` containing brackets.

### Output Format
Print `YES` if valid, otherwise print `NO`.

### Constraints
- 1 ≤ Length of S ≤ 1000

### Example

**Input:**
```text
{[([])]}
```

**Output:**
```text
YES
```

### C Solution (Short Code)

#include<stdio.h>
int main(){
    char s[1005],st[1005];
    int t=-1,ok=1;
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            st[++t]=s[i];
        else{
            if(t==-1){
            ok=0;
            break;
           }
            if((s[i]==')'&&st[t]=='(')||(s[i]=='}'&&st[t]=='{')||(s[i]==']'&&st[t]=='['))
                t--;
            else{ok=0;break;}
        }
    }
    if(t!=-1)
    ok=0;
    printf(ok?"YES\n":"NO\n");
    return 0;
}

### Explanation
A stack stores opening brackets.

For `{[([])]}`:
- Push opening brackets.
- Match each closing bracket with the top opening bracket.
- All brackets match and the stack becomes empty.

Therefore, output is **YES**.

### Complexity
- Time: O(N)
- Space: O(N)
