# AlgarismosRomanos-CPP

- [Compilando](#compilando)
	- [Linux](#linux)
- [Uso](#uso)

## Compilando

### Linux

 Executa o código no terminal ` c++ conversores/ParaRomano.cpp conversores/DeRomano.cpp Main.cpp -o out.o ` 

## Uso

 `./out.o <numero>` para converter um número decimal para algarismos romanos
 
 `./out.o <numero>` para converter algarismos romanos para um número decimal

O algoritmo suporta numeros maiores que 3999 usando _ (underscore). Eg. _XX retorna 10010

O maior número suportado pelo algoritmo é 3.999.999 (três milhões, novecentos e noventa e nove mil, novecentos e noventa e nove) em ambas direções

Para utlizar outro caractere no lugar de _ (underscore) basta atualizar a expressão regex e o algoritmo em conversores/DeRomano.cpp
