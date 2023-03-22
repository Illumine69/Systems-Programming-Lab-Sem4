{
    dinotype[$2] = dinotype[$2] "\n\t" $1;
}
END {
    for(type in dinotype){
        print type ":" dinotype[type];
        print "Total count = " (split(dinotype[type], a, "\n\t") - 1) "\n";
    }
}