#warning **** Included USERMOD_M5AtomWifiFix ****  // For debugging
#pragma once

#include "wled.h"

class M5AtomWifiFixUsermod : public Usermod {

  private:

    // Private class members. You can declare variables and functions only accessible to your usermod here
    bool initDone = false;
    bool fixSuccess = false;
    int8_t wifiFixPin = 0;

  public:

    /*
     * setup() is called once at boot. WiFi is not yet connected at this point.
     * readFromConfig() is called prior to setup()
     * You can use it to initialize variables, sensors or similar.
     */
    void setup() {
      // do your set-up here
      fixSuccess = false;
      bool allocSuccess = false;
      // DEBUG_PRINTLN(F("Allocating Wifi pin..."));
      DEBUG_PRINTLN(F("Allocating Wifi pin..."));

      if (pinManager.allocatePin(wifiFixPin, false, PinOwner::UM_Unspecified)) {
            DEBUG_PRINTLN(F("WiFi pin allocation succeeded."));
            allocSuccess = true;
      }

      if (!allocSuccess) {
          DEBUG_PRINTLN(F("WiFi pin allocation failed."));
          wifiFixPin = -1;  // allocation failed
      } else {
        pinMode(wifiFixPin, OUTPUT);
        digitalWrite(wifiFixPin, HIGH);
        DEBUG_PRINTLN(F("WiFi pin set high!"));
        fixSuccess = true;
      }
      initDone = true;
    }


    /*
     * connected() is called every time the WiFi is (re)connected
     * Use it to initialize network interfaces
     */
    // void connected() {
    //   //Serial.println("Connected to WiFi!");
    // }


    /*
     * loop() is called continuously. Here you can check for events, read sensors, etc.
     * 
     * Tips:
     * 1. You can use "if (WLED_CONNECTED)" to check for a successful network connection.
     *    Additionally, "if (WLED_MQTT_CONNECTED)" is available to check for a connection to an MQTT broker.
     * 
     * 2. Try to avoid using the delay() function. NEVER use delays longer than 10 milliseconds.
     *    Instead, use a timer check as shown here.
     */
    // void loop() {
    //   // if usermod is disabled or called during strip updating just exit
    //   // NOTE: on very long strips strip.isUpdating() may always return true so update accordingly
    //   if (!enabled || strip.isUpdating()) return;

    //   // do your magic here
    //   if (millis() - lastTime > 1000) {
    //     //Serial.println("I'm alive!");
    //     lastTime = millis();
    //   }
    // }
    void loop() 
    {
     // loop() must exist in a usermod, even if it does nothing
    }

    /**
     * handleButton() can be used to override default button behaviour. Returning true
     * will prevent button working in a default way.
     * Replicating button.cpp
     */
    bool handleButton(uint8_t b) {
      /**
       * The following button code is for debugging & verification that the fix is working.
      */
      yield();
      bool enabled = true;
      if (!enabled
        || b // button 0 only
        || buttonType[b] == BTN_TYPE_SWITCH
        || buttonType[b] == BTN_TYPE_NONE
        || buttonType[b] == BTN_TYPE_RESERVED
        || buttonType[b] == BTN_TYPE_PIR_SENSOR
        || buttonType[b] == BTN_TYPE_ANALOG
        || buttonType[b] == BTN_TYPE_ANALOG_INVERTED) {
        return false;
      }

      if(isButtonPressed(b) && fixSuccess){
        Serial.println("Button Pressed & WiFi Fixed");
      }else if (isButtonPressed(b) && !fixSuccess){
        Serial.println("Button Pressed & WiFi Not Fixed");
      }

      return false;
    }
  

    /*
     * getId() allows you to optionally give your V2 usermod an unique ID (please define it in const.h!).
     * This could be used in the future for the system to determine whether your usermod is installed.
     */
    uint16_t getId()
    {
      return USERMOD_ID_M5ATOMWIFIFIX;
    }

   //More methods can be added in the future, this example will then be extended.
   //Your usermod will remain compatible as it does not need to implement all methods from the Usermod base class!
};
