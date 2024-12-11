package com.visitafrica.tonga.service;

import com.visitafrica.tonga.model.Review;
import com.visitafrica.tonga.repository.ReviewRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
@Service
public class ReviewService {
    @Autowired
    private ReviewRepository reviewRepository;
    public List<Review> getAllReviews()
    {
        return reviewRepository.findAll();
    }

}

