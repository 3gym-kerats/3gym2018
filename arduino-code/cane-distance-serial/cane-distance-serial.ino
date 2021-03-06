#include <Servo.h>

Servo myservo;  // δημιουργήστε ένα αντικείμενο myservo για να ελέγχεται το servo motor
//  6 αντικείμενα servo μπορούνα δημιουργηθούν στις περισσότερες πλακέτες

int pos = 0;    // μεταβλητή για την αποθήκευση της θέσης servo
int trigPin1 = 9;
int echoPin1 = 10;
int trigPin2 = 12;
int echoPin2 = 11;
int duration = 100 ;

void setup() {
    myservo.attach(3);  //συνδέει το servo στον ακροδέκτη 3 με το αντικείμενο servo
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void beep(){
   // παίξε έναν τόνο στον ακροδέκτη 13
  tone(13, 340, duration);
  delay(duration);
  // απενεργοποιήστε τη λειτουργία τόνου για τον ακροδέκτη 13
  noTone(13);
}

void servomove(){ // ρουτίνα εξυπηρέτησης servo κινητήρα
for (pos = 0; pos <= 180; pos += 10) { // pos=να παίρνει τιμές 0 εως 180 ανά 10
    // σε βήματα 1 βαθμού
    myservo.write(pos);              //ο servo να τεθεί σε γωνίες από 0 εως 180 μοίρες
    delay(5);                       // καθυστέρηση 5ms για το σερβο να φτάσει στη θέση προορισμού 
  }
  for (pos = 180; pos >= 0; pos -= 10) { //pos=να παίρνει τιμές 180 εως 0 κατά 10
    myservo.write(pos);              // ο servo να τεθεί σε γωνίες από 180 εως 0 μοίρες
    delay(5);                       //  καθυστέρηση 5ms για το σερβο να φτάσει στη θέση προορισμού 
  }
}

void sensor1(){ // Αυτή η ρουτίνα είναι για τον πρώτο αισθητήρα ,  ανίχνευση τοίχων
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

void sensor2(){ //Αυτή η ρουτίνα είναι για τον δεύτερο αισθητήρα , ανίχνευση πεζοδρόμιου
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
      Serial.print("2nd Sensor: ");
      Serial.print(distance2); 
      Serial.print("cm    ");  
    if (distance2 <=15 && distance2 >=1) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.
     duration = 600;
     beep();
    } else if (distance2 <=40 && distance2 >=16) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.
      delay(250);
     duration = 300;
     beep();   
     } else if (distance2 <=65 && distance2 >=41) {  // Αλλάξτε τον αριθμό για μεγάλες ή μικρές αποστάσεις.
      delay(500);
     duration = 50;
     beep();    
    } else {
      // Μην κάνεις τίποτα
  }  
 }
 
void loop() {
Serial.println("\n");
sensor1();
delay(150);
sensor2();
delay(150);
}
