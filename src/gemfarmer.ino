/*
 * Project gemfarmer
 * Description:
 * Author:
 * Date:
 */

#define sizeFile 512

// setup() runs once, when the device is first turned on.
void setup()
{
  // Put initialization like pinMode and begin functions here.

  Serial.begin(115200);
  Serial1.begin(115200);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{

  // Variables
  static char tempString[sizeFile];
  int spot = 0;

  // Clear the string if Serial1 is available
  if (Serial1.available())
  {
    memset(tempString, 0, sizeof(tempString));
  }

  // Read Serial1 into the string
  while (Serial1.available())
  {
    tempString[spot++] = Serial1.read();
    if (spot > sizeFile)
      break;
    delay(10); // Wait for Serial1
  }

  // Output
  if (strlen(tempString) > 0)
  {
    Serial.printlnf("tempString Length: %d", strlen(tempString));
    Serial.println("tempString Contents:");
    Serial.println(tempString);
  }
}