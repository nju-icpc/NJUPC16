for ((i = 0; i < 36; i++)); do
    echo '- name: ' "$((i+10))-secret";
    echo '  src: gen' ;
    echo '  flags:' "$((i))"; 
done
