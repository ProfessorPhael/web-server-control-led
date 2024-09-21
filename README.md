### Web Server com ESP32 - Ligar e Apagar um LED  
#### (Informações em Inglês e Português)

---

#### **📘 Descrição / Description:**

Neste projeto, você aprenderá como configurar um **servidor web no ESP32** para controlar um LED remotamente. Através de um navegador web, você poderá **ligar** ou **apagar** o LED usando dois botões. O código será escrito em **C++** no **Arduino IDE**, utilizando bibliotecas específicas para conectividade Wi-Fi e gerenciamento do servidor web.

---

#### **📋 Requisitos / Requirements:**

- **ESP32** (como o ESP-WROOM-32)
- **Arduino IDE** (com suporte para placas ESP32 instalado)
- **LED** e um **resistor** de 220Ω
- Conexão Wi-Fi
- Cabo USB para programação

---

#### **🔧 Linguagem Utilizada / Language Used:**

- **C++**: O código é escrito em **C++**, no Arduino IDE, para programar o ESP32.
  
  - **Funções principais**:
    - **`setup()`**: Configura o ESP32, o LED e a rede Wi-Fi.
    - **`loop()`**: Lida com as requisições dos clientes no servidor web.

---

#### **📚 Bibliotecas Utilizadas / Libraries Used:**

1. **WiFi.h**:
   - Conecta o ESP32 à rede Wi-Fi, permitindo a comunicação sem fio.

2. **WebServer.h**:
   - Permite configurar um servidor web que responde a requisições HTTP e exibe a interface de controle do LED.

---

#### **🔌 Circuito / Circuit:**

- **LED**: Conecte o **ânodo (positivo)** do LED ao **pino D2** do ESP32 e o **cátodo (negativo)** ao **GND** com um resistor de **220Ω**.


---

#### **🔍 Explicação / Explanation:**

1. **Conexão Wi-Fi**:
   - O ESP32 conecta-se à rede Wi-Fi configurada com o **`ssid`** e a **`password`**.
   - A função **`WiFi.begin()`** inicia o processo de conexão, e o loop aguarda até que a conexão seja estabelecida.

2. **Servidor Web**:
   - O **`WebServer`** na porta **80** responde a requisições HTTP.
   - A rota **`"/"`** exibe a interface com dois botões para ligar e apagar o LED.
   - As rotas **`/led/on`** e **`/led/off`** controlam o estado do LED.

3. **Monitor Serial**:
   - O **Monitor Serial** é usado para depuração. Ele exibe o endereço IP do ESP32 quando a conexão Wi-Fi é estabelecida.

4. **Controle do LED**:
   - A função **`handleLedOn()`** liga o LED definindo o pino como **HIGH**.
   - A função **`handleLedOff()`** apaga o LED definindo o pino como **LOW**.

---

#### **⚙️ Passos para Configuração / Steps to Set Up:**

1. **Instalar a Biblioteca ESP32 no Arduino IDE**:
   - No **Arduino IDE**, siga as mesmas etapas mencionadas anteriormente para adicionar suporte à placa ESP32.

2. **Conectar o LED**:
   - Conecte o LED ao **pino D2** do ESP32 e ao **GND**, conforme o esquema descrito.

3. **Carregar o Código no ESP32**:
   - Selecione a placa correta (**ESP32 Dev Module**) e a porta adequada no Arduino IDE.
   - Carregue o código.

4. **Acessar o Servidor Web**:
   - Abra o **Monitor Serial** e localize o endereço IP do ESP32.
   - Acesse o IP no navegador (por exemplo: `http://192.168.1.100`).
   - Use os botões na página para **ligar** e **apagar** o LED.

---

#### **📈 Possíveis Melhorias / Possible Improvements:**

- **Estilizar a página HTML** com CSS para melhorar a aparência dos botões.
- Adicionar controle por **sliders** para ajustar a intensidade de brilho do LED (usando PWM).
- Expandir o projeto para controlar múltiplos LEDs ou outros dispositivos eletrônicos.

---

#### **🔗 Recursos Adicionais / Additional Resources:**

- [Documentação Oficial do ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Guia para Configuração do Arduino IDE com ESP32](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

---

Este guia detalha como controlar um LED via servidor web no ESP32. Se precisar de ajuda ou ajustes no código, é só falar!
