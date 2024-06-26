/*!
 * @File  DFRobot_IraserSensor.ino
 sen0366
D2 -yellow 
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);//Define software serial, 3 is TX, 2 is RX
//char buff[4]={0x80,0x06,0x03,0x77};

    char singleMeasurement[] = {0x80, 0x06, 0x02, 0x78};                  //1
    char continuousMeasurement[] = {0x80, 0x06, 0x03, 0x77};              //2
    char shutdownDevice[] = {0x80, 0x04, 0x02, 0x7A};                     //3
    char setAddress[] = {0xFA, 0x04, 0x01, 0x80, 0x81};                   //4
    char distanceModMinus1[] = {0xFA, 0x04, 0x06, 0x2D, 0x01, 0xCE};      //5
    char distanceModPlus1[] = {0xFA, 0x04, 0x06, 0x2B, 0x01, 0xD0};       //6
    char timeInterval1S[] = {0xFA, 0x04, 0x05, 0x01, 0xFC};               //7
    char setStartPointTop[] = {0xFA, 0x04, 0x08, 0x01, 0xF9};             //8
    char setStartPointBackEnds[] = {0xFA, 0x04, 0x08, 0x00, 0xFA};        //9
    char setRange5m[] = {0xFA, 0x04, 0x09, 0x05, 0xF4};                   //10
    char setRange10m[] = {0xFA, 0x04, 0x09, 0x0A, 0xEF};                  //11
    char setRange30m[] = {0xFA, 0x04, 0x09, 0x1E, 0xDB};                  //12
    char setRange50m[] = {0xFA, 0x04, 0x09, 0x32, 0xC7};                  //13
    char setRange80m[] = {0xFA, 0x04, 0x09, 0x50, 0xA9};                  //14
    char setFrequency0[] = {0xFA, 0x04, 0x0A, 0x00, 0xF8};                //15
    char setFrequency5[] = {0xFA, 0x04, 0x0A, 0x05, 0xF3};                //16
    char setFrequency10[] = {0xFA, 0x04, 0x0A, 0x0A, 0xEE};               //17
    char setFrequency20[] = {0xFA, 0x04, 0x0A, 0x14, 0xE4};               //18
    char setResolution1mm[] = {0xFA, 0x04, 0x0C, 0x01, 0xF5};             //19
    char setResolution0_1mm[] = {0xFA, 0x04, 0x0C, 0x02, 0xF4};           //20
    char startMeasurementOnPowerOff[] = {0xFA, 0x04, 0x0D, 0x00, 0xF5};   //21
    char startMeasurementOnPowerOn[] = {0xFA, 0x04, 0x0D, 0x01, 0xF4};    //22
    char singleMeasurementBroadcast[] = {0xFA, 0x06, 0x06, 0xFA};         //23
    char readCache[] = {0x80, 0x06, 0x07, 0x73};                          //24
    char controlLaserOpen[] = {0x80, 0x06, 0x05, 0x01, 0x74};             //25
    char controlLaserClose[] = {0x80, 0x06, 0x05, 0x00, 0x75};            //26

    int n = 11; //bytes

unsigned char data[15]={0};
void setup()
{
 Serial.begin(115200);
 mySerial.begin(9600);
 mySerial.print(continuousMeasurement);
}

void loop()
{
  //mySerial.print(buff);
  //while(1)

  if (Serial.available() > 0) {

    int input = Serial.parseInt();

switch (input) {
      case 1:
        mySerial.write(singleMeasurement, sizeof(singleMeasurement));
        Serial.println("1 - singleMeasurement");
        break;
      case 2:
        mySerial.write(continuousMeasurement, sizeof(continuousMeasurement));
        Serial.println("2 - continuousMeasurement");
        break;
      case 3:
        mySerial.write(shutdownDevice, sizeof(shutdownDevice));
        Serial.println("3 - shutdownDevice");
        break;
      case 4:
        mySerial.write(setAddress, sizeof(setAddress));
        Serial.println("4 - setAddress");
        break;
      case 5:
        mySerial.write(distanceModMinus1, sizeof(distanceModMinus1));
        Serial.println("5 - distanceModMinus1");
        break;
      case 6:
        mySerial.write(distanceModPlus1, sizeof(distanceModPlus1));
        Serial.println("6 - distanceModPlus1");
        break;
      case 7:
        mySerial.write(timeInterval1S, sizeof(timeInterval1S));
        Serial.println("7 - timeInterval1S");
        break;
      case 8:
        mySerial.write(setStartPointTop, sizeof(setStartPointTop));
        Serial.println("8 - setStartPointTop");
        break;
      case 9:
        mySerial.write(setStartPointBackEnds, sizeof(setStartPointBackEnds));
        Serial.println("9 - setStartPointBackEnds");
        break;
      case 10:
        mySerial.write(setRange5m, sizeof(setRange5m));
        Serial.println("10 - setRange5m");
        break;
      case 11:
        mySerial.write(setRange10m, sizeof(setRange10m));
        Serial.println("11 - setRange10m");
        break;
      case 12:
        mySerial.write(setRange30m, sizeof(setRange30m));
        Serial.println("12 - setRange30m");
        break;
      case 13:
        mySerial.write(setRange50m, sizeof(setRange50m));
        Serial.println("13 - setRange50m");
        break;
      case 14:
        mySerial.write(setRange80m, sizeof(setRange80m));
        Serial.println("14 - setRange80m");
        break;
      case 15:
        mySerial.write(setFrequency0, sizeof(setFrequency0));
        Serial.println("15 - setFrequency0");
        break;
      case 16:
        mySerial.write(setFrequency5, sizeof(setFrequency5));
        Serial.println("16 - setFrequency5");
        break;
      case 17:
        mySerial.write(setFrequency10, sizeof(setFrequency10));
        Serial.println("17 - setFrequency10");
        break;
      case 18:
        mySerial.write(setFrequency20, sizeof(setFrequency20));
        Serial.println("18 - setFrequency20");
        break;
      case 19:
        mySerial.write(setResolution1mm, sizeof(setResolution1mm));
        Serial.println("19 - setResolution1mm");
        break;
      case 20:
        mySerial.write(setResolution0_1mm, sizeof(setResolution0_1mm));
        Serial.println("20 - setResolution0_1mm");
        break;
      case 21:
        mySerial.write(startMeasurementOnPowerOff, sizeof(startMeasurementOnPowerOff));
        Serial.println("21 - startMeasurementOnPowerOff");
        break;
      case 22:
        mySerial.write(startMeasurementOnPowerOn, sizeof(startMeasurementOnPowerOn));
        Serial.println("22 - startMeasurementOnPowerOn");
        break;
      case 23:
        mySerial.write(singleMeasurementBroadcast, sizeof(singleMeasurementBroadcast));
        Serial.println("23 - singleMeasurementBroadcast");
        break;
      case 24:
        mySerial.write(readCache, sizeof(readCache));
        Serial.println("24 - readCache");
        break;
      case 25:
        mySerial.write(controlLaserOpen, sizeof(controlLaserOpen));
        Serial.println("25 - controlLaserOpen");
        break;
      case 26:
        mySerial.write(controlLaserClose, sizeof(controlLaserClose));
        Serial.println("26 - controlLaserClose");
        break;
    }
  }

  {
    if(mySerial.available()>0)//Determine whether there is data to read on the serial 
    {
      delay(20);
      for(int i=0;i<n;i++)
      {
        data[i]=mySerial.read();
      }
      unsigned char Check=0;
      for(int i=0;i<n;i++)
      {
        Check=Check+data[i];
      }
      Check=~Check+1;
      if(data[n]==Check)
      {
            // Print all 10-bit signals
      for (int i = 0; i < n; i++) {
       Serial.print(data[i], HEX);
       Serial.print(" ");
      }
      Serial.println();
      //Serial.print("Checksum: ");
      //Serial.println(Check, HEX);



        if(data[3]=='E'&&data[4]=='R'&&data[5]=='R')
        {
          Serial.println("Out of range");
        }
        else
        {
          float distance=0;
          distance=(data[3]-0x30)*100+(data[4]-0x30)*10+(data[5]-0x30)*1+(data[7]-0x30)*0.1+(data[8]-0x30)*0.01+(data[9]-0x30)*0.001;
          Serial.print("Distance = ");
          Serial.print(distance,3);
          Serial.println(" M");
        }
      }
      else
      {
        Serial.println();
        Serial.println("Invalid Data!");

       for (int i = 0; i < n; i++) {
       Serial.print(data[i], HEX);
       Serial.print(" ");
      }
      Serial.println();
      //Serial.print("Checksum: ");
      //Serial.println(Check, HEX);
      
      Serial.print("data-30: ");
      for (int i = 0; i < n; i++) {
       Serial.print(data[i]-0x30, HEX);
       Serial.print(" ");
       
      }
      Serial.println();
          float distance=0;
          distance=(data[3]-0x30)*100+(data[4]-0x30)*10+(data[5]-0x30)*1+(data[7]-0x30)*0.1+(data[8]-0x30)*0.01+(data[9]-0x30)*0.001;
          Serial.print("Distance = ");
          Serial.print(distance,3);
          Serial.println(" M");

      }
    }
    delay(20);
  }
}
