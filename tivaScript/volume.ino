uint32_t ulAIN0;
int previousVolume=-1;

void volumeInitialize()
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
  GPIOPinTypeADC(AINPort, AIN);
  ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
  ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);
  ADCSequenceEnable(ADC0_BASE, 0);
}

void volume()
{
  ADCProcessorTrigger(ADC0_BASE, 0);
  while(!ADCIntStatus(ADC0_BASE, 0, false));
  ADCSequenceDataGet(ADC0_BASE, 0, &ulAIN0);
  if(ulAIN0/40!=previousVolume)
  {
    Serial.print("v");
    //max potentiometer val is 4095, 4095/40=102
    //itunes interprets as 100, spotify breaks lololol
    if(ulAIN0/41>98)
      Serial.println(99);
    else
      Serial.println(ulAIN0/41);
    previousVolume=ulAIN0/41;
  }
  delay(delayTime);
}

