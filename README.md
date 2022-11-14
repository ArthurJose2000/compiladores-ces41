# compiladores-ces41

Para gerar o executável:

$ bison -d cminus.y && flex cminus.l && gcc -c *.c && gcc -o cminus *.o -lfl
$ flex cminus.l
$ gcc -c *.c
$ gcc -o cminus *.o -lfl

Para executar o programa:

$ ./cminus selsort.cm

(Em Mac pode ser que funcione com -ll no lugar de -lfl)