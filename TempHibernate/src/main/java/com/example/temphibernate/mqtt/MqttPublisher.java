package com.example.temphibernate.mqtt;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.springframework.stereotype.Component;

@Component
public class MqttPublisher {

    private final MqttClient client;

    public MqttPublisher() throws Exception {

        String broker = String.format("tcp://%s:1883", Configs.BROKER_IP);
        String clientId = MqttClient.generateClientId();

        client = new MqttClient(broker, clientId);
        MqttConnectOptions options= new MqttConnectOptions();
        options.setUserName(Configs.BROKER_USERNAME);
        options.setPassword(Configs.BROKER_PASSWORD.toCharArray());
        options.setAutomaticReconnect(true);
        options.setCleanSession(true);
        client.connect(options);


    }

    public void publish(String topic, String msg) throws Exception {

        MqttMessage mqttMessage = new MqttMessage(msg.getBytes());
        mqttMessage.setQos(1);

        client.publish(topic,mqttMessage);
    }


}
