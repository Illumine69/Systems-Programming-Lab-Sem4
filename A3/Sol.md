## s = 17721

### Method:
1. run the executable file using `gdb ./oops`
2. Use `l` to find the line where variable **r** is being assigned the value returned by function **f**. This is **line 16**
3. Use `b 16` to insert a breakpoint at **line 16**
4. Use `r 21CS10057` to run . At the breakpoint, type `set var n = 20000`. Type `c` to continue.
5. The program will return **1**. This means **s** lies    between 10000 and 20000.    
    We will repeat **step 4** again by changing the value of **n**. For efficiency , we will use **binary search**. 

Hence, set **n** to **half the range + lowest value(which gave f(n) = 0)**. For example, I found that *f(15000) = 0* and *f(20000) = 1*. So I will set n to *(20000 - 15000)/2 + 15000 = 17500* using `set var n = 17500`. Since *n = 17500* gave *f(n) = 0*, it became my new lowest value with new range = 2500.

Continuing like this, you can find the secret **s** for which *f(s) = 1 and f(s-1) = 0*.