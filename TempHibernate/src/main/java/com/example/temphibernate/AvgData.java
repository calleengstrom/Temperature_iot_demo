package com.example.temphibernate;

import jakarta.persistence.Entity;
import lombok.AccessLevel;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data

public class AvgData

{
    protected double temp;
    protected double hum;
    protected String room;
    protected int dataSamples;

    public AvgData(double temp, double hum, String room, int dataSamples) {
        this.temp = temp;
        this.hum = hum;
        this.room = room;
        this.dataSamples = dataSamples;
    }
}
