# Instalador de programas para Linux

## Descrição

Este projeto tem como objetivo criar um instalador de programas de terceiros para Linux, para evitar desorganização em seu diretório de usuário e para que haja facilidade de acesso no desktop (ou menu de programas) e no terminal, especificamente os que não são pacotes (`.rpm` e `.deb`, por exemplo) e não possuem um instalador próprio. Podemos citar como exemplos os seguintes programas:

- Discord para Linux, empacotado em `.tar.gz`, que possui um arquivo .desktop e a imagem de um ícone em sua pasta raiz, mas não possui um instalador que conecte o programa com o menu de programas nem com o terminal;
- Postman para Linux, empacotado também em `.tar.gz`, que possui somente uma pasta com o arquivo binário executável sem nenhum instalador;
- Programas que utilizam Wine e são executados manualmente, definindo 2 variáveis de ambiente do Wine no terminal e executando o arquivo `.exe`, e muitas vezes temos trabalho extra de sempre lembrar onde o arquivo está e de redefinir variáveis de ambiente.

Inicialmente será feito para Linux Fedora 34, e posteriormente será validado em outras versões deste sistema. Após isso, a intenção é expandir para as principais distribuições Linux.

## Tecnologias

- C
- GTK 4

## Atualmente na versão 0.2

Layout criado no Figma: https://www.figma.com/file/Tf6UBtb1EuLN8E00Z4CQ07/Instalador?node-id=0%3A1
