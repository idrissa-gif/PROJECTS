package com.visitafrica.tonga.model;

import javax.persistence.*;

@Entity
@Table(name = "operator_tb" , uniqueConstraints = @UniqueConstraint(columnNames = "operator_name"))

public class Operator {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    @Column(name = "operator_name")
    private String name;

    @Column(name = "number_tours")
    private  String tours ;

    @Column(name = "countries")
    private String countries;
    @Column(name = "rate")
    private Integer rate;

    private String image;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTours() {
        return tours;
    }

    public void setTours(String tours) {
        this.tours = tours;
    }

    public String getCountries() {
        return countries;
    }

    public void setCountries(String countries) {
        this.countries = countries;
    }

    public Integer getRate() {
        return rate;
    }

    public void setRate(Integer rate) {
        this.rate = rate;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
