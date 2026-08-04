package com.example.temphibernate;

import com.example.temphibernate.mqtt.MqttPublisher;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class TempHibernateApplication {

    public static void main(String[] args) throws Exception {
        SpringApplication.run(TempHibernateApplication.class, args);
        boolean test = true;
        MqttPublisher publisher = new MqttPublisher();
        if (test){
            publisher.publish("temp/room/office/cmd","test");
            test = false;
        }

    }




}
