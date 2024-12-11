package com.visitafrica.tonga.model;

import javax.persistence.*;

@Entity
@Table(name = "country_tb")
public class Country {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    @Column(name = "country_name")

    private String name ;

    @Column (name = "country_tours")
    private Integer tours;

    @Column(name = "country_operators")
    private Integer operators;

    private String image;

    public Long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getTours() {
        return tours;
    }

    public void setTours(Integer tours) {
        this.tours = tours;
    }

    public Integer getOperators() {
        return operators;
    }

    public void setOperators(Integer operators) {
        this.operators = operators;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
