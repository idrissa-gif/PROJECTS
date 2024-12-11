package com.visitafrica.tonga.model;

import javax.persistence.*;

@Entity
@Table(name = "book_tb",uniqueConstraints =@UniqueConstraint(columnNames = "id"))


public class Book {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Integer id;
    @Column(name = "destination")
    private String destination;
    @Column(name = "start_date")
    private String start_date;
    @Column(name = "FullName")
    private String FullName;
    @Column(name = "email")
    private String email;
    @Column(name = "phone")
    private String phone;
    @Column(name = "adults")
    private Integer adults;
    @Column(name = "children")
    private Integer children;
}
