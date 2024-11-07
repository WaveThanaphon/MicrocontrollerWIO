#include <Adafruit_NeoPixel.h>

#define PIN            6  // Pin where the NeoPixels are connected
#define NUMPIXELS      16 // Number of NeoPixels
#define BUTTON_PIN     2  // Pin where the button is connected

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

bool buttonState = false;
bool lastButtonState = false;
int colorIndex = 0;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
    pixels.begin(); // Initialize the NeoPixel library
    pixels.show();  // Initialize all pixels to 'off'
}

void loop() {
    buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == LOW && lastButtonState == HIGH) {
        colorIndex++;
        if (colorIndex > 2) {
            colorIndex = 0;
        }
        setColor(colorIndex);
    }

    lastButtonState = buttonState;
}

void setColor(int index) {
    uint32_t color;
    switch (index) {
        case 0:
            color = pixels.Color(255, 0, 0); // Red
            break;
        case 1:
            color = pixels.Color(0, 255, 0); // Green
            break;
        case 2:
            color = pixels.Color(0, 0, 255); // Blue
            break;
    }

    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, color);
    }
    pixels.show();
}