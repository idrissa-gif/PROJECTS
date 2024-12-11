package com.example.onlinefood;

import javafx.scene.control.Alert;

import java.io.ByteArrayInputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class SimpleOrderStrategy implements OrderStrategy {
    public DatabaseConnector database = new DatabaseConnector();
    @Override
    public void processOrder(Dish order, Integer number) {
        try {
            Connection conn = database.getConnection();
            String query = "INSERT INTO pizza_db.dishOrdered_tb (name,number,price ) VALUES (?, ? , ?)";

            // Assuming you want to insert information based on user input
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, order.getName());
                stmt.setInt(2, number);
                stmt.setInt(3, order.getPrice()*number);
                int rowsAffected = stmt.executeUpdate();

                // Show success message
                showSuccessAlert("The order was successfully");

            }
        } catch (SQLException e) {
            e.printStackTrace();
            // Handle any SQL exceptions as needed
        }
    }
    public void showSuccessAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}