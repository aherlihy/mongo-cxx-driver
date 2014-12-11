clang++ "$@"
rv="$?"

for last; do true; done

if grep -q "StringData" "$last"; then
    /home/ubuntu/llvm/build/bin/tooling_sample "$last" > tmp_file
    touch tmp_file
    if diff "$last" tmp_file > /dev/null; then
        cp -r tmp_file "$last"
        echo "$last" >> modified_files
    fi
    rm tmp_file
fi

return $rv
