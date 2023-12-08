# Portfólio

   Neste documento é apresentado uma especificação de uma aplicação para controle de energia elétrica durante o banho com as camadas de percepção, camada de rede, camada de middleware e camada de aplicativo.
![image](https://github.com/Duduseth/Portfolio/assets/67663334/61162294-cf1c-4dc6-81e6-94998e9c578a)

**Nome do Produto/Protótipo e de seus Componentes Principais:**


O protótipo a caixinha de banho é composto pelos componentes e estão organizados em 4 camadas.


**1 - Camada de percepção (Hardware):**

- ESP32;
- Placa RFID;
- TAG;
- Cabos de energia;
- Cabos de comunicação;
- Conectores;
- Relé.


**2 - Camada de rede:**

- Conexão internet;
- Equipamentos para conexão de internet (Modem, Roteadores, etc.);
- Cabos para as conexões.


**3 - Camada de middleware:**

- Programa/sistema para recepção dos dados;
- Banco de dados para guardar as informações.


**4 - Camada de aplicativo:**

- Programa/sistema para compilação e resultado dos dados a serem analisados.



**Missão do Produto/Protótipo:**

A missão do produto é promover o controle da quantidade do tempo de banho e facilitar o controle para redução dos custos com energia elétrica.


**Visão geral deste documento:**

Este documento está estruturado da seguinte maneira: na Seção 2 tem-se uma breve descrição das funções do aplicativo (produto); na Seção 3 encontra-se a descrição dos requisitos específicos, o modelo casos de uso e o modelo de classes; na Sessão 4 os Requisitos do Produtos; na Sessão 5 os Artefatos do produto.


**Descrição geral do Produto/Protótipo**

  Visando ajudar na diminuição dos custos com energia elétrica, a Caixinha de banho
inteligente visa limitar o período de banho por tempo. Cada pessoa terá uma tag que será
pré cadastrada e através do aplicativo cada tag cadastrada terá um período de tempo
determinado para que a caixinha de banho libere energia elétrica para o chuveiro, sendo
que ao término do tempo a energia é interrompida. No aplicativo será possível também
limitar a quantidade de banhos diários.


**Contexto para Produto/Protótipo:**

![image](https://github.com/Duduseth/Portfolio/assets/67663334/d44f1887-52de-4cca-b4c0-74dfd4a1957c)

  
**Requisitos do Produto/Protótipo**

![image](https://github.com/Duduseth/Portfolio/assets/67663334/d948c714-ce6a-46a5-8224-340f6a2f89bd)

**Artefatos do Produto/Protótipo**

TELA DE LOGIN:

![image](https://github.com/Duduseth/Portfolio/assets/67663334/5e0f3156-09b7-43be-aa0d-958ae54d89e8)

TELA PRINCIPAL:

![image](https://github.com/Duduseth/Portfolio/assets/67663334/d6280d1b-382f-4638-a6ce-fa087d2a6c4e)

CADASTRANDO USUÁRIO:

![image](https://github.com/Duduseth/Portfolio/assets/67663334/652681b9-d1d3-4a5c-b41b-ecc2bc318dcb)

USUÁRIO CADASTRADO APARECE NA LISTA:

![image](https://github.com/Duduseth/Portfolio/assets/67663334/bdacc2bb-644d-4351-a62d-26df296fc228)

EXCLUINDO UM USUÁRIO:

![image](https://github.com/Duduseth/Portfolio/assets/67663334/1ce7ec0b-63b6-4629-a767-c486fbf00538)

USUÁRIO EXCLUIDO:

![image](https://github.com/Duduseth/Portfolio/assets/67663334/07c7c76b-a212-4a15-b1ca-5a1a074f25b2)


**Visão Arquitetural – Arquitetura do Produto**

![image](https://github.com/Duduseth/Portfolio/assets/67663334/5028ff52-7b88-4a4d-a6f6-573365d8d5e0)

**Visão Estrutural – Diagrama de Blocos (IoT)**

![image](https://github.com/Duduseth/Portfolio/assets/67663334/2cb1f4b4-a784-4a31-b8b8-bdeaed0d9676)

**Visão Comportamental – Diagramas de Máquina de Estados**

![image](https://github.com/Duduseth/Portfolio/assets/67663334/6bc1e551-3020-412d-966a-5c5f723d6a6d)
















