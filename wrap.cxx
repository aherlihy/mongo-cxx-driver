/home/ubuntu/llvm/build/bin/clang++ "$@"
rv="$?"
for last; do true; done
if [ -f "$last" ]; then
    if grep -q "StringData" "$last"; then
        echo "$last" >> "modified_files"
        newfile="$last.new"
        touch $newfile
        echo
        /home/ubuntu/llvm/build/bin/tooling_sample "$last" > $newfile
    fi
fi
return $rv
