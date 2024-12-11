package com.visitafrica.tonga.model;

import org.springframework.beans.factory.annotation.Autowired;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "tour_tb" , uniqueConstraints = @UniqueConstraint(columnNames = "tour_id"))
public class Tour {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "tour_id")
    private Integer id;
    private String tour_name ;
    private String tour_operator;
    private String countries;
    private String prices;
    private String number_person;
    private Integer rate ;
    private String image1;
    private String image2;
    private String image3;


    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getTour_name() {
        return tour_name;
    }

    public void setTour_name(String tour_name) {
        this.tour_name = tour_name;
    }

    public String getTour_operator() {
        return tour_operator;
    }

    public void setTour_operator(String tour_operator) {
        this.tour_operator = tour_operator;
    }

    public String getCountries() {
        return countries;
    }

    public void setCountries(String countries) {
        this.countries = countries;
    }

    public String getPrices() {
        return prices;
    }

    public void setPrices(String prices) {
        this.prices = prices;
    }

    public String getNumber_person() {
        return number_person;
    }

    public void setNumber_person(String number_person) {
        this.number_person = number_person;
    }

    public Integer getRate() {
        return rate;
    }

    public void setRate(Integer rate) {
        this.rate = rate;
    }

    public String getImage1() {
        return image1;
    }

    public void setImage1(String image1) {
        this.image1 = image1;
    }

    public String getImage2() {
        return image2;
    }

    public void setImage2(String image2) {
        this.image2 = image2;
    }

    public String getImage3() {
        return image3;
    }

    public void setImage3(String image3) {
        this.image3 = image3;
    }

}
