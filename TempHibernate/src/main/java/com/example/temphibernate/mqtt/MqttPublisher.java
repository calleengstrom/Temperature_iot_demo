package com.example.temphibernate.mqtt;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttMessage;


public class MqttPublisher {

    private final MqttClient client;

    public MqttPublisher() throws Exception {

        String broker ="tcp://localhost:1883";
        String clientId = MqttClient.generateClientId();

        client = new MqttClient(broker, clientId);
        MqttConnectOptions options = new MqttConnectOptions();
        options.setAutomaticReconnect(true);
        options.setCleanSession(true);

        client.connect();


    }

    public void publish(String topic, String msg) throws Exception {

        MqttMessage mqttMessage = new MqttMessage(msg.getBytes());
        mqttMessage.setQos(1);

        client.publish(topic,mqttMessage);
    }

}
