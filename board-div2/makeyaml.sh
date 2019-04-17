for ((i = 2; i < 30; i++)); do
    echo '- name: ' "$((i+10))-secret";
    echo '  src: gen' ;
    echo '  flags:' "$((i))"; 
done
