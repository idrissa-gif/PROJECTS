package com.visitafrica.tonga.model;

import javax.persistence.*;

@Entity
@Table(name = "review_tb",uniqueConstraints =@UniqueConstraint(columnNames = "id"))
public class Review {
    @Id
    @GeneratedValue (strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Integer id;
    @Column(name = "reviewer_name")
    private String reviewer_name;
    @Column(name = "message")
    private String message;
    @Column(name = "target")
    private String target;
    @Column(name="rate")
    private Integer rate ;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getReviewer_name() {
        return reviewer_name;
    }

    public void setReviewer_name(String reviewer_name) {
        this.reviewer_name = reviewer_name;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getTarget() {
        return target;
    }

    public void setTarget(String target) {
        this.target = target;
    }

    public Integer getRate() {
        return rate;
    }

    public void setRate(Integer rate) {
        this.rate = rate;
    }
}
