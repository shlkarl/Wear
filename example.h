/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-web-server-physical-button/
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Подключаем библиотеки
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

// Укажите свой учетные данные сети
const char* ssid = "qwe";
const char* password = NULL;

const char* PARAM_INPUT_1 = "state";

const int output = 2;
const int buttonPin = 4;

// Переменные
int ledState = LOW;          // текущее состояние выхода
int buttonState;             // состояние кнопки
int lastButtonState = LOW;   // предыдущее состояние кнопки

// следующие переменные будут типа unsigned long потому, что время
// в миллисекундах достаточно быстро выйдет за пределы типа int
unsigned long lastDebounceTime = 0;  // время, когда состояние пина изменилось последний раз
unsigned long debounceDelay = 50;    // задержка для защиты от дребезга контактов; увеличьте, если наблюдается самопроизвольное мигание на выходе


// Создаем сервер (80 порт)
AsyncWebServer server(80);
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}
    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; border-radius: 34px}
    .slider:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px; background-color: #fff; -webkit-transition: .4s; transition: .4s; border-radius: 68px}
    input:checked+.slider {background-color: #2196F3}
    input:checked+.slider:before {-webkit-transform: translateX(52px); -ms-transform: translateX(52px); transform: translateX(52px)}
  </style>
</head>
<body>
  <h2>ESP Web Server</h2>
  %BUTTONPLACEHOLDER%
<script>function toggleCheckbox(element) {
  var xhr = new XMLHttpRequest();
  if(element.checked){ xhr.open("GET", "/update?state=1", true); }
  else { xhr.open("GET", "/update?state=0", true); }
  xhr.send();
}
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var inputChecked;
      var outputStateM;
      if( this.responseText == 1){ 
        inputChecked = true;
        outputStateM = "On";
      }
      else { 
        inputChecked = false;
        outputStateM = "Off";
      }
      document.getElementById("output").checked = inputChecked;
      document.getElementById("outputState").innerHTML = outputStateM;
    }
  };
  xhttp.open("GET", "/state", true);
  xhttp.send();
}, 1000 ) ;
</script>
</body>
</html>
)rawliteral";

// Заменяет заполнитель на кнопку на веб-странице
String processor(const String& var){
  //Serial.println(var);
  if(var == "BUTTONPLACEHOLDER"){
    String buttons ="";
    String outputStateValue = outputState();
    buttons+= "<h4>Output - GPIO 2 - State <span id=\"outputState\"></span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"output\" " + outputStateValue + "><span class=\"slider\"></span></label>";
    return buttons;
  }
  return String();
}

String outputState(){if(digitalRead(output)) return "checked";
    else return "";
return "";}

void setup(){
  // Запускаем монитор порта
  Serial.begin(115200);

  pinMode(output, OUTPUT);
  digitalWrite(output, LOW);
  pinMode(buttonPin, INPUT);
  
  // Подключаемся к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Выводим IP адрес платы
  Serial.println(WiFi.localIP());

  // Маршрут для стартовой веб-страницы
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){request->send_P(200, "text/html", index_html, processor);});

  // Отправляем запрос GET <ESP_IP>/update?state=<inputMessage>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    String inputParam;
    // получаем значение input1 <ESP_IP>/update?state=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
      digitalWrite(output, inputMessage.toInt());
      ledState = !ledState;
    }
    else {
      inputMessage = "No message sent";
      inputParam = "none";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  // Отправляем запрос GET на <ESP_IP>/state
  server.on("/state", HTTP_GET, [] (AsyncWebServerRequest *request) { request->send(200, "text/plain", String(digitalRead(output)).c_str());});
  // Запускаем сервер
  server.begin();
}
  
void loop() {
  // считываем состояние переключателя в локальную переменную:
  int reading = digitalRead(buttonPin);
  // подождите немного и проверьте не изменился ли сигнал
  // (с LOW на HIGH) с момента последнего нажатия чтобы исключить дребезг:
  // Если состояние изменилось из-за дребезга или случайного нажатия:
  if (reading != lastButtonState) {
    // сбрасываем таймер 
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // вне зависимости от действительного состояния, 
    //если оно длится больше задержки, то принимаем его за текущее:
    // если состояние кнопки изменилось:
    if (reading != buttonState) {
      buttonState = reading;
      // включаем светодиод только если сигнал HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // выводим состояние светодиода:
  digitalWrite(output, ledState);

  // сохраняем значение в lastButtonState:
  lastButtonState = reading;
}
