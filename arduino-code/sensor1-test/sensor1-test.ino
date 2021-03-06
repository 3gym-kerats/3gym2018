#include <Servo.h>

Servo myservo;  // δημιουργήστε ένα αντικείμενο myservo για να ελέγχεται το servo motor
//  6 αντικείμενα servo μπορούνα δημιουργηθούν στις περισσότερες πλακέτες

int pos = 0;    // μεταβλητή για την αποθήκευση της θέσης servo
int trigPin1 = 9;
int echoPin1 = 10;



void setup() {
  myservo.attach(3);  //συνδέει το servo στον ακροδέκτη 3 με το αντικείμενο servo
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(13, OUTPUT);   // setting the pin modes, the "13" buzer  
 
}



void servomove(){
for (pos = 0; pos <= 180; pos += 10) { // πηγαίνει από 0 μοίρες έως 180 μοίρες
    // σε βήματα 1 βαθμού
    myservo.write(pos);              // πείτε στο σερβο να πάει στη θέση του σε μεταβλητή 'pos'
    delay(5);                       // περιμένει 15ms για το σερβο να φτάσει στη θέση
  }
  for (pos = 180; pos >= 0; pos -= 10) { // πηγαίνει από 180 μοίρες έως 0 μοίρες
    myservo.write(pos);              // πείτε στο σερβο να πάει στη θέση του σε μεταβλητή 'pos'
    delay(5);                       // περιμένει 15ms για το σερβο να φτάσει στη θέση
  }
}

void sensor1(){ // Αυτή η λειτουργία είναι για τον πρώτο αισθητήρα , των τοίχων
  int duration1, distance1;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
      Serial.print("1st Sensor: ");
      Serial.print(distance1); 
      Serial.print("cm    ");
  if (distance1 <=60 && distance1 >=5) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.                                                                                                                                                                                                                             
     servomove(); 
    } else {
      // Μην κάνεις  τίποτα
  }
}


void loop() {
Serial.println("\n");
sensor1();  // ανιχνευση τοιχου
delay(150);
}
