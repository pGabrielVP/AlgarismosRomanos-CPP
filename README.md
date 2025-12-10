# AlgarismosRomanos-CPP

- [Compilando](#compilando)
	- [Windows](#windows)
	- [Linux](#linux)
- [Uso](#uso)

## Compilando

### Windows

#### Visual Studio Build Tools 2022
 
 Powershell de Desenvolvedor ` cl /EHsc /std:c++20 .\conversores\DeRomano.cpp .\conversores\ParaRomano.cpp .\Main.cpp /Feout.exe `

### Linux

#### g++

 No terminal ` g++ -std=c++20 conversores/ParaRomano.cpp conversores/DeRomano.cpp Main.cpp -o out.o ` 

## Uso

 `./out.o <numero>` para converter um número decimal para algarismos romanos
 
 `./out.o <string>` para converter algarismos romanos para um número decimal

O algoritmo suporta numeros maiores que 3999 usando _ (underscore). Eg. _XX retorna 10010

O maior número suportado pelo algoritmo é 3.999.999 (três milhões, novecentos e noventa e nove mil, novecentos e noventa e nove) em ambas direções

Para utlizar outro caractere no lugar de _ (underscore) basta atualizar a expressão regex e o algoritmo em conversores/DeRomano.cpp
