Sprint 3 Edge Computing
👥 Integrantes

Vitor Rodrigues Tigre – RM: 561746
Josué Faria da Silva – RM: 563819
Mariana Silva Oliveira – RM: 564241
Jonas Esteves França – RM: 564143
Augusto Valério – RM: 562185

📖 Descrição do Projeto

Este projeto tem como objetivo simular a coleta e o envio de dados biométricos utilizando um ESP32 integrado à plataforma ThingSpeak para armazenamento e visualização.

Os dados simulados são:
Frequência cardíaca (bpm)
Nível de oxigênio no sangue (%)

Aceleração nos eixos X, Y e Z

O ESP32 gera valores aleatórios para cada parâmetro e os envia periodicamente ao ThingSpeak através de requisições HTTP.

🏗️ Arquitetura Proposta

O ESP32 conecta-se à rede Wi-Fi configurada no código.

Os dados (batimentos, oxigênio e aceleração) são gerados de forma simulada utilizando a função random().

Esses dados são enviados para o ThingSpeak através de uma requisição HTTP.

O ThingSpeak armazena os valores nos respectivos campos do canal, permitindo sua visualização em gráficos.

🔧 Recursos Necessários

Placa ESP32

Acesso à internet (Wi-Fi)

Conta no ThingSpeak e chave de API para envio dos dados

(Obs: Os sensores de batimento, oxigênio e acelerômetro são simulados no código, não sendo necessário hardware adicional.)

▶️ Instruções de Uso

Instale o Arduino IDE e configure o suporte ao ESP32.

Abra o código fornecido no Arduino IDE.

Configure:

Nome e senha da rede Wi-Fi:

const char* ssid = "NOME_DA_REDE";
const char* password = "SENHA";


Chave de API do seu canal ThingSpeak:

String apiKey = "SUA_CHAVE_DE_API";


Conecte o ESP32 ao computador e faça o upload do código.

Abra o Serial Monitor (115200 baud) para acompanhar o envio dos dados.

Acesse seu canal no ThingSpeak para visualizar os gráficos gerados.
