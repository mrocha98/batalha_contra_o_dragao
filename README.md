# Batalha contra o Dragão
Comande um guerreiro em uma intensa luta contra o Dragão!

```
                                               _   __,----'~~~~~~~~~`-----.__
                                        .  .    `//====-              ____,-'~`
                        -.            \_|// .   /||\\  `~~~~`---.___./
                  ______-==.       _-~o  `\/    |||  \\           _,'`
            __,--'   ,=='||\=_    ;_,_,/ _-'|-   |`\   \\        ,'
         _-'      ,='    | \\`.    '',/~7  /-   /  ||   `\.     /
       .'       ,'       |  \\  \_  "  /  /-   /   ||      \   /
      / _____  /         |     \\.`-_/  /|- _/   ,||       \ /
     ,-'     `-|--'~~`--_ \     `==-/  `| \'--===-'       _/`
               '         `-|      /|    )-'\~'      _,--"'
                           '-~^\_/ |    |   `\_   ,^             /\
                                /  \     \__   \/~               `\__
                            _,-' _/'\ ,-'~____-'`-/                 ``===\
                           ((->/'    \|||' `.     `\.  ,                _||
             ./                       \_     `\      `~---|__i__i__\--~'_/
            <_n_                     __-^-_    `)  \-.______________,-~'
             `B'\)                  ///,-'~`__--^-  |-------~~~~^'
             /^>                           ///,--~`-\
            `  `                                    
```

# Como rodar essa belezinha

Se você têm pavor do terminal/prompt de comando :scream:: 
- Clique em Clone or Download 
- Download ZIP 
- Extraia para o local de sua preferência 
- execute o arquivo .exe (Windows) / .out (Linux)

Caso não tenha, continue lendo!

# Compilação e execução

Presumindo que você tenha o GCC instalado na sua máquina e tenha clonado o repositório no local de sua preferência, digite:


- Linux:
```
gcc -std=c99 *.c -o dragon.out
./dragon.out
```

- Windows:
```
gcc -std=c99 *.c -o dragon.exe
start dragon.exe
```
Se você utiliza o Windows 10, é possível que o Smart Screen dê algum aviso de segurança, basta aceitar/concordar que o jogo iniciará normalmente ~confie em mim~.


# Avisos

- Os nomes do dragão e do guerreiro não devem ultrapassar 30 caracteres ~você pode alterar isso antes de compilar na diretiva TAM_NOME~
- Todos os arquivos, principalmente a pasta de ASCII artes, devem estar no mesmo diretório do arquivo executável
- Sugestões são bem vindas!
