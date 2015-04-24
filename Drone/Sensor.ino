
void initSensor(){
 Wire.begin();
  
  ps.init();
  ps.enableDefault();
  
  accelo.init();
  accelo.enableDefault();
  
  gyro.init();
  gyro.enableDefault();
  
  accelo.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  accelo.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
}


void updateSensor(){
  baroTime = millis() - prev_baroTime;
  acceTime = millis() - prev_acceTime;
  gyroTime = micros() - prev_gyroTime;
  if(baroTime>refreshBaro){
  }
  if(acceTime>refreshAcce){
    int bufferACC[3];
    accelo.read();
    float heading = accelo.heading();
    bufferACC[0]=((int)((accelo.a.x)*0.061)) - ACC_X_OFFSET; 
    bufferACC[1]=((int)((accelo.a.y)*0.061)) - ACC_Y_OFFSET;
    bufferACC[2]=((int)((accelo.a.z)*0.061)) - ACC_Z_OFFSET;  
    accx_temp=(ACC_HPF_NR*accx_temp+(100-ACC_HPF_NR)*bufferACC[0])/100;
    accy_temp=(ACC_HPF_NR*accy_temp+(100-ACC_HPF_NR)*bufferACC[1])/100;
    accz_temp=(ACC_HPF_NR*accz_temp+(100-ACC_HPF_NR)*bufferACC[2])/100;
    prev_acceTime = millis();
  }
  if(gyroTime>refreshGyro){
     gyro.read();
     gx = (float)((gyro.g.x)*8.75/1000);
     gy = (float)((gyro.g.y)*8.75/1000);
     gz = (float)((gyro.g.z)*8.75/1000);
     float buffer[3] = {gx,gy,gz}; //Gyro buffer
     
     for(int i=0;i<(GYRO_MAF_NR-1);i++){
        gx_temp[i]=gx_temp[i+1];
        gy_temp[i]=gy_temp[i+1];
        gz_temp[i]=gz_temp[i+1];
     }
     gx_temp[1]=buffer[0]-GYRO_X_OFFSET;
     gy_temp[1]=buffer[1]-GYRO_Y_OFFSET;
     gz_temp[1]=buffer[2]-GYRO_Z_OFFSET;
     
     gyroMAF();
     prev_gyroTime = micros();
  }
  unsigned long t = millis();
  float dt = (float)(t-tp)/1000.0;
  float accx = atan2(accx_temp,accz_temp)*RadToDeg;
  float accy = atan2(accy_temp,accz_temp)*RadToDeg;
  angles[0]=SPLIT*(-gy_aver*dt+angles[0])+(1.0-SPLIT)*accx;
  angles[1]=SPLIT*(gx_aver*dt+angles[1])+(1.0-SPLIT)*accy;
  tp=t;
}

void gyroMAF(){//Moving average filter
  float gx_old,gy_old,gz_old;
  if(GYRO_HPF_NR > 0){
  gx_old=gx_aver;
  gy_old=gy_aver;
  gz_old=gz_aver;
  }
  gx_aver=0;
  gy_aver=0;
  gz_aver=0;
  for(byte i=0;i<GYRO_MAF_NR;i++){
    gx_aver=gx_aver+gx_temp[i];
    gy_aver=gy_aver+gy_temp[i];
    gz_aver=gz_aver+gz_temp[i];
  }  
  gx_aver=(float)gx_aver/GYRO_MAF_NR;
  gy_aver=(float)gy_aver/GYRO_MAF_NR;
  gz_aver=(float)gz_aver/GYRO_MAF_NR;

  if(GYRO_HPF_NR > 0){
  gx_aver=(GYRO_HPF_NR*gx_old+(100.0-GYRO_HPF_NR)*gx_aver)/100.0;
  gy_aver=(GYRO_HPF_NR*gy_old+(100.0-GYRO_HPF_NR)*gy_aver)/100.0;
  gz_aver=(GYRO_HPF_NR*gz_old+(100.0-GYRO_HPF_NR)*gz_aver)/100.0;
  }
}
