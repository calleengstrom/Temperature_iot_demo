package com.example.temphibernate.tempservice;

import com.example.temphibernate.TempHum;
import com.example.temphibernate.mqtt.MqttPublisher;

public class TempratureServiceController {

    public void temperatureController (TempHum tH) throws Exception {
        MqttPublisher publisher = new MqttPublisher();
        if ( tH.getTemp() < 24 &&  tH.getTemp() > 21){
            publisher.publish("temp/room/office/cmd","NORMAL");
            IO.println("Normal temp");
            return;
        }
        if (tH.getTemp() > 23){
            publisher.publish("temp/room/office/cmd","COOLING");
            IO.println("High temp");
        }
        else {
            publisher.publish("temp/room/office/cmd", "HEATING");
            IO.println("Low temp");
        }
    }
}
