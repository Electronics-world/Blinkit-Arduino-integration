char buffer[22];

int RedPIN = 3; //pin for led 1 (single colour led) or pin for the Red led in the RGB led
int GreenPIN = 5; //pin for led 2 (single colour led) or pin for the Green led in the RGB led
int BluePIN = 6 ; //pin for led 3 (single colour led) or pin for the Blue led in the RGB led
//above pins must be DIGITAL PWM PINS (in Arduino Uno, PIN 3, 5, 6, 9, 10, 11 are PWM) in order to obtain the colours shades with the RGB led
int y=0;
int transferdata[3]; //array to be used to store the incoming settings and transfer them to the right setting array
int ledmode[2]; //this array will store the information regarding the ledmode (mode 1 for 3x single colour leds and mode 2 for 1x RGB led )
int blinkdelay[3]; //this array will store the information to be used for the blink speed (in this case it is a delay between blinks)
int Nofblinks[3]; //this array will store the information to be used for the number of triggers/blinks to do (number of repeated triggers)
int BRIGHTU[3]; // This array will store the information regarding the colour of the RGB led for an incoming upvote trigger and the effect chosen(3 values for the colour)
int BRIGHTF[3];// This array will store the information regarding the colour of the RGB led for an incoming follower trigger and the effect chosen(3 values for the colour)
int BRIGHTP[3]; // This array will store the information regarding the colour of the RGB led for an incoming post trigger and the effect chosen(3 values for the colour)

void setup()
{
Serial.begin(9600);
Serial.flush();    
    pinMode(RedPIN, OUTPUT); //set the selected pins as output 
    pinMode(GreenPIN, OUTPUT);
    pinMode(BluePIN, OUTPUT);
    
     int redIntensity = 0; //variable to handle the brightness of the red colour of the RGB led
     int blueIntensity = 0;// variable to handle the brightness of the blue colour of the RGB led
     int greenIntensity = 0; // variable to handle the brightness of the green colour of the RGB led

while (Serial.available() == NULL){ // repeat the below pattern while no data is received over serial
 for (int i = 0; i <=240; i+=1){ //This loop will light up/dim linearly the led till it goes from off state to a value close to
                                  //R=110 G=0 B=255 the starting value for our fading pattern

    if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
      redIntensity = i/2;
      blueIntensity = i ;
 
      analogWrite(RedPIN, redIntensity);     //
      analogWrite(GreenPIN, greenIntensity); //activate with proper delay the led using the currently stored values for R G B
      analogWrite(BluePIN, blueIntensity);   //
      delay(10);    
      }

for (int t = 0; t<2; t++){  //this FOR loop will let use repeat the below (whole) fade-in, fade-out pattern twice
  if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
for (int i = 110; i <=255; i+=1){        //In this for loop we will handle the first transition from R=110 G=0 B=255 (darker Violet) to 
                                         //R=255 G=10 B=255 (much brighter Violet) and have chosen to use the redIntensity as the variable part of the FOR loop
                                         //based on the value of R = i we will calculate the Green brightness.
if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
 redIntensity = i;
 greenIntensity = ((118937/10000)*log(i)-(559050/10000)); //The neperien logarithmic function usually wrote as ln(x) 
                                                          //is not recognized in Arduino coding by using ln but log
if(greenIntensity> 10){ //based on the aproximation in calculations we do this just in case not to pass the values
  greenIntensity =10;
}
if(greenIntensity< 1){ //based on the aproximation in the calculations we do this so that value of Green 
  greenIntensity =0;   //does not turn negative in anyway thus creating an error in the display
}
analogWrite(RedPIN, redIntensity);     //
analogWrite(GreenPIN, greenIntensity); //activate with proper delay the led using the currently stored values for R G B
analogWrite(BluePIN, blueIntensity);   //
delay(10);                             //
}

for (int i = 10; i <=240; i+=1){ //using this For loop we handle the linear transition between the bright Violet (R=255 G=10 B=255) 
                                 //and the White colour (R=255 G=255 b=255)
if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
redIntensity=255;
blueIntensity=255;
greenIntensity=i;

analogWrite(RedPIN, redIntensity);     //
analogWrite(GreenPIN, greenIntensity); //activate with proper delay the led using the currently stored values for R G B
analogWrite(BluePIN, blueIntensity);   //
delay(10);                             //
}
//below we reverse the loops used before to fade from Violet to White and use them to do the other way (from White to Violet)
for (int i = 255; i >=10; i-=1){ //using this For loop we handle the linear transition between the White colour (R=255 G=255 b=255)  
                                 //and the bright Violet (R=255 G=10 B=255)
if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
redIntensity=255;
blueIntensity=255;
greenIntensity=i;

analogWrite(RedPIN, redIntensity);     //
analogWrite(GreenPIN, greenIntensity); //activate with proper delay the led using the currently stored values for R G B
analogWrite(BluePIN, blueIntensity);   //
delay(10);                             //
}

for (int i = 255; i >=110; i-=1){ //In this for loop we will handle the transition from R=255 G=10 B=255 (much brighter Violet) to 
                                  // R=110 G=0 B=255 (darker Violet) and as before have chosen to use the redIntensity as the variable part of the FOR loop
                                  //based on the value of R = i we will calculate the Green brightness.
if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
redIntensity = i;
greenIntensity = ((118937/10000)*log(i)-(559050/10000));
 
if(greenIntensity<1){ //based ont he aproximations this will keep us on the safe side.
  greenIntensity =0;
}
analogWrite(RedPIN, redIntensity);     //
analogWrite(GreenPIN, greenIntensity); //activate with proper delay the led using the currently stored values for R G B
analogWrite(BluePIN, blueIntensity);   //
delay(10);                             //
}
}
for (int i = 255; i >=0; i-=1){ //This loop will dim linearly the led till it goes totally of
                                //since we went back to R=110 G=0 B=255 with a quick calculation and a good aproximation 
                                //we set the step to take for each brightness decrease so that they get dimmed simultaneously and of the same ammount each time

if (Serial.available() > 0){ // turn off the led when data is received and exit the loop
      analogWrite(RedPIN, 0);   //
      analogWrite(GreenPIN, 0); //
      analogWrite(BluePIN, 0);  //
    break;
    }
redIntensity = i/3;
blueIntensity = i ;
 
analogWrite(RedPIN, redIntensity);     //
analogWrite(GreenPIN, greenIntensity); //activate with proper delay the led using the currently stored values for R G B
analogWrite(BluePIN, blueIntensity);   //
delay(10);    
}
}
}


 
void loop() //collecting the incoming data and filling the buffer with it
{
if (Serial.available() > 0) {
int index=0;
delay(100); // let the buffer fill up
int numChar = Serial.available();
if (numChar>22) {
numChar=22;
}
while (numChar--) {
buffer[index++] = Serial.read();
}
splitString(buffer);
}

 
}
void splitString(char* data) { //splitting the data received based on a fixed separator (in this case the blank space " ")
//Serial.print("Data entered: "); 
//Serial.println(data); // display data entered/received
char* info;
info = strtok (data, " "); //using strtok split in tokens the data entered in a sequences of contiguous characters separated by the delimiter " " (empty space)
while (info != NULL) {
setallsettings(info);
setLEDon(info);
info = strtok (NULL, " ");
}
// Clear the text and serial buffers
for (int x=0; x<21; x++) {
buffer[x]='\0';
}
Serial.flush();
}

