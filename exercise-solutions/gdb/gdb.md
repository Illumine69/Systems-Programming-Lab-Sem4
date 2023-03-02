1.  1. Use `list FUNCTION`
    2. Use `set listsize <NumofLines>`
    3. Use `l -` to print 10 lines before the last lines printed

2.  
        gcc -g allparts.c
        gdb ./a.out

    Using list directive will run the main function of allparts.c.  
    To list individual part files partx.c, use `l partx.c:LINNUM`   
    To set breakpoint at specified line number in the part files, use `b FILENAME:LINNUM`

3.  Compiling using `#include "partx.c"` is suspicious and gives linker error. Hence, I declared the function in the main file (you can also include a separate header file).
    
        gcc -g allparts.c part1.c part2.c part3.c
        gdb ./a.out

    Using list directive will run the main function of allparts.c.  
    //To list individual part files partx.c, use `l partx.c:LINNUM`   
    //To set breakpoint at specified line number in the part files, use
    //`b FILENAME:LINNUM`
    
4.  
5.  Use `file <exe-file>`
6.  To re-run from beginning, type `run`   
    Breakpoints and value history remain the same   
    Variables' values have to be entered again
7.  Use the `show` command  
8.  Use the `ignore` command. For example, you can ignore the breakpoint   for the next 10 times with the command `ignore 1 10`, where "1" is the number of the breakpoint and "10" is the number of times to ignore it.
9.  - Set a breakpoint at a line in the program where you want to create the new variable. For example, you can set a breakpoint at line 10 with the command `break 10`.
    - When the program stops at the breakpoint, you can create a new variable using the `set` command. For example, you can create a new integer variable named my_var and set it to 42 with the command `set $my_var = 42`.
    - You can then use the new variable in GDB commands just like any other variable. For example, you can print the value of my_var with the command `print $my_var`.
    - If you want to delete the variable, you can use the `unset` command. For example, you can delete my_var with the command `unset $my_var`.
10.      //conditional break
        break 234
        condition 234 p==NULL\

        //to get value of n
        print n
11.
12. While programming is running, use `watch x` for the variable x.Whenever the value of the watched variable changes, gdb will pause the program execution and display a message like this:    

        Hardware watchpoint N: x
        Old value = ...
        New value = ...

    - To list all the watchpoints that are currently set, use the`info watchpoints` command
    - To enable or disable a watchpoint, use the `enable` or `disable` command followed by the watchpoint number:   

            (gdb) enable watchpoint N
            (gdb) disable watchpoint N
    - To delete a watchpoint, use `delete watchpoint N`
    - In addition, gdb also supports conditional watchpoints, where the program execution is paused only when a particular condition is met. To set a conditional watchpoint, use the `watch` command followed by the variable or expression, and the condition:    

            (gdb) watch x if x > 100
        This will pause the program execution only when the value of x is greater than 100.
13. At a breakpoint, you can use the `x` command to examine the memory content of the program.  
    `(gdb) x /[format] [length] [address]`

    > **format** specifies the display format for the memory contents (such as `x` for hexadecimal, `d` for decimal, or `c` for character), **length** specifies the number of units to display, and **address** is the memory address to examin

    For example, `x /x 16 0x1000` will examine 16 bytes of memory starting at address 0x1000 in hexadecimal format

    - to examine the contents of a variable **x**, use-     
    `x /d &x`
    - The x command also supports a range of modifiers that allow you to customize the output.      

            (gdb) x /t 0x1000  # display a byte at address 0x1000
            (gdb) x /h 0x1000  # display a half-word at address 0x1000
            (gdb) x /w 0x1000  # display a word at address 0x1000
            (gdb) x /i 0x1000  # display the disassembled instruction at address 0x1000
            (gdb) x /s 0x1000  # display a null-terminated string at address 0x1000

14. At the breakpoint set at the first printf statement, the values of **A** and **i** are uninitialized and may contain garbage values. Therefore, the values displayed by the `x` command may vary depending on the system and compiler used.     

        (gdb) x /5wx A
        0x7fffffffd8e0: 0x0000000f      0x00000010      0x00000011      0x00000000
        0x7fffffffd8f0: 0x00000000
    >`x/5wx A` : This command displays the 5 words (4 bytes each) starting at the memory address of the first element of array A        

        (gdb) x /5wx A+1
        0x7fffffffd8e4: 0x00000010      0x00000011      0x00000000      0x00000000
        0x7fffffffd8f4: 0x00000000
    >`x/5wx A+1` : This command displays the 5 words starting at the memory address of the second element of array A    

        (gdb) x/5wx A-1
        0x7fffffffd8dc: 0x00000000      0x0000000f      0x00000010      0x00000011
        0x7fffffffd8ec: 0x00000000
    >`x/5wx A-1`: This command displays the 5 words starting at the memory address of the last word of the previous stack frame, which may contain the return address

        x/1wx &i
        0x7fffffffd8dc: 0x00000000
    >`x/1wx &i` displays the word (4 bytes) starting at the memory address of the variable **i**. Since **i** is uninitialized and may contain garbage data
15. 