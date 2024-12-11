package com.visitafrica.tonga.repository;

import com.visitafrica.tonga.model.Operator;
import org.springframework.data.jpa.repository.JpaRepository;

public interface OperatorRepository extends JpaRepository<Operator, String> {
    // You can add custom methods here for querying the Operator entity
}
