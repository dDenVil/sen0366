# sens0366
Made simple code to test 20hz high Accuracy 80m Laser Sensor Range finder Distance measuring module TTL interface ardunio


So this module called **SENS0366**, it is range distance sensor. It should measure distance from 50 to 80m. But in realy I could get **less then 30m**. So real measuring distance around 20m.

![sensor](https://dfimg.dfrobot.com/nobody/wiki/b5412e541833689f75cc2b88c4ea5f5e.png)

I did not find good datasheet, there are few usefull links:
1. aka [datasheet](https://wiki.dfrobot.com/Infrared_Laser_Distance_Sensor_50m_80m_SKU_SEN0366#target_1)
2. Aliexpress [datasheet](https://www.aliexpress.com/item/1005005384252531.html?spm=a2g0o.order_detail.order_detail_item.3.4a9ff19c70culH), place where I bought it
3. Other [Github test code](https://github.com/1m2lab/LRMD/blob/main/tests/sen0366.py)

With code below, you can simply test your sensor. I have used arduino nano with connected RX and TX pins, to D2 and D3 correspondently. In some datasheets it mensioned that it works from 3.3V only. But I risked and connected it to arduino 5V, and it is works fine. 
So you can connected your sensor as it is shown.

![connect1](https://dfimg.dfrobot.com/nobody/wiki/9baa5bf812b40f12da725e18ac77ca5c.png)
Define software serial, 3 is TX, 2 is RX.
![connect2](https://dfimg.dfrobot.com/nobody/wiki/3729ed2e85b73af307bb026255d377d1.png)

Code prints in serial distance, and recieved command with data bit. To set nessasery parameters type corresponding number:

| Variable Name                   | Number | Notes |
|---------------------------------|--------|-------|
| singleMeasurement               | 1      |works       |
| continuousMeasurement           | 2      |works        |
| shutdownDevice                  | 3      |works        |
| setAddress                      | 4      |idk       |
| distanceModMinus1               | 5      |idk   (it doesn't change distance range 5-10-30-50-80)      |
| distanceModPlus1                | 6      |idk   (it doesn't change distance range 5-10-30-50-80)    |
| timeInterval1S                  | 7      |useless       |
| setStartPointTop                | 8      |it should meassure distance from the top of the sensor       |
| setStartPointBackEnds           | 9      |...but there are no difference       |
| setRange5m                      | 10     |works         |
| setRange10m                     | 11     |works         |
| setRange30m                     | 12     |works         |
| setRange50m                     | 13     |works         |
| setRange80m                     | 14     |works         |
| setFrequency0                   | 15     |didn't see difference       |
| setFrequency5                   | 16     |didn't see difference         |
| setFrequency10                  | 17     |didn't see difference         |
| setFrequency20                  | 18     |didn't see difference         |
| setResolution1mm                | 19     |maybe works       |
| setResolution0_1mm              | 20     |maybe works       |
| startMeasurementOnPowerOff      | 21     |don't work      |
| startMeasurementOnPowerOn       | 22     |don't work        |
| singleMeasurementBroadcast      | 23     | idk       |
| readCache                       | 24     | works      |
| controlLaserOpen                | 25     |works (laser stays ON)      |
| controlLaserClose               | 26     |works        |

After you type any command, you may have to type **2** as well to start continuous measurement. If you have any ideas, how this commands works, let me know)
Also you can find code in code.ino
```c
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
```

Hope it will help somebody. It took for me a lot of time, to find this info and test it. I hoped it would meassure distance up to 50m, but with 25m range it is useless for me.
GL
