#define TRIG 9
#define ECHO 10
#define BUZZER 6

long duracion;
int distancia;

void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  duracion = pulseIn(ECHO, HIGH);

  distancia = duracion * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distancia);

  if (distancia <= 20) {

    digitalWrite(BUZZER, HIGH);

    Serial.println("ALERTA");

  } else {

    digitalWrite(BUZZER, LOW);

    Serial.println("NORMAL");
  }

  delay(500);
}
