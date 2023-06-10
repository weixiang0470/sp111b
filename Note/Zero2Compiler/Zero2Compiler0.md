# Memory
- Device to store data
- Provide and receive data to/from CPU or others device
# CPU
- Main operation device
- Read and write memory
    - See memory as a big array that made up by byte
    - When accessing memory need to specify the address of memory
    - CPU will store the **memory address** of the instruction being executed at the current time in pc_register, then access the memory address and execute the instruction, then read next instruction and execute. 
    - The number store in the pc_register is called **Program Counter** or **Instruction Pointer**
    - CPU can use **branch instruction** to let Program Counter jump to any instruction other than the next instruction, this operation called **jump** or **branch**
- CPU only execute Machine language

# Assembler
- Use to translate **assembly language(組合語言)** to **machine language(機械語言)**
    - The process is called Compilation
- Assembly language is much **easier** to read and write than machine language
- EX: `3d58:  48 83 ec 08           sub    rsp,0x8` (hexadecimal number)
    - **3d58** : The memory address that the machine language stored (0x3d58)
    - **48 83 ec 08** : The machine language 
    - **sub rsp,0x8** : The assembly language corresponding to the machine language(48 83 ec 08)
        - Meaning : Register rsp subtract by 8 

# Simple c example
- c program language
```
int main() {
  return 42;
}
``` 
- assemble language 
```
.intel_syntax noprefix
.global main
main:
        mov rax, 42
        ret
```
- `.intel_syntax noprefix` : Use intel assembly language's syntax 
- `.global main` : Define **main** in **global label**
- `main:` : Following by instruction code of main function
    - `mov rax, 42` : Set(move) **42** into **rax register**
    - `ret` : Transfers control to the **return address** and jump out from main

# Stack
- Return address need to be stored in memory
    - if only happens once then we can store in register but we can keep calling the function(Recursive)
    - Practically store the return address in memory's stack
- push : add into the top of stack
- pop : remove from the top of stack
# Example with function call
- c program
```
int plus(int x, int y) {
  return x + y;
}

int main() {
  return plus(3, 4);
}
```
- assemble language
```
.intel_syntax noprefix
.global plus, main

plus:
        add rsi, rdi
        mov rax, rsi
        ret

main:
        mov rdi, 3
        mov rsi, 4
        call plus
        ret
```
- `.global plus, main` : Define **plus** and **main** in global label(program scope)
- `main:` : Instruction code of main function
    - `mov rdi, 3` : Set 3 into rdi register 
    - `mov rsi, 4` : Set 4 into rsi register
        - Default set first argument into rdi and second argument into rsi register
    - `call plus` : Command/instruction to call function, and do the following 
        1. Push the address of next instruction(after call) into **stack**
        2. Jump to the address of the given by the argument of call(address of plus)
        - main will wait here and start execute plus function, after plus function return will continue execute from next instruction(ret)
    - `ret` : Transfers control to the **return address** and jump out from main
        - From c program, main return the plus function's return value
        - Inside of rax register is plus function's return value, so main return directly(rax register become main function's return value)
- `plus:` : Instruction code of plus function
    - `add rsi, rdi` : Add the value inside of **rsi and rdi register** and stored in **rsi register**
    - `mov rax, rsi` : Set/copy the value inside of **rsi register** into **rax register**
        - **Return value of function** need to be stored inside **rax register**
    - `ret` : return back
        1. pop the address from stack (address pushed when call in main)
        2. Jump to the address poped out from stack
        - After ret will go back to main(main call this function) and continue execute the next instruction
# Conclusions 
1. The **CPU reads and writes the memory** to let the program continue.
2. **Program executed by the CPU** and the **data** processed by the program, are both keep in the **memory**.(CPU reads the machine code line by line and execute it)
3. The **CPU** has a **small access space** called a **register**, most of the **instructions** are defined to **operate between registers**.
4. **Assembly language is more readable** compare to machine language. C compilers generally output assembly language.
5. **Function** in **C language** also a function in **assembly language**
6. **Function calls** are implemented using the **stack** 