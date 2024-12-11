package com.example.onlinefood;

import javafx.scene.control.Alert;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class CustomizedDishDecorator implements DishDecorator {
    public DatabaseConnector database = new DatabaseConnector();
    @Override
    public void customize(Dish order,Integer number, String extras) {
        try {
            Connection conn = database.getConnection();
            String query = "INSERT INTO pizza_db.dishOrdered_tb (name,number,price,toppings ) VALUES (?, ? , ?,?)";

            // Assuming you want to insert information based on user input
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, order.getName());
                stmt.setInt(2, number);
                stmt.setInt(3, order.getPrice()*number);
                stmt.setString(4,extras);
                int rowsAffected = stmt.executeUpdate();

                // Show success message
                showSuccessAlert();
            }
        } catch (SQLException e) {
            e.printStackTrace();
            // Handle any SQL exceptions as needed
        }
    }
    public void showSuccessAlert() {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success");
        alert.setHeaderText(null);
        alert.setContentText("Your Customized Dish has been ordered successfully!");
        alert.showAndWait();
    }
}