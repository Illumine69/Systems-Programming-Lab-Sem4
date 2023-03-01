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
13. 