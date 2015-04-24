
void initrx(){
  attachInterrupt(THRO_SIGNAL_IN,calcInput1,CHANGE);
  attachInterrupt(AILE_SIGNAL_IN,calcInput2,CHANGE);
  attachInterrupt(ELEV_SIGNAL_IN,calcInput3,CHANGE);
  attachInterrupt(RUDD_SIGNAL_IN,calcInput4,CHANGE);
}

void calcInput1()
{
  if(digitalRead(THRO_SIGNAL_IN_PIN) == HIGH)
  { 
    ulStartPeriod0 = micros();
  }
  else
  {
    if(ulStartPeriod0)
    {
      rxVal[0] = (int)(micros() - ulStartPeriod0);
      ulStartPeriod0 = 0;
    }
  }
}

void calcInput2()
{
  if(digitalRead(AILE_SIGNAL_IN_PIN) == HIGH)
  { 
    ulStartPeriod1 = micros();
  }
  else
  {
    if(ulStartPeriod1)
    {
      rxVal[1] = (int)(micros() - ulStartPeriod1);
      ulStartPeriod1 = 0;
    }
  }  
}
void calcInput3()
{
  if(digitalRead(ELEV_SIGNAL_IN_PIN) == HIGH)
  { 
    ulStartPeriod2 = micros();
  }
  else
  {
    if(ulStartPeriod2)
    {
      rxVal[3] = (int)(micros() - ulStartPeriod2);
      ulStartPeriod2 = 0;
    }
  }
}
void calcInput4()
{
  if(digitalRead(RUDD_SIGNAL_IN_PIN) == HIGH)
  { 
    ulStartPeriod3 = micros();
  }
  else
  {
    if(ulStartPeriod3)
    {
      rxVal[2] = (int)(micros() - ulStartPeriod3);
      ulStartPeriod3 = 0;
    }
  }
}

