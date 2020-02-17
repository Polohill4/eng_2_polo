#include <Servo.h>
Servo myservo;
int trig = 9;
int echo = 12;
int dist = 0;
void setup()
{
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    myservo.attach(11);
    myservo.write(0);
}

void loop()
{
    dist = getDistance();
    if (dist > 5)
        myservo.write(180);
    else
        if ((dist > 1) && (dist < 5))
            myservo.write(0);
    else
        if (dist < 2)
            myservo.write(90);
}

int getDistance()
{
    int distance;
    int duration;
    digitalWrite(trig, LOW);
    delay(5);
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    Serial.println(distance);
    distance = duration * 0.01330 / 2;
    return distance;
}
