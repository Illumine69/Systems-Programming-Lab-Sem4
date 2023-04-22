BEGIN {
    FS = ":"
}
{
    if($2 == "sauropod"){
        pos = index($6,"-")
        if(pos == 0){
            ts = te = int($6)
        }
        else{
            ts = int(substr($6,1,pos-1))
            te = int(substr($6,pos+1,length($6)-pos))
        }
        liv_time = (te + ts) / 2.0
        if( $3 == "" ){
            dino[liv_time] = dino[liv_time] "\n" $1 ":\n\t" "Living time: " liv_time " million years ago\n\t" "Length: unknown"
        }
        else{
            dino[liv_time] = dino[liv_time] "\n" $1 ":\n\t" "Living time: " liv_time " million years ago\n\t" "Length: " $3 " meters"
        }
    }
}
END{
    asorti(dino, sdino);
    for(time in sdino){
        print dino[sdino[time]]
    }
}