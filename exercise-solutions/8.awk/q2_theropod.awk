#!/usr/bin/gawk -f
{
    if ($2 == "large theropod") {
        n = split($7, country, ", ");
        for (i=1; i<=n; ++i) { tlist[country[i]] = tlist[country[i]] " " $1 }
    }
}
END {
    asorti(tlist, slist);
    for (c in slist) {
        printf("%-15s: %s\n",slist[c], tlist[slist[c]])
    }
}