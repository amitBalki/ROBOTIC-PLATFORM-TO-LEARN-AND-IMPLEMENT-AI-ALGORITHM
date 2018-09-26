#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

void setup()
{
    pinMode(8, OUTPUT); 
    pinMode(3, OUTPUT); 
    pinMode(5, OUTPUT); 
    pinMode(6, OUTPUT); 
    pinMode(9, OUTPUT); 
    // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
    digitalWrite(8, HIGH);
    Serial.begin(9600);
    BTSerial.begin(57600);  // HC-05 default speed in AT command more
}

int buff[5];

int input,num,degree,dis;
int j=-1;

int calc()
{
    int num=0,x=0;

    for(x;x<=j;x++)
          num=num+(buff[x]-48)*pow(10,j-x);

    return num;
}
float spd = 0;
int ptr = 0;
float d;
void loop()
{
    
    if(BTSerial.available()>0)
    {
       //Serial.println("Ready");
        input=BTSerial.read();
         if(input == ','){
             
              num=calc();

            if(ptr%2==0){
             degree=num;
             d=degree*1.0;
             if(degree> 180){
                d= 360-degree;
               }
            }
            else{
              dis=num;
              spd = (dis*110*1.0)/350+16;
              d= (d*1.0*spd)/50;
              if(degree>5 && degree < 180)
              {
                Serial.println("positive  ");
               //analogWrite(5,spd-d);
              analogWrite(5,25); 
              analogWrite(3,0);
              analogWrite(6,0);
              analogWrite(9,16);
                delay(1);
              }
              else if(degree<355 && degree >180)
              {
                Serial.println("negative ");
                analogWrite(5,0);
                analogWrite(3,16);
                //analogWrite(6,spd-d);
                analogWrite(6,25);
                analogWrite(9,0);
                delay(1);
              }
              else{
              Serial.println(spd);
              analogWrite(5,spd);
              analogWrite(3,0);
              analogWrite(6,spd);
              analogWrite(9,0);
              delay(3);
              }
            
            }
            j=-1;
            ptr++;
            
          }
          
      
         
        
          else
          {
             j++;
            buff[j]=input;
         }
        
   }          
    
}

