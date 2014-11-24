for last; do true; done

bname=$(basename "$last")
dname=$(dirname "$last")
fname="$dname""/tooled/i_""$bname"
/home/ubuntu/llvm/build/bin/tooling_sample "$last" > "$fname"

clang++ "$@" 
