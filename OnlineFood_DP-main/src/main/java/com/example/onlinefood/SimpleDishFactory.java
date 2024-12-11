package com.example.onlinefood;

import javafx.scene.image.Image;
import javafx.scene.image.PixelReader;
import javafx.scene.image.WritableImage;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import javafx.embed.swing.SwingFXUtils;


import javax.imageio.ImageIO;

public class SimpleDishFactory implements DishFactory {
    public DatabaseConnector database = new DatabaseConnector();
    public SimpleOrderStrategy notification = new SimpleOrderStrategy();

    public Dish createDish(String name, Integer price, String ingredients, String description, Image image) {
        try {
            byte[] imageData = getImageBytes(image);
            Connection conn = database.getConnection();
            String query = "INSERT INTO pizza_db.dish_tb (name, description, price,ingredients,image) VALUES (?, ? , ?, ?, ?)";

            // Assuming you want to insert information based on user input
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, name);
                stmt.setString(2, description);
                stmt.setInt(3, price);
                stmt.setString(4, ingredients);
                stmt.setBlob(5, new ByteArrayInputStream(imageData));
                int rowsAffected = stmt.executeUpdate();

                // Example: Print the number of rows affected
                System.out.println(rowsAffected + " row(s) affected");

                // Show success message
                notification.showSuccessAlert("The dish has been successfully created!");

            }
        } catch (SQLException e) {
            e.printStackTrace();
            // Handle any SQL exceptions as needed
        }

        return new Dish(name, description, ingredients, price,image);

    }

    public void deleteDish(Dish dish) {
        try {
            Connection conn = database.getConnection();
            String query = "DELETE FROM pizza_db.dish_tb WHERE name = ?";

            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, dish.getName());
                int rowsAffected = stmt.executeUpdate();

                // Example: Print the number of rows affected
                System.out.println(rowsAffected + " row(s) deleted");

                // Show success message
                notification.showSuccessAlert("The dish has been successfully deleted!");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            // Handle any SQL exceptions as needed
        }
    }

    @Override
    public void editDish(Dish dish) {
        try {
            Connection conn = database.getConnection();
            String query = "UPDATE pizza_db.dish_tb SET name = ?, description = ?, price = ?, ingredients = ?, image = ? WHERE name = ?";

            // Assuming you want to update information based on user input
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, dish.getName());
                stmt.setString(2, dish.getDescription());
                stmt.setInt(3, dish.getPrice());
                stmt.setString(4, dish.getIngredients());

                // Convert JavaFX Image to byte array (assuming it's a PNG format)
                byte[] imageData = getImageBytes(dish.getImage());
                stmt.setBlob(5, new ByteArrayInputStream(imageData));

                // Use the original dish name for the WHERE clause
                stmt.setString(6, dish.getName());

                int rowsAffected = stmt.executeUpdate();

                // Example: Print the number of rows affected
                System.out.println(rowsAffected + " row(s) updated");

                // Show success message
                notification.showSuccessAlert("The dish has been successfully updated!");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            // Handle any SQL exceptions as needed
        }
    }

    private byte[] getImageBytes(Image image) {
        // Convert JavaFX Image to byte array (assuming it's a PNG format)
        WritableImage writableImage = new WritableImage((int) image.getWidth(), (int) image.getHeight());
        PixelReader pixelReader = image.getPixelReader();
        writableImage = new WritableImage(pixelReader, (int) image.getWidth(), (int) image.getHeight());

        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();

        try {
            ImageIO.write(SwingFXUtils.fromFXImage(writableImage, null), "png", outputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }

        return outputStream.toByteArray();
    }


}
