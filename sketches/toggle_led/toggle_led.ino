
#define LED 9

String buffer = "";
int command = 0;

void setup() {
  Serial1.begin( 9600 );  
  pinMode( LED, OUTPUT );    
}

void loop() {
  if ( Serial1.available() ) {
    buffer = Serial1.readString();
    command = buffer.toInt();
    if ( command != 0 ) {
      digitalWrite( LED, HIGH );
    } else {
      digitalWrite( LED, LOW );
    }
  }
}

