package com.visitafrica.tonga.service;



import com.visitafrica.tonga.model.Country;
import com.visitafrica.tonga.repository.CountryRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class CountryService {

    @Autowired
    private CountryRepository countryRepository;

    public void addCountry(Country country) {
        countryRepository.save(country); // Save the country object to the database
    }
    public List<Country> findCountries()
    {
        return countryRepository.findAll();
    }
    public void updateCountry(Country country) {
        // Find the existing country by name from the database
        Optional<Country> existingCountryOptional = countryRepository.findById(country.getId());

        if (existingCountryOptional.isPresent()) {
            // Update the country information
            Country existingCountry = existingCountryOptional.get();
            existingCountry.setTours(country.getTours());
            existingCountry.setOperators(country.getOperators());
            existingCountry.setName(country.getName());
            existingCountry.setImage(country.getImage());

            // Save the updated country in the database
            countryRepository.save(existingCountry);
        } else {
            // Handle the case when the country is not found in the database
            throw new IllegalArgumentException("Country not found: " + country.getName());
        }
    }

    public void deleteCountryById(long id) {
        countryRepository.deleteById(id);
    }
    public Country getCountryById(Long countryId){
        Optional<Country> countryOptional = countryRepository.findById(countryId);
        if (countryOptional.isPresent()) {
            return countryOptional.get();
        } else {
            // Handle case where country with given ID is not found
            throw new RuntimeException("Country not found with ID: " + countryId);
        }
    }
}