//here we will store the splitted data received over the serial comunication to store our set-ups
void setallsettings(char* data) { 
  
if (data[0] == 'm') {  // if incoming data has marker "m" store in the array lemode the mode ( m1 for 3x single colour led, m2 for 1x RGB led)
    int blinkdata = strtol(data+1, NULL, 10);
    blinkdata = constrain(blinkdata,1,2); 
    transferdata[y] = blinkdata;
    y=y+1;
    if (y==1){ // when transferdata is full of data (we expect 1 data for this setting)
    memcpy(ledmode, transferdata, sizeof(transferdata)); //copying transferdata to ledmode then clearing transferdata and resetting y, 
    for (int i=0; i<=sizeof(transferdata); i++){
    transferdata[i]= '\0';
    }
    y=0;
    }
  }
  if (data[0] == 'n') { //if incoming data has marker "n" store in an array the number of repeated triggers we want for each led/notification (ex. n10 n15 n1)
    int blinkdata = strtol(data+1, NULL, 10);
    blinkdata = constrain(blinkdata,1,30); 
    transferdata[y] = blinkdata;
    y=y+1;
    if (y==3){                                       // when transferdata is full of data (we expect 3 values)
    memcpy(Nofblinks, transferdata, sizeof(transferdata));   //copying transferdata to Nofblinks then clearing transferdata and resetting y, 
    for (int i=0; i<=sizeof(transferdata); i++){
    transferdata[i]= '\0';
    }
    y=0;
    }
  }
  if (data[0] == 'd') { //if incoming data has marker "d" store in an array called blinkdelay the delay/speed in the blinking/trigger
    int blinkdata = strtol(data+1, NULL, 10);
    blinkdata = constrain(blinkdata,1,1000); 
    transferdata[y] = blinkdata;
    y=y+1;
    if (y==3){                                                // when transferdata is full of data (we expect 3 values)
    memcpy(blinkdelay, transferdata, sizeof(transferdata));   //copying transferdata to blinkdelay then clearing transferdata and resetting y, 
    for (int i=0; i<=sizeof(transferdata); i++){
    transferdata[i]= '\0';
    }
    y=0;
    }
  }
if (data[0] == 'U') { //if incoming data has marker "U" store in an array called BRIGHTU the rgb colour code assigned for upvote (ex. U255 U0 U0 for red)
    int blinkdata = strtol(data+1, NULL, 10);
    blinkdata = constrain(blinkdata,0,255); 
    transferdata[y] = blinkdata;
    y=y+1;
    if (y==3){                                                // when transferdata is full of data (we expect 4 values, 3 regarding the colour code and the fourth for the effect)
    memcpy(BRIGHTU, transferdata, sizeof(transferdata));   //copying transferdata to BRIGHTU then clearing transferdata and resetting y, 
    transferdata[0]= '\0';
    y=0;
    }
  }
if (data[0] == 'F') { //if incoming data has marker "F" store in an array called BRIGHTF the rgb colour code assigned for follower (ex. F0 F255 F0 for green)
    int blinkdata = strtol(data+1, NULL, 10);
    blinkdata = constrain(blinkdata,0,255); 
    transferdata[y] = blinkdata;
    y=y+1;
    if (y==3){                                                // when transferdata is full of data (we expect 4 values, 3 regarding the colour code and the fourth for the effect)
    memcpy(BRIGHTF, transferdata, sizeof(transferdata));   //copying transferdata to BRIGHTF then clearing transferdata and resetting y, 
    transferdata[0]= '\0';
    y=0;
    }
  }
if (data[0] == 'P') {  //if incoming data has marker "P" store in an array called BRIGHTP the rgb colour code assigned for post (ex. P0 P0 P255 for blue)
    int blinkdata = strtol(data+1, NULL, 10);
    blinkdata = constrain(blinkdata,0,255); 
    transferdata[y] = blinkdata;
    y=y+1;
    if (y==3){                                                // when transferdata is full of data (we expect 4 values, 3 regarding the colour code and the fourth for the effect)
    memcpy(BRIGHTP, transferdata, sizeof(transferdata));   //copying transferdata to BRIGHTP then clearing transferdata and resetting y, 
    transferdata[0]= '\0';
    y=0;
    }
  }
 
if (data[0] == '?'){   //send command set to view on serial all the current setups
  Serial.println("Current Settings: ");
  Serial.println("---------------------------------------------------- ");
  Serial.println(" ");  
if(ledmode[0]== 1){     
        Serial.println("ledmode is set to: 3x single colour LED ");
        Serial.println(" ");  

  for (int i=0;i<=2;i++){
      Serial.print("Nofblinks for led");
      Serial.print(i+1);
      Serial.print(" is:");
      Serial.print(Nofblinks[i]);
      Serial.println(" Blinks");
    if (i==2){
      Serial.println(" ");
      }
   }     
  for (int i=0;i<=2;i++){
        Serial.print("blinkdelay for led ");
        Serial.print(i+1);
        Serial.print(" is:");
        Serial.print(blinkdelay[i]);
        Serial.println(" Millis");
     if (i==2){
        Serial.println(" ");
        }
   }
}
   if(ledmode[0]==2){
              Serial.println("ledmode is set to: 1x RGB LED ");
              Serial.println(" ");
            
              Serial.print("number of blinks for upvote trigger is: ");
              Serial.print(Nofblinks[0]);
              Serial.println(" Blinks");
              Serial.print("number of blinks for follower trigger is: ");
              Serial.print(Nofblinks[1]);
              Serial.println(" Blinks");
              Serial.print("number of blinks for post trigger is: ");
              Serial.print(Nofblinks[2]);
              Serial.println(" Blinks");
              Serial.println(" ");
        
              Serial.print("blinkdelay for upvote trigger is: ");
              Serial.print(blinkdelay[0]);
              Serial.println(" Millis");
              Serial.print("blinkdelay for follower trigger is: ");
              Serial.print(blinkdelay[1]);
              Serial.println(" Millis");
              Serial.print("blinkdelay for post trigger is: ");
              Serial.print(blinkdelay[2]);
              Serial.println(" Millis");
              Serial.println(" ");
              
              Serial.println("RGB value for upvote trigger is set to");
              Serial.println(" ");
              Serial.print("R= ");
              Serial.println(BRIGHTU[0]);
              Serial.print("G= ");
              Serial.println(BRIGHTU[1]);
              Serial.print("B= ");
              Serial.println(BRIGHTU[2]);
              Serial.println("");
                          
              Serial.println("RGB value for follower trigger is set to");
              Serial.println(" ");
              Serial.print("R= ");
              Serial.println(BRIGHTF[0]);
              Serial.print("G= ");
              Serial.println(BRIGHTF[1]);
              Serial.print("B= ");
              Serial.println(BRIGHTF[2]);
              Serial.println("");
                            
              Serial.println("RGB value for post trigger is set to");
              Serial.println(" ");
              Serial.print("R= ");
              Serial.println(BRIGHTP[0]);
              Serial.print("G= ");
              Serial.println(BRIGHTP[1]);
              Serial.print("B= ");
              Serial.println(BRIGHTP[2]);
              Serial.println("");
               
         }
    }
}

