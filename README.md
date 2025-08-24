# Projeto-Integrado-II
Este projeto, desenvolvido para uma disciplina da faculdade, visa a criação de um aplicativo desktop simples para o controle geral de operações em uma rede farmacêutica.

Para executar o programa é necessária a instalação do pacote Conio2, segue o link para download do pacote e o passo a passo de como instalar no Dev-C++:
https://sourceforge.net/projects/orwelldevcpp
https://sourceforge.net/projects/conio/files/devpak/CONIO%202.0/conio-2.0-1mol.DevPak/download
Após instalar o Dev-C++ e baixar o pacote Conio2:
1. Abra o Dev-C++;
2. Na barra superior vá em "Ferramentas\Package Manager" e clique em install;
3. Vá para a pasta em que o pacote baixado está, selecione o mesmo e instale;
4. Na barra superior vá em "Ferramentas\Opções do Compilador";
5. Altere o compilador para 32-bits Release, na caixa inferior escreva "-static-libgcc -lconio" e clique em "OK";
6. Na barra superior vá em "Ferramentas\Opções do ambiente" e clique diretórios;
7. Altere o "diretório padrão do usuário" para onde está localizado o Dev-C++, por padrão ele fica em "C:\Program Files (x86)\Dev-Cpp\", e clique em "OK";
8. Vá para a pasta de instalação do Dev-C++, geralmente localizado em "C:\Program Files (x86)\Dev-Cpp\";
9. Abra a pasta "include" e copie o arquivo "conio2.h";
10. Volte para a pasta principal, vá para "MinGW64\include" e cole o arquivo lá;
11. Volte para a pasta principal, abra a pasta "lib" e copie os arquivos da pasta;
12. Volte para a pasta principal, vá para "MinGW64\lib32" e cole os arquivos lá;
13. Abra o código e teste;
