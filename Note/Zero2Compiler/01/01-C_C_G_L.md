# **Creating Computer Grade Language**
- Goal : Support sentences with arithmetic operators, ex : `30 + (4 - 2) * -5`
- Algorithm : **Recursive descendent parsing**

## **Extra Knowledge**
- Compare Intel and AT&T syntax
    1. The result of the AT&T syntax is placed in the second argument
    2. Register need `%` reference symbol, ex: `%rax`
    3. Value need `$` reference symbol, ex : `$42`
    4. The reference memory also has its unique way of writing, which is to replace `[]` with `()`
```
mov rbp, rsp   // Intel (copy(move) the value of rsp into rbp)
mov %rsp, %rbp // AT&T  (copy(move) the value of rsp into rbp)

mov rax, 8     // Intel (set(move) 8 into rax)
mov $8, %rax   // AT&T  (set(move) 8 into rax)

mov [rbp + rcx * 4 - 8], rax // Intel
mov %rax, -8(rbp, rcx, 4)    // AT&T
```
## **Step 1 : Compile 1 integer**
