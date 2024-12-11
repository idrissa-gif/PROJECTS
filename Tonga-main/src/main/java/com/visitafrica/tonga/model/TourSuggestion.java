package com.visitafrica.tonga.model;

import javax.persistence.*;
import java.util.Date;

@Entity
@Table(name = "toursuggestion_tb" , uniqueConstraints = @UniqueConstraint(columnNames = "id"))

public class TourSuggestion {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Integer id;
    @Column(name = "tour_title")
    private String title;
    @Column(name = "prices")
    private String prices;

    @Column(name = "operator_name")
    private String operator_name;
    @Column(name = "country")
    private String country;

    @Column(name = "rate")
    private Integer rate;
    @Column(name = "Availability")
    private String Availability;
    @Column(name = "Image")
    private String Image;
    @Column(name = "Image1")
    private String Image1;
    @Column(name = "Image2")
    private String Image2;
    @Column(name = "Image3")
    private String Image3;
    @Column(name = "description")
    private String description;
    @Column(name = "CreationDate")
    private Date CreationDate;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getPrices() {
        return prices;
    }

    public void setPrices(String prices) {
        this.prices = prices;
    }

    public String getOperator_name() {
        return operator_name;
    }

    public void setOperator_name(String operator_name) {
        this.operator_name = operator_name;
    }

    public String getCountry() {
        return country;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public Integer getRate() {
        return rate;
    }

    public void setRate(Integer rate) {
        this.rate = rate;
    }

    public String getAvailability() {
        return Availability;
    }

    public void setAvailability(String availability) {
        Availability = availability;
    }

    public String getImage() {
        return Image;
    }

    public void setImage(String image) {
        Image = image;
    }

    public String getImage1() {
        return Image1;
    }

    public void setImage1(String image1) {
        Image1 = image1;
    }

    public String getImage2() {
        return Image2;
    }

    public void setImage2(String image2) {
        Image2 = image2;
    }

    public String getImage3() {
        return Image3;
    }

    public void setImage3(String image3) {
        Image3 = image3;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Date getCreationDate() {
        return CreationDate;
    }

    public void setCreationDate(Date creationDate) {
        CreationDate = creationDate;
    }
}
