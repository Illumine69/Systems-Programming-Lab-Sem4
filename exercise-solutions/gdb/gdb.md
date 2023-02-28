1.  1. Use `list FUNCTION`
    2. Use `set listsize <NumofLines>`
    3. Use `l -` to print 10 lines before the last lines printed

2.  Compiling using `#include "partx.c"` is suspicious and gives linker error. Hence, I declared the function in the main file (you can also include a separate header file).
    
        gcc -g allparts.c part1.c part2.c part3.c
        gdb ./a.out

    Using list directive will run the main function of allparts.c.  
    To list individual part files partx.c, use `l partx.c:LINNUM`   
    To set breakpoint at specified line number in the part files, use `b FILENAME:LINNUM`

3.  
    