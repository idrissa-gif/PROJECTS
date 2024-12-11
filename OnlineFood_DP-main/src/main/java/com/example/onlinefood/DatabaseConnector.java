package com.example.onlinefood;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnector {
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/pizza_db";  // Use "localhost" or "127.0.0.1" if MySQL is on the same machine
    private static final String USER = "root";
    private static final String PASSWORD = "admin123";

    public Connection getConnection() throws SQLException {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            return DriverManager.getConnection(JDBC_URL, USER, PASSWORD);
        } catch (ClassNotFoundException e) {
            throw new SQLException("MySQL JDBC Driver not found", e);
        }
    }
}
