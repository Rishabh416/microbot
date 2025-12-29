#include <Arduino.h>

const int m1pos = 0;  const int m1neg = 1;
const int m2pos = 2;  const int m2neg = 3;
const int m3pos = 4;  const int m3neg = 5;
const int em1pos = 8; const int em1neg = 9;
const int em2pos = 11; const int em2neg = 12;

void setup() {
  Serial.begin(115200);
  
  int pins[] = {m1pos, m1neg, m2pos, m2neg, m3pos, m3neg, em1pos, em1neg, em2pos, em2neg};
  for (int i = 0; i < 10; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

void stopAll() {
  digitalWrite(m1pos, LOW); digitalWrite(m1neg, LOW);
  digitalWrite(m2pos, LOW); digitalWrite(m2neg, LOW);
  digitalWrite(m3pos, LOW); digitalWrite(m3neg, LOW);
  digitalWrite(em1pos, LOW); digitalWrite(em1neg, LOW);
  digitalWrite(em2pos, LOW); digitalWrite(em2neg, LOW);
}

void loop() {
  if (Serial.available() > 0) { 
    String command = Serial.readStringUntil('\n');
    command.trim(); 
    if (command == "stop") {
      stopAll();
      Serial.println("All motors stopped.");
      return;
    }

    int motor = command.substring(0, 1).toInt();
    char direction = command.charAt(command.length() - 1);
    int pwmValue = command.substring(1, command.length() - 1).toInt();

    int posPin, negPin;
    switch (motor) {
      case 1: posPin = m1pos; negPin = m1neg; break;
      case 2: posPin = m2pos; negPin = m2neg; break;
      case 3: posPin = m3pos; negPin = m3neg; break;
      case 4: posPin = em1pos; negPin = em1neg; break;
      case 5: posPin = em2pos; negPin = em2neg; break;
      default:
        Serial.println("Wrong motor");
        return;
    }

    if (direction == 'p') {
      analogWrite(negPin, 0);
      analogWrite(posPin, pwmValue); 
      Serial.printf("Motor %d Forward at %d\n", motor, pwmValue);
    } else if (direction == 'n') {
      analogWrite(posPin, 0);
      analogWrite(negPin, pwmValue);
      Serial.printf("Motor %d Reverse at %d\n", motor, pwmValue);
    } else {
      Serial.println("Invalid direction. Use 'p' or 'n'");
    }
  }
}