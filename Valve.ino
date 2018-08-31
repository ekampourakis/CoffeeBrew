// Stepper Pinout
#define StepPin  8
#define DirPin   7

// Valve direction
#define Fwd   LOW
#define Bwd   HIGH

// Maximum allowed steps per second
#define StepFrequency   50
// Required steps per motor revolution
#define StepsPerRevolution  200
// Valve revolution range
#define ValveTurns      5

unsigned long LastStep = 0;

// On boot consider valve closed
// Ranges from 0-MaxSteps open
int ValvePosition = 0;
// On boot stepper direction is forward
bool IsForward = true;

void InitValve() {
  pinMode(StepPin, OUTPUT);
  pinMode(DirPin, OUTPUT);
  digitalWrite(StepPin, LOW);
  digitalWrite(DirPin, Fwd);
}

void GoForward() {
  digitalWrite(DirPin, Fwd);
}

void GoBackward() {
  digitalWrite(DirPin, Bwd);
}

void Step(bool Forward = true) {
  // Set the direction if needed
  if (Forward) {
    if (!IsForward) {
      GoForward();
    }
  } else {
    if (IsForward) {
      GoBackward();
    }
  }
  // Cap maximum steps per second
  if (millis() > LastStep + (1000 / StepFrequency)) {
    // Execute step
    if (Forward) {
      if (ValvePosition < StepsPerRevolution * ValveTurns) {
        
      }
    } else {
      
    }
    digitalWrite(StepPin, HIGH);
    delay(1);
    digitalWrite(StepPin, LOW);
    if (Forward) {
      ValvePosition++;
    } else {
      ValvePosition--;
    }
    LastStep = millis();
  }
}

void Open(uint8_t Percent = 0) {
  if (Percent == 0) {
    // Open it fully
    
  } else {
    
  }
}

void Close(uint8_t Percent = 0) {
  if (Percent == 0) {
    // Close it fully
  } else {
    
  }
}

void CalibrateValve() {
  
}