void setLEDon(char* data) {
  //if i receive the command u from serial (upvote)
if (data[0] == 'u') {             
  if(ledmode[0]==1){ //and if ledmode[0] is set to 1 (3x single colour led mode)
    for (int a= 0; a< Nofblinks[0]; a++){
      digitalWrite(RedPIN, HIGH);
      delay(blinkdelay[0]);
      digitalWrite(RedPIN, 0);
      delay(blinkdelay[0]);
       }
}
  if(ledmode[0]==2){
    for (int a= 0; a< Nofblinks[0]; a++){
      analogWrite(RedPIN, BRIGHTU[0]);
      analogWrite(GreenPIN, BRIGHTU[1]);
      analogWrite(BluePIN, BRIGHTU[2]);
      delay(blinkdelay[0]);
      analogWrite(RedPIN, 0);
      analogWrite(GreenPIN, 0);
      analogWrite(BluePIN, 0);
      delay(blinkdelay[0]);
    }
  }
 Serial.println("you got an upvote ");
 Serial.println(" "); 
}      
//if i receive the command f from serial (follower)   
if (data[0] == 'f') { //if Arduino detects the trigger command f from serial (follower)    
    if(ledmode[0]==1){    // if ledmode[0] is set to 1 (3x single colour led mode)
       for (int a= 0; a< Nofblinks[1]; a++){
         digitalWrite(GreenPIN, HIGH);
         delay(blinkdelay[1]);
         digitalWrite(GreenPIN, 0);
         delay(blinkdelay[1]);
          }
      }
      
    if(ledmode[0]==2){ //and if ledmode[0] is set to 2 (1x RGB led mode)
       for (int a= 0; a< Nofblinks[1]; a++){
         analogWrite(RedPIN, BRIGHTF[0]);
         analogWrite(GreenPIN, BRIGHTF[1]);
         analogWrite(BluePIN, BRIGHTF[2]);
         delay(blinkdelay[1]);
         analogWrite(RedPIN, 0);
         analogWrite(GreenPIN, 0);
         analogWrite(BluePIN, 0);
         delay(blinkdelay[1]);
         }
     }
 Serial.println("you got a new follower ");
 Serial.println(" "); 
}     
  

if (data[0] == 'p') { //if Arduino detects the trigger command p from serial (new post) 
    if(ledmode[0]==1){    //and if ledmode[0] is set to 1 (3x single colour led mode)
      for (int a= 0; a< Nofblinks[2]; a++){
         digitalWrite(BluePIN, HIGH);
         delay(blinkdelay[2]);
         digitalWrite(BluePIN, 0);
         delay(blinkdelay[2]);
          }
}
    if(ledmode[0]==2){ //if ledmode[0] is set to 2 (1x RGB led mode)
      for (int a= 0; a< Nofblinks[2]; a++){
         analogWrite(RedPIN, BRIGHTP[0]);
         analogWrite(GreenPIN, BRIGHTP[1]);
         analogWrite(BluePIN, BRIGHTP[2]);
         delay(blinkdelay[2]);
         analogWrite(RedPIN, 0);
         analogWrite(GreenPIN, 0);
         analogWrite(BluePIN, 0);
         delay(blinkdelay[2]);
         }
        }
 Serial.println("there is a new post ");
 Serial.println(" "); 
}     
}

