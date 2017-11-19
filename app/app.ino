int led = D7; // The on-board LED

void setup()
{
    pinMode(led, OUTPUT);
}

void loop()
{
    digitalWrite(led, HIGH); // Turn ON the LED

    String temp = String(random(-5, 7));
    Particle.publish("temp", temp, PRIVATE);
    delay(5000); // Wait for 5 seconds

    digitalWrite(led, LOW); // Turn OFF the LED
    delay(5000);           // Wait for 5 seconds
}