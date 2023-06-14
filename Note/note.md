# **$a^nb^n$**
- Solution 1
    - $S = a(S^*)b$
- Solution 2
    - $S = ab | aSb$
# **Make**
- `make`
- `mingw32-make`
```
CC = riscv64-unknown-elf-gcc
CFLAGS = -nostdlib -fno-builtin -mcmodel=medany -march=rv32ima -mabi=ilp32

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none

OBJDUMP = riscv64-unknown-elf-objdump

all: os.elf

os.elf: start.s os.c
	$(CC) $(CFLAGS) -T os.ld -o os.elf $^

qemu: $(TARGET)
	@qemu-system-riscv32 -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	$(QEMU) $(QFLAGS) -kernel os.elf

clean:
rm -f *.elf
```
- `-nostdlib` : 不使用標準函式庫
- `-fno-builtin` : 不適用內建功能 
- `-march=rv32ima` : 整數，乘除，原子
- `-bios none` : 不要bios

# **Execute file + "&"**
- 放在背景執行, ex : `./task &`
# **gcc**
- `gcc sum.c -o sum` : compile **sum.c** to executable file **sum**
- `./sum` : execute **sum**
- `gcc -s sum.c -o sum.s` : compile **sum.c** into **sum.s**(assemble language file)

# **Denoka**
- `ssh guest2@denoka.net`
- `denoka111b`

# **Extra**
- _**殭屍行程：程式已結束但還存在記憶體裡面**_
- Telnet
	- 早期的ssh
	- 沒加密的功能
- Fork
    - 效能較thread差
- ffmpeg
	- 命令列版的photoshop
 
## **MAC terminal 中文编码问题(solution)**
- `locale`
- `source ~/.bash_profile`
- `vim ~/.bash_profile`
- `export LC_CTYPE=en_US.UTF-8`

# **C language**
```

int main() {
  int a = open("a.txt", O_RDWR);  
  int b = open("b.txt", O_CREAT|O_RDWR, 0644);  
  char text[SMAX];
  int n = read(a, text, SMAX);
  printf("n=%d\n", n);
  write(b, text, n);
  printf("a=%d, b=%d\n", a, b);
}
```
- `O_RDWR` : 可讀可寫
- `O_CREAT` : 建立新檔
- `while(__sync_lock_test_and_set(&lk->locked, 1) != 0)；` : 等待直到鎖定成功
- `__sync_synchronize();` : 要求編譯器載入儲存指令不跨越此邊界 (fence)
## **How to include other file**
```
#include <…> : 系統預設的函式庫資料夾
#include "…" : 自己目錄的資料夾
```

## **functions & libs**
- `mmap`
	- 共用記憶體
	
- `prot`
	- 保護，可讀可寫(PROT_READ|PROT_WRITE)

- `flags`
	- 共用(MAP_SHARED)

- `./chat 1x aa bb cc`
	- argv = ["./chat","1x","aa","bb","cc"]
    - argc = 5 (number of arguments)

# **OS**
- Unix : open 回傳的是一個值
- 開啟的第一個檔案是3,因為 0(stdin), 1(stdout), 2(stderr)
    - 0 : console , keyboard
    - 1 : terminal, screen
    - 2 : terminal, screen
    - Close(0) => stdin become 
    
- MMU
    - 分頁，fork時無需複製檔案表(filetable)
	- V-addr(虛擬位置) => P-addr(實體位置)
	-  sv39 (xv6) , 64 bits
	-  sv32, 32 bits
    - Benefits : 
        1. 在虛擬空間編排程式碼（可以使用更大的空間，大家都可以從0開始（否則要重定位））
        2. 共享和保護（防止其他程式讀寫）
- Inode
    - 用于描述檔案系統
- Linux's shell
	- cshell
	- bash
    - zsh

- Thread 是嵌入式的核心
	- ex : Mini-riscv-os
- Process, thread + process 是電腦的OS核心
    - ex : xv6

- `fseek()` : 不會一直做硬碟的讀取（移動讀寫頭），設檔案目前位置，在read時才移動讀寫頭。但因為有`bread()`，有緩衝所以不是每次read都會移動，只有要讀取緩衝外的區塊才會移動讀寫頭。

- xv6 Interrupt(Trap)
	- RISC-V 通常有兩種中斷控制器，局部中斷 CLINT (Core Local Interruptor) 和外部中斷 PLIC (Platform-Level Interrupt Controller)。
	- CLINT 包含軟體中斷 (Software Interrupt) 和時間中斷 (Timer Interrupt)，發生後會立刻執行。
    - PLIC 則是外部設備的中斷，像是磁碟，鍵盤，網路的中斷，必須經過仲裁決定哪個中斷優先處理。
## **Some introduction to assembly language**
```
zero : 只能讀
ra : 用於儲存返回位址
sp : 用於指向堆疊的頂端
t0-t6 : 暫存
s0-s11 : 呼叫時必須要存起來
f0-f31 : 浮點暫存器

• RV32I：基础整数指令集 (固定不變了)
• RV32M：乘法和除法
• RV32F：單精度浮点操作（和 RV32D:雙精度浮點操作）
• RV32A：原子操作
• RV32C：可选的压缩扩展 (對應 32 位元的 RV32G),32位元 可繼續壓縮為16位元
• RV32B：基本擴展。
• RV32V：向量扩展（SIMD）指令
• RV64G：RISC-V 的 64 位地址版本。
(G : 通用)
```
- `imm` : 立即值
- `addi a4,a1,0` :  a4 = a1+0