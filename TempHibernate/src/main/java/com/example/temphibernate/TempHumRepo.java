package com.example.temphibernate;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface TempHumRepo extends JpaRepository<TempHum ,Long> {

    public List<TempHum> findByRoom(String Room);


}
