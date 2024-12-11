package com.example.cse4636_assignment4.model;

import javax.persistence.*;

@Entity
@Table(name = "Student")
@NamedQuery(name = "find student by id" ,query = "Select s from Student s where s.id = :id")

public class Student {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "studentId")
    private long studentId;

    @Column(name = "name", nullable = false)
    private String name;

    @Column(name = "semester", nullable = false)
    private int semester;

    @Column(name = "cgpa", nullable = false)
    private double cgpa;

    // Constructors, getters, and setters

    // Default constructor
    public Student() {}

    // Parameterized constructor
    public Student(long studentId,String name, int semester, double cgpa) {
        this.studentId = studentId;
        this.name = name;
        this.semester = semester;
        this.cgpa = cgpa;
    }
    public Student(String name, int semester, double cgpa) {
        this.name = name;
        this.semester = semester;
        this.cgpa = cgpa;
    }

    public long getStudentId() {
        return studentId;
    }

    public void setStudentId(Long studentId) {
        this.studentId = studentId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getSemester() {
        return semester;
    }

    public void setSemester(int semester) {
        this.semester = semester;
    }

    public double getCgpa() {
        return cgpa;
    }

    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }
    // Getters and setters for attributes
    // ...

    @Override
    public String toString() {
        return "Student{" +
                "studentId=" + studentId +
                ", name='" + name + '\'' +
                ", semester=" + semester +
                ", cgpa=" + cgpa +
                '}';
    }
}

