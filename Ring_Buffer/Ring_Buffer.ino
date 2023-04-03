#define RING_BUFFER_SIZE 8
#define TEMP_BUFFER_SIZE 64

static char ring_buff[RING_BUFFER_SIZE] = {0, };
static int data = 0;

void setup() 
{
  Serial.begin(115200);
  pinMode(45, OUTPUT);
}

void loop() 
{
  char read_temp[TEMP_BUFFER_SIZE];
  if (Serial.available() > 0)
  {
    byte leng = Serial.readBytes(read_temp, TEMP_BUFFER_SIZE);
    delay(2);
    digitalWrite(45, HIGH);
    Serial.println(" ");
    Serial.print("Input data Length: ");
    Serial.println(leng);
    for (int i = 0; i < leng; i++)
    {
      ring_buff[data] = read_temp[i];
      Serial.print(read_temp[i]);
      data++;
      if (data >= RING_BUFFER_SIZE)
      {
        data = 0;
        memset(&ring_buff[1], 0, RING_BUFFER_SIZE - 1);
      }
    }
    Serial.println(" ");
    Serial.print("data no: ");
    Serial.println(data);
    for (int j = data; j < RING_BUFFER_SIZE; j++)
    {
      if (ring_buff[j] == 0) 
      {
        Serial.print("0");
      }
      else 
      {
        Serial.print(ring_buff[j]);
      }
    }
    for (int j = 0; j < data; j++)
    {
      if (ring_buff[j] == 0)
      {
        Serial.print("0");
      } 
      else 
      {
        Serial.print(ring_buff[j]);
      }
    }
    Serial.println(" ");
  }
  digitalWrite(45, LOW);
}
