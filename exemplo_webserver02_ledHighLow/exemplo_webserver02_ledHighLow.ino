#include <WiFi.h>        // Biblioteca para gerenciar a conexão Wi-Fi
#include <WebServer.h>    // Biblioteca para criar o servidor web

// Defina o nome da rede Wi-Fi (SSID) e a senha (PASSWORD)
const char* ssid = "Aldivino-Repetidor";
const char* password = "ivonete1964";

// Cria uma instância do servidor web na porta 80
WebServer server(80);

// Defina o pino do LED
const int ledPin = 4;
bool ledState = LOW;  // Estado inicial do LED (desligado)

// Função que será chamada quando acessar a rota "/"
void handleRoot() {
  // Cria a página HTML com dois botões para controlar o LED
  String html = "<h1>Controle do LED</h1><p>LED ";
  html += (ledState) ? "Ligado" : "Desligado";
  html += "</p><p><a href=\"/on\"><button>Ligar</button></a></p>";
  html += "<p><a href=\"/off\"><button>Desligar</button></a></p>";
  
  server.send(200, "text/html", html);
}

// Função que liga o LED
void handleLedOn() {
  ledState = HIGH;  // Atualiza o estado do LED
  digitalWrite(ledPin, ledState);  // Liga o LED
  server.sendHeader("Location", "/");  // Redireciona para a página principal
  server.send(303);  // Código 303 para redirecionamento
}

// Função que desliga o LED
void handleLedOff() {
  ledState = LOW;  // Atualiza o estado do LED
  digitalWrite(ledPin, ledState);  // Desliga o LED
  server.sendHeader("Location", "/");  // Redireciona para a página principal
  server.send(303);  // Código 303 para redirecionamento
}

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);

  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);  // Garante que o LED comece desligado

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Conectando ao Wi-Fi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Conectado ao Wi-Fi");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Define as rotas do servidor web
  server.on("/", handleRoot);      // Página principal
  server.on("/on", handleLedOn);   // Rota para ligar o LED
  server.on("/off", handleLedOff); // Rota para desligar o LED
  
  // Inicia o servidor
  server.begin();
  Serial.println("Servidor iniciado");
}

void loop() {
  // Mantém o servidor rodando
  server.handleClient();
}
