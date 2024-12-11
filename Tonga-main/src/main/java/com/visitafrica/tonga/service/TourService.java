package com.visitafrica.tonga.service;

import com.visitafrica.tonga.model.Tour;
import com.visitafrica.tonga.repository.TourRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class TourService {
    @Autowired
    private TourRepository tourRepository;
    public void saveTour(Tour tour)
    {
        tourRepository.save(tour);
    }
    public List<Tour> findTour()
    {
        return tourRepository.findAll();
    }
    public void Delete(Tour tour){tourRepository.delete(tour);}
}

