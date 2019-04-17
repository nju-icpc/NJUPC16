for ((i = 100; i < 115; i++)); do
    echo '- name: ' "$i-shortrand";
    echo '  src: shortrand.py' ;
    echo '  flags:' "$((4328527934 + i))"; 
done
