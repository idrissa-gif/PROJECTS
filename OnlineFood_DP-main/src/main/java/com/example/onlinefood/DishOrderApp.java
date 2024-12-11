package com.example.onlinefood;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class DishOrderApp extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(DishOrderApp.class.getResource("choice.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        stage.setTitle("Order A Dish!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}