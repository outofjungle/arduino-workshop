#define SENSOR A0

int sensor_value = 0;
long input_sum = 0;
int input_count = 0;
char msg[32];

void setup() {
  Serial1.begin(9600);
}

void loop() {
  int current_sensor_value = calculate_average( analogRead( SENSOR ) );
  
  if (current_sensor_value != sensor_value ) {
    sensor_value = current_sensor_value;
    sprintf( msg, "Current Value: %d", sensor_value );
    Serial1.println( msg );
  }

  delay( 500 );
}

int calculate_average(int value) {
  input_sum += value;
  input_count++;
  int average =  input_sum / input_count;  

  if (input_count > 10) {
    input_sum -= average;
    input_count = 10;
  }
  return average;
}
