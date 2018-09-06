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

// Initialize pins of the stepper motor
void InitValve() {
  pinMode(StepPin, OUTPUT);
  pinMode(DirPin, OUTPUT);
  digitalWrite(StepPin, LOW);
  digitalWrite(DirPin, Fwd);
}

// Change stepper direction to forward
void GoForward() {
  digitalWrite(DirPin, Fwd);
}

// Change stepper direction to backwards
void GoBackward() {
  digitalWrite(DirPin, Bwd);
}

// Send signal to stepper driver for a single step
void Step() {
  digitalWrite(StepPin, HIGH);
  delay(1);
  digitalWrite(StepPin, LOW);
}

// Blocking move function to execute fixed number of steps
void Move(int Steps, bool Forward = true) {
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
  // Do steps
  for (int StepNo = 0; StepNo < Steps; StepNo++) {
    // Cap maximum steps per second
    if (millis() > LastStep + (1000 / StepFrequency)) {
      // Execute step
      if (Forward) {
        if (ValvePosition < StepsPerRevolution * ValveTurns) {
          Step();
          ValvePosition++;
          LastStep = millis();
        }
      } else {
        if (ValvePosition > 0) {
          Step();
          ValvePosition--;
          LastStep = millis();
        }
      } 
    }
    // Delay some time to cap maximum step frequency
    delay((1000 / StepFrequency) + 1);
  }
}

void Open(uint8_t Percent = 0) {
  if (Percent == 0) {
    // Consider valve fully closed
    ValvePosition = 0;
    // Open it fully
    Move(StepsPerRevolution * ValveTurns);
  } else {
    
  }
}

void Close(uint8_t Percent = 0) {
  if (Percent == 0) {
    // Consider valve fully open
    ValvePosition = StepsPerRevolution * ValveTurns;
    // Close it fully
    Move(StepsPerRevolution * ValveTurns, false);
  } else {
    
  }
}

// After calibration sequence valve is considered fullyclosed
void CalibrateValve() {
  // Open valve fully
  Open();
  // Close valve fully
  Close();
}
