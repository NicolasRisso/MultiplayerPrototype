# Multiplayer Prototype - Steam

## Exemplo de Documentação de Uso

[Link Para Documentação](https://www.notion.so/Multiplayer-Prototype-Exemplo-de-Documenta-o-de-Uso-1ceb9e574bc580cd8c6ed045744d10e5)

## Observações

- Caso não consigam encontrar o servidor pelo sistema de matchmaking, utilizem a funcionalidade **Invite Friend** na Steam para se conectar com amigos.
- Lembrem-se que o Steam ID 480 possui restrições regionais, o que pode limitar a descoberta de servidores em outras regiões.

## Descrição do Projeto

Multiplayer Prototype - Steam é um projeto experimental desenvolvido para testar a integração multiplayer utilizando a API da Steam. O foco principal é explorar funcionalidades de física com replicação e autenticação de servidor, criando uma experiência dinâmica e interativa em um ambiente de plataformas.

## Funcionalidades

- **Plataformas em Movimento:**  
  Plataformas que podem se mover autonomamente ou serem ativadas por triggers, oferecendo desafios dinâmicos durante o jogo.

- **Mudanças de Velocidade (Corrida):**  
  Mecanismo que permite aos jogadores aumentar sua velocidade com autenticação do servidor.

- **Interação com Objetos:**  
  Os jogadores podem pegar e soltar objetos utilizando física realista, criando oportunidades para puzzles e interações no ambiente.

- **Ativação de Botões (Triggers):**  
  Botões que, ao serem acionados, interagem com plataformas, incluindo a alteração de propriedades visuais, como a mudança de cor dos materiais das plataformas.

- **Replicação e Autenticação de Servidor:**  
  Implementação de sistemas de replicação de física e autenticação de servidor para garantir que todas as ações e interações sejam sincronizadas entre os jogadores, promovendo uma experiência multiplayer estável e segura.

## Tecnologias Utilizadas

- **Linguagens:** C++ e Blueprints (BP)  
  Uma implementação híbrida que permite aproveitar o poder e a flexibilidade do C++ juntamente com a facilidade de prototipação dos Blueprints.

- **Motor de Jogo:** Unreal Engine  
  Plataforma utilizada para o desenvolvimento e execução do projeto, com suporte robusto para multiplayer e física avançada.

- **Integração Multiplayer:** API da Steam  
  Responsável pela autenticação, comunicação entre clientes e gerenciamento das sessões multiplayer.

## Propósito e Objetivos

- **Teste de Integração Multiplayer:**  
  Validar a eficácia da API da Steam em um ambiente de jogo real, garantindo uma comunicação segura e estável entre os jogadores.

- **Exploração de Física Replicada:**  
  Desenvolver e testar mecânicas que envolvem física realista replicada, assegurando que todos os clientes visualizem interações consistentes, especialmente em plataformas e objetos interativos.

- **Aprendizado e Prototipagem:**  
  Fornecer uma base prática para desenvolvedores aprenderem e experimentarem com a combinação de C++ e Blueprints, explorando as vantagens de ambos os métodos de desenvolvimento.
