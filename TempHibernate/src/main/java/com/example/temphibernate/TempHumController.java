package com.example.temphibernate;

import com.example.temphibernate.tempservice.TempratureServiceController;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class TempHumController {
    private final TempHumRepo repo;
    TempratureServiceController tempController = new TempratureServiceController();
    TempHumController(TempHumRepo repo){ this.repo = repo;}


    @RequestMapping("Temp")
    public List<TempHum> getAllTemp(){
        return repo.findAll();
    }

    @PostMapping("Temp/PostTemp")
    public String addNewTH(@RequestBody TempHum tH) throws Exception {
        repo.save(tH);
        tempController.temperatureController(tH);
        return "HTTP : 200";
    }

    @RequestMapping("Temp/id/{id}")
    public TempHum getById(@PathVariable long id){
        return repo.findById(id).get();
    }

    @RequestMapping("Temp/room/{room}")
    public List<TempHum> getRoom(@PathVariable String room){
        return repo.findByRoom(room);
    }

    @RequestMapping("Temp/room/{room}/Latest")
    public TempHum getLatest(@PathVariable String room){
        return repo.findByRoom(room).getLast();
    }

    @RequestMapping ("Temp/room/{room}/avg")
    public AvgData getAvgDataByRoom(@PathVariable String room){
        double avgTemp = 0;
        double avgHum = 0;
        int counter = 0;
        for(TempHum temp_t : repo.findByRoom(room)){
            avgTemp += temp_t.temp;
            avgHum += temp_t.hum;
            counter++;
        }
        avgTemp /= counter;
        avgHum /= counter;
        return new AvgData(avgTemp,avgHum,room,counter);
    }
}
