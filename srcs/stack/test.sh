#! /bin/bash

clang++ -Wall -Werror -Wextra -std=c++98 -g -D NAMESPACE=ft -D FT=1 stack.cpp -o stack.ft.out

clang++ -Wall -Werror -Wextra -std=c++98 -g -D NAMESPACE=std -D FT=0 stack.cpp -o stack.std.out

./stack.ft.out > ft.log

./stack.std.out > std.log

diff ft.log std.log > diff.out

printf $YELLOW"running main.ft.out...\n"$RESET
if [[ $1 = "-v" ]]
then
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.out ./stack.ft.out
else
    START_TIME=$(perl -MTime::HiRes -e 'printf("%.0f\n",Time::HiRes::time()*1000)')
    ./stack.ft.out
    END_TIME=$(perl -MTime::HiRes -e 'printf("%.0f\n",Time::HiRes::time()*1000)')
    echo "elapsed time ft: $(($END_TIME - $START_TIME)) ms"
fi

# run main.std.out and save output to main.std.output
printf $YELLOW"running main.std.out...\n"$RESET
START_TIME=$(perl -MTime::HiRes -e 'printf("%.0f\n",Time::HiRes::time()*1000)')
./stack.std.out
END_TIME=$(perl -MTime::HiRes -e 'printf("%.0f\n",Time::HiRes::time()*1000)')
echo "elapsed time std: $(($END_TIME - $START_TIME)) ms"


sleep 10
rm ft.log std.log stack.ft.out stack.std.out output.ft.out output.std.out diff.out valgrind.out
