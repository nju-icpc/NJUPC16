for ((i = 10; i < 25; i++)); do
    echo '- name:' "$((i))-secret";
    echo '  src:' "$((i))-secret.txt"; 
done
