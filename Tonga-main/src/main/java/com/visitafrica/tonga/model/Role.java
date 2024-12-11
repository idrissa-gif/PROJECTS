package com.visitafrica.tonga.model;

import javax.persistence.*;

import java.util.Set;

@Entity
@Table(name = "role_tb")
public class Role {
    private Long role_id;
    private String name;
    private Set < User > users;



    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    public Long getRole_id() {
        return role_id;
    }

    public void setRole_id(Long role_id) {
        this.role_id = role_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @ManyToMany(mappedBy = "roles")
    public Set < User > getUsers() {
        return users;
    }

    public void setUsers(Set < User > users) {
        this.users = users;
    }
}
