### Practice exercises:

1.  You can use the `--dry-run` or `-n` flag with the make command to see what commands would be executed for updating the targets, without actually rebuilding them. This flag will print out the commands that would be executed by make, but without actually running them.

    For example, if you have a target called `foo` that needs rebuilding, you can run the following command to see what commands would be executed for updating it:       

        make --dry-run foo

    >This will output the commands that would be executed to rebuild the foo target, but without actually rebuilding it.
    
    You can also use wildcards to specify multiple targets that need rebuilding, like so:       
            
        make --dry-run *.o

    >This will show you the commands that would be executed for rebuilding all object files in the current directory that need updating.

2.  You can force make to rebuild a target and all its dependencies, even if they are already up-to-date, by using the `-B` or `--always-make` flag.

    When you use the -B or --always-make flag, make will ignore the timestamps of the files and always rebuild the specified target and all its dependencies. This is useful when you want to ensure that everything is rebuilt from scratch, regardless of whether the files appear to be up-to-date or not.

    For example, to force make to rebuild the target `foo` and all its dependencies, you can run the following command:       

        make -B foo OR make --always-make foo

3.  Running this makefile results in:       

        make: Circular c <- a dependency dropped.
        make: Circular c <- b dependency dropped.
        Building c
        make: Circular b <- a dependency dropped.
        Building b
        Building a
    This message indicates that Make has detected the **circular dependency** (Circular dependencies occur when two or more targets in a makefile depend on each other, either directly or indirectly. When a circular dependency exists, it can cause Make to enter an infinite loop, and the build process will never finish) and has dropped one of the dependencies to break the cycle.
    
    Specifically, Make has dropped the dependencies between c and a, c and b, and b and a. This means that when the targets are built, some of the dependencies will not be taken into account, which may lead to incorrect results or missing files.

4.  The `make` command will stop building when it encounters an error:      

        /bin/sh: 1: ecko: not found
        make: *** [makefile:4: b] Error 127
    
    `make -k` will continue building other targets even if one target fails:        
    
        /bin/sh: 1: ecko: not found
        make: *** [makefile:4: b] Error 127
        Building c
        make: Target 'a' not remade because of errors.
        
    `make -i` will ignore errors for individual targets and continue building other targets:        
    
        /bin/sh: 1: ecko: not found
        make: [makefile:4: b] Error 127 (ignored)
        Building c
        Building a




