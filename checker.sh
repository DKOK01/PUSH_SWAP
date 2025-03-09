while true; do
    args=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
    i=$(./push_swap $args | wc -l)
    status=$(./push_swap $args | ./checker_linux $args)

    if [[ "$i" -gt 700 || "$status" == "KO" ]]; then
        printf "\e[31mError: %d instructions\e[0m\n" "$i"
        printf "\e[31mArgs: %s\e[0m\n" "$args"
        break
    fi

    printf "\e[32mPass, tested with %d instructions\e[0m\n" "$i"
    sleep 0.05
done

