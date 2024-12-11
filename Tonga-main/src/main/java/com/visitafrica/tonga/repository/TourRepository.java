package com.visitafrica.tonga.repository;

import com.visitafrica.tonga.model.Tour;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Service;

@Service
public interface TourRepository extends JpaRepository<Tour,Long> {
    @Override
    void delete(Tour tour);
}
