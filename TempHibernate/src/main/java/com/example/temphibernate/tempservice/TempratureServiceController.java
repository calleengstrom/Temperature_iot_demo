package com.example.temphibernate.tempservice;

import com.example.temphibernate.TempHum;
import com.example.temphibernate.mqtt.MqttPublisher;
import org.springframework.stereotype.Component;

@Component
public class TempratureServiceController {

    private final MqttPublisher publisher;

    public TempratureServiceController(MqttPublisher publisher) {
        this.publisher = publisher;
    }

    public void temperatureController (TempHum tH) throws Exception {

        if ( tH.getTemp() <= 24 &&  tH.getTemp() > 21){
            publisher.publish("climate/office","NORMAL");
            IO.println("Normal temp");
            return;
        }
        if (tH.getTemp() >= 25){
            publisher.publish("climate/office","COOLING");
            IO.println("High temp");
        }
        else {
            publisher.publish("climate/office", "HEATING");
            IO.println("Low temp");
        }
    }
}
