{
    if ($2 == "sauropod") {
        pos = index($6,"-")
        if (pos == 0) {
            ts = te = int($6)
        } else {
            ts = int(substr($6, 1, pos-1))
            te = int(substr($6, pos+1, length($6)-pos))
        }
        ##if ((ts <= 252) && (te >= 201)) { nt++; sumt += $3 }
        if ((ts >= 201) && te <= 252 && ts>=te) { nt++; sumt += $3 }
        else if ((ts >= 145) && (te <= 201) && ts>=te) { nj++; sumj += $3 }
        else if ((ts >= 65) && (te <= 145) && ts>=te) { nc++; sumc += $3 }
        else { printf("Period cannot be determined for %s (%d,%d)\n", $1, ts, te) }
    }   
}
END {
    printf("Average lengths of sauropod dinosaurs\n")
    printf("Triassic period (252-201 Ma) : %6.2f meters\n", sumt / nt)
    printf("Jurassic period (201-145 Ma) : %6.2f meters\n", sumj / nj)
    printf("Cretaceous period (145-65 Ma) : %6.2f meters\n", sumc / nc)
}