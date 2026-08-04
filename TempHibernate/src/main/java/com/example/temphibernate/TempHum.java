package com.example.temphibernate;


import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import lombok.AccessLevel;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.annotations.CreationTimestamp;

import java.time.LocalDateTime;

@Data
@AllArgsConstructor(access = AccessLevel.PROTECTED)
@NoArgsConstructor(access = AccessLevel.PROTECTED)
@Entity

public class TempHum {
    @Id
    @GeneratedValue
    protected Long id;
    protected double temp;
    protected double hum;
    protected String room;
    @CreationTimestamp
    protected LocalDateTime time;

}
