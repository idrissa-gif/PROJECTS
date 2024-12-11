package com.visitafrica.tonga.repository;

import com.visitafrica.tonga.model.Country;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface CountryRepository extends JpaRepository<Country, Long> {
    // Define any additional custom database operations here

}
