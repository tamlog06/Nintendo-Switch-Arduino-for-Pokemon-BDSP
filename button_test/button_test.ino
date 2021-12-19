const int DIN_PIN = 7;

void setup(){
    pinMode( DIN_PIN, INPUT_PULLUP );
    Serial.begin( 19200 );
}

void loop(){
    
//    value = 
    if (digitalRead( DIN_PIN ) == 1) {
        Serial.println( "High" );
      } else {
        Serial.println( "Low" );
    }
    
    delay( 10 );
}
