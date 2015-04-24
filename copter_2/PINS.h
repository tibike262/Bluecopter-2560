
#define ACC_X_OFFSET -29
#define ACC_Y_OFFSET -42
#define ACC_Z_OFFSET 1027

#define GYRO_X_OFFSET  13,56902
#define GYRO_Y_OFFSET  -1,80459
#define GYRO_Z_OFFSET  0,00210

#define SPLIT  0.99 //COMP-filter nr
#define RadToDeg 180.0/PI 
#define  ACC_HPF_NR  98  //high pass filter nr
#define  GYRO_HPF_NR 0   //high pass filter nr
#define  GYRO_MAF_NR  2  //Moving average filter nr

#define THRO_SIGNAL_IN 0 // INTERRUPT 0 = DIGITAL PIN 2 - use the interrupt number in attachInterrupt
#define THRO_SIGNAL_IN_PIN 2 // INTERRUPT 0 = DIGITAL PIN 2 - use the PIN number in digitalRead

#define AILE_SIGNAL_IN 1
#define AILE_SIGNAL_IN_PIN 3

#define ELEV_SIGNAL_IN 5
#define ELEV_SIGNAL_IN_PIN 18

#define RUDD_SIGNAL_IN 4
#define RUDD_SIGNAL_IN_PIN 19

#define NEUTRAL_AILE 1500
#define NEUTRAL_ELEV 1500
#define NEUTRAL_RUDD 1500

//Motor Pins
#define MOTOR0  10
#define MOTOR1  11
#define MOTOR2  9
#define MOTOR3  8

//-------PID Config----------

#define ROLL_PID_KP  0.250
#define ROLL_PID_KI  0.950
#define ROLL_PID_KD  0.011
#define ROLL_PID_MIN  -50.0
#define ROLL_PID_MAX  50.0

#define PITCH_PID_KP  0.250
#define PITCH_PID_KI  0.950
#define PITCH_PID_KD  0.011
#define PITCH_PID_MIN  -50.0
#define PITCH_PID_MAX  50.0

#define YAW_PID_KP  0.680
#define YAW_PID_KI  0.500
#define YAW_PID_KD  0.0001
#define YAW_PID_MIN  -50.0
#define YAW_PID_MAX  50.0

#define ANGLEX_KP 5.0
#define ANGLEX_KI 0.02
#define ANGLEX_KD -0.015
#define ANGLEX_MIN -100.0
#define ANGLEX_MAX 100.0

#define ANGLEY_KP 5.0
#define ANGLEY_KI 0.02
#define ANGLEY_KD -0.015
#define ANGLEY_MIN -100.0
#define ANGLEY_MAX 100.0

//-------------------------

//.....RX Config............
#define THROTTLE_RMIN  1092
#define THROTTLE_RMAX  1912
#define THROTTLE_WMIN  MOTOR_ARM_START
#define THROTTLE_WMAX  MOTOR_MAX_LEVEL

#define ROLL_RMIN  1092
#define ROLL_RMAX  1912
#define ROLL_WMIN  -15
#define ROLL_WMAX  15

#define PITCH_RMIN  1092
#define PITCH_RMAX  1912
#define PITCH_WMIN  -15
#define PITCH_WMAX  15

#define YAW_RMIN  1092
#define YAW_RMAX  1912
#define YAW_WMIN  -45
#define YAW_WMAX  45

#define RX_RATE_SENSITIVITY  3
#define RX_ANGLE_DAMPNING  20.0  //D-term dampning
#define RX_EXPO
//*************************************
#define SAFE 0
//***********MOTOR CONFIG**************

//Motor PWM Levels
#define MOTOR_ZERO_LEVEL  120
#define MOTOR_ARM_START  125
#define MOTOR_MAX_LEVEL  253

