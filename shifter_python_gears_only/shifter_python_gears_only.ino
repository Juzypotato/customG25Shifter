

const int shifter_X_pin = A4;
int shifter_X_value = 0;

const int shifter_Y_pin = A2;
int shifter_Y_value = 0;

const int shifter_Z_pin = A6;
int shifter_Z_value = 0;


int checkGear() {
  shifter_X_value = analogRead(shifter_X_pin);
  //Serial.println(shifter_X_value);
  shifter_X_value = map(shifter_X_value, 0, 680, -1, 1);
  //Serial.println(shifter_X_value);
  
  shifter_Y_value = analogRead(shifter_Y_pin);
  //Serial.println(shifter_Y_value);
  shifter_Y_value = map(shifter_Y_value, 200, 800, -1, 1);
  //Serial.println(shifter_Y_value);
  
  shifter_Z_value = analogRead(shifter_Z_pin);
  //Serial.println(shifter_Z_value);
  if(shifter_Z_value >= 1022){
    shifter_Z_value = 1;
    } else{
      shifter_Z_value = 0;
      }
  //Serial.println(shifter_Z_value);
  
  if(shifter_X_value == -1 && shifter_Y_value == 1 && shifter_Z_value == 0){
    return 1;
  } 
  else if(shifter_X_value == 1 && shifter_Y_value == -1 && shifter_Z_value == 1){
    return 7;
  }
  else if(shifter_X_value == -1 && shifter_Y_value == -1 && shifter_Z_value == 0){
    return 2;
  }
  else if(shifter_X_value == 0 && shifter_Y_value == 1 && shifter_Z_value == 0){
    return 3;
  }
  else if(shifter_X_value == 0 && shifter_Y_value == -1 && shifter_Z_value == 0){
    return 4;
  }
  else if(shifter_X_value == 1 && shifter_Y_value == 1 && shifter_Z_value == 0){
    return 5;
  }
  else if(shifter_X_value == 1 && shifter_Y_value == -1 && shifter_Z_value == 0){
    return 6;
  } else {
    return 0;
    }
  
}

void setup() {
  Serial.begin(9600);
  pinMode(shifter_Z_pin, INPUT);
}

void loop() {
  int currentGear = checkGear();
  Serial.print(currentGear);
  delay(1000/60);
}
