#!/usr/bin/gawk -f
{
    if ($2 == "large theropod") {
        n = split($7, country, ", ");
        for (i=1; i<=n; ++i) { tlist[country[i]] = tlist[country[i]] " " $1 }
    }
}
END {
    for (c in tlist) {
        printf("%-15s: %s\n", c, tlist[c])
    }
}