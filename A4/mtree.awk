#!/usr/bin/gawk -f

# run the file using `chmod 755; ./mtree.awk mtree.txt`
# if Permission is denied, use `gawk -f mtree.awk mtree.txt`

function prntree(n,i){
    for(i = 1; i <= n; i++){
        printf("%10s :  ID = %3s Left Child = %-10s Right child = %-10s\n", K[i], H[K[i]], K[L[H[K[i]]]], K[R[H[K[i]]]]);
    }
}

function findroot(n,i){
    for(i = 1; i <= n; i++){
        if(int(P[i]) < 1 || int(P[i]) > n){
            return i;
        }
    }
}

function inorder(i){
    if(int(i) < 1 || int(i) > n){
        return;
    }
    inorder(L[i]);
    printf("%10s", K[i]);
    if(++num_order % 5 == 0){
        printf("\n");
    }
    inorder(R[i]);
    return;
}

BEGIN{
    FS = ":"
    num_node = 1    # use to assign ID to nodes
}

{
    if(NR == 1) { n = $1 }
    else{
        if(done[$1] != 1){  # done[] stores 1 if ID has been assigned to node
            H[$1] = num_node++
            K[H[$1]] = $1
            done[$1] = 1
        }
        pos = index($2,",")
        split($2, A, ",")
        if(A[1] != ""){     # A[1] has the left child
            if(done[A[1]] != 1){
                H[A[1]] = num_node++
                K[H[A[1]]] = A[1]
                done[A[1]] = 1
            }
            L[H[$1]] = H[A[1]]
            P[H[A[1]]] = H[$1]
        }
        if(A[2] != ""){     # A[2] has the right child
            if(done[A[2]] != 1){
                H[A[2]] = num_node++
                K[H[A[2]]] = A[2]
                done[A[2]] = 1
            }
            R[H[$1]] = H[A[2]]
            P[H[A[2]]] = H[$1]
        }
    }
}

END{
    print "Going to read tree with " n " nodes\n"
    prntree(n)
    print "       ...\n"
    print "The root node has ID " findroot(n) " and key \"" K[findroot(n)] "\"\n"
    print "Inorder listing of the keys:"
    num_order = 0  # keeps track of number of keys printed in inorder
    inorder(findroot(n))
    print "\n       ...\n"
    print "Bye..."
}