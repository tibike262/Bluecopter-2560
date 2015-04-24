#include <Servo.h>
#include <Wire.h>
#include <LPS.h>
#include <LPS.cpp>
#include <LSM303d.h>
#include <math.h>
#include <L3G.h>
#include <PIDCont.h>
#include "PINS.h"

float gx,gy,gz;
int accx_temp=0;
int accy_temp=0;
int accz_temp=0;

// neutral values at the begginning of the flight
volatile int nThroIn = 1096;
volatile int nAileIn = NEUTRAL_AILE;
volatile int nElevIn = NEUTRAL_ELEV;
volatile int nRuddIn = NEUTRAL_RUDD;

volatile unsigned long ulStartPeriod0 = 0;
volatile unsigned long ulStartPeriod1 = 0;
volatile unsigned long ulStartPeriod2 = 0;
volatile unsigned long ulStartPeriod3 = 0;

long refreshBaro = 40;   //  25 Hz refresh rate 
long refreshAcce = 10;   // 100 Hz refresh rate
long refreshGyro = 1250; // 100 Hz refresh rate

long baroTime = millis();
long acceTime = millis();
long gyroTime = micros();

long prev_baroTime = millis();
long prev_acceTime = millis();
long prev_gyroTime = micros();

volatile float pressure, altitude, temperature;
volatile float accx,accy;

unsigned long tp;

float gx_temp[GYRO_MAF_NR]={0.0,0.0};
float gy_temp[GYRO_MAF_NR]={0.0,0.0};
float gz_temp[GYRO_MAF_NR]={0.0,0.0};

float angles[2]={0.0,0.0};

float gx_aver=0;
float gy_aver=0;
float gz_aver=0;

int setX = 0; //Rate Setpoint for PID
int setY = 0; //Rate Setpoint for PID
int setZ = 0; //Rate Setpoint for PID

volatile int rxVal[4]={1100,1500,1500,1500};
int throttle=MOTOR_ZERO_LEVEL;

byte rateAngleSwitch = 0;

Servo left,right,front,back;

PIDCont PIDroll,PIDpitch,PIDyaw,PIDangleX,PIDangleY;
LPS ps;
LSM303 accelo;
L3G gyro;

void setup()
{
  Serial.begin(115200);
  pinMode(40,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(44,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(48,OUTPUT);
  digitalWrite(40,HIGH);
  digitalWrite(42,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(46,HIGH);
  digitalWrite(48,HIGH);
  delay(2000);
  initrx();
  initSensor();
  motorInit();
  motorArm();
  PID_init();
  tp = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateSensor();
  FlightControl();
}
